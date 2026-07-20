#ifndef ERRORS_H
#define ERRORS_H

#ifdef __cplusplus
extern "C" {
    #endif
/**
 * @brief SerialStack status and error codes. 
 */

typedef enum
{
    SS_OK = 0,

    /*UART Errors*/

    SS_ERROR_UART_OPEN,
    SS_ERROR_UART_READ,
    SS_ERROR_UART_WRITE,

    /*Packet Errors*/
    SS_ERROR_INVALID_LENGTH,
    SS_ERROR_INVALID_VERSION,
    SS_ERROR_INVALID_COMMAND,
    SS_ERROR_INVALID_ADDRESS,
    SS_ERROR_INVALID_SEQUENCE,

    /*Framing Error*/
    SS_ERROR_INVALID_SOF,
    SS_ERROR_INVALID_EOF,

    /*Integrity Errors*/
    SS_ERROR_CRC,

    /*General Errors*/
    SS_ERROR_TIMEOUT,
    SS_ERROR_BUFFER_OVERFLOW,
    SS_ERROR_NULL_POINTER,
    SS_ERROR_UNKNOWN
} ss_error_t;

/**
 * @brief returns human-readable description of SerialStack error.
 *  
 * @param error SerialStack error code
 * 
 * @return constant string describing the error
 */
const char *ss_error_string(ss_error_t error);

#ifdef __cplusplus
}
#endif

#endif /* ERRORS_H*/

