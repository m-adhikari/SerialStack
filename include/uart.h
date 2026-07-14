#ifndef UART_H
#define UART_H

#include <stddef.h>
#include <sys/types.h>

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief Opens and configures a UART device. 
 * 
 * Opens the given serial device and configures it as:
 * raw 8-N-1 communication at desired baud rate.
 *
 * @param device Path to the UART device
 * @param baudrate Desired baud rate
 *
 * @return File descriptor on success. 
 * @return -1 on failure
 */
int uart_open(const char *device, int baudrate);

/**
 * @brief closes an UART device
 *
 * @param fd UART file descriptor 
 */
void uart_close(int fd);

/**
 * @brief Reads bytes from the UART.
 *
 * This function blocks until data becomes available or an error occurs.
 * 
 * @param fd UART file descriptor.
 * @param buffer Destination buffer.
 * @param length maximum number of bytes for reading
 *
 * @return Number of bytes read.
 * @return -1 on error.
 */
ssize_t uart_read (int fd, void *buffer, size_t length);

/**
 * @brief writes bytes to the UART
 * 
 * @param fd UART file descriptr.
 * @param buffer source buffer.
 * @param length number of bytes to transmit
 *
 * @return Number of bytes written
 * @return -1 on error
 */
ssize_t uart_write(int fd, const void *buffer, size_t length);

#ifdef __cplusplus
}
#endif

#endif /*UART H*/



