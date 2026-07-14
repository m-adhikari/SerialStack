#include "uart.h"

#include <stdio.h>
#include <sys/types.h>

#define UART_DEVICE "/dev/serial0"
#define UART_BAUDRATE 115200
#define BUFFER_SIZE 256

int main(void)
{
    char buffer[BUFFER_SIZE];

    /*
     * Opening UART device
     */
    
    int fd = uart_open(UART_DEVICE, UART_BAUDRATE);

    if(fd < 0)
    {
        fprintf(stderr, "Failed to open UART\n");
        return 1;
    }

    printf("Listening on %s (%d baud) ... \n",
            UART_DEVICE,
            UART_BAUDRATE);
    
    /*
     * Continuously receives bytes
     */
    
    while(1)
    {
        ssize_t bytes_read = uart_read(
            fd,
            buffer,
            sizeof(buffer)
        );

        if (bytes_read < 0)
        {
            fprintf(stderr, "UART read failed\n");
            break;
        }

        if (bytes_read == 0)
        {
            continue;
        }

        /*
         * print exactly the bytes received
         */

        fwrite(buffer, 1, bytes_read, stdout);
        fflush(stdout);
    }

    /*
     * close UART
     */
    uart_close(fd);

    return 0;

}
