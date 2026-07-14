#include "uart.h"

#include <stdio.h>
#include <string.h>

#define UART_DEVICE "/dev/serial0"
#define UART_BAUDRATE 115200

int main(void)
{
    const char message[] = "Hello SerialStack\n";

    /*
     * Open UART device
     */
    int fd = uart_open(UART_DEVICE, UART_BAUDRATE);

    if (fd < 0)
    {
        fprintf(stderr, "Failed to open UART \n");
        return 1;
    }

    /*
     * Sending raw bytes
     */
    ssize_t bytes_sent = uart_write(
        fd,
        message, 
        strlen(message)
    );

    if (bytes_sent < 0)
    {
        fprintf(stderr, "UART transmission failed");
        uart_close(fd);
        return 1;
    }

    printf("Sent %zd bytes \n", bytes_sent);
    
    /*
     * close UART
     */
    uart_close(fd);

    return 0;
    
}
