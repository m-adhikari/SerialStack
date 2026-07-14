#define _DEFAULT_SOURCE

#include "uart.h"

#include <fcntl.h>
#include <unistd.h>
#include <termios.h>
#include <errno.h>
#include <stdio.h>

/**
 * Convert integer baud rate to termios constant
 */

static speed_t get_baudrate(int baudrate)
{
    switch (baudrate)
    {
        case 9600:
            return B9600;
        
        case 19200:
            return B19200;
        
        case 38400:
            return B38400;
        
        case 57600:
            return B57600;
        
        case 115200:
            return B115200;
        
        default:
            return 0;
    }
}

int uart_open(const char *device, int baudrate)
{
    int fd;
    struct termios tty;

    speed_t speed = get_baudrate(baudrate);

    if (speed == 0)
    {
        fprintf(stderr, "Unsupported baud rate: %d\n", baudrate);
        return -1;
    }

    /*
     * Open UART device
     * O_RDWR -> read and write
     * O_NOCTTY -> don't become controlling terminal
     */

    fd = open(device, O_RDWR | O_NOCTTY);
    if (fd < 0)
    {
       perror("UART open failed");
       return -1;
    }

    /*
     * Get current UART settings.
     */
    if (tcgetattr(fd, &tty) != 0)
    {
        perror("tcgetattr failed");
        close(fd);
        return -1;
    }

    /*
     * Raw mode:
     * disable: input processing, output processing, echo, special character handling
     */
     cfmakeraw(&tty);

    /*
     * Configure baud rate.
     */
    cfsetispeed(&tty, speed);
    cfsetospeed(&tty, speed);

    /*
     * 8N1 cofiguration
     */
    tty.c_cflag &= ~PARENB;
    tty.c_cflag &= ~CSTOPB;
    tty.c_cflag &= ~CSIZE;
    tty.c_cflag |= CS8;

    /*
     * Enable receiver
    */
    tty.c_cflag |= CREAD | CLOCAL;

    /*
     * Blocking read configuration.
     * 
     * VMIN = minimum bytes required
     * VTIME = timeout
     */
    tty.c_cc[VMIN] = 1;
    tty.c_cc[VTIME] = 0;

    /*
     * Apply settings.
     */
    if (tcsetattr(fd, TCSANOW, &tty) != 0)
    {
        perror("tcsetattr failed");
        close(fd);
        return -1;
    }

    /*
     * Clear pending data
     */
    tcflush (fd, TCIOFLUSH);

    return fd;
}

void uart_close(int fd)
{
    close(fd);
}

ssize_t uart_read(int fd, void *buffer, size_t length)
{
    return read(fd, buffer, length);
}



ssize_t uart_write(int fd, const void *buffer, size_t length)
{
    return write(fd, buffer, length);
}
