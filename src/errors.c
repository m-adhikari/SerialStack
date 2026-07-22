#include "errors.h"

const char *ss_error_string(ss_error_t error)
{
    switch (error)
    {
        case SS_OK:
            return "Success";

        /* UART Errors */
        case SS_ERROR_UART_OPEN:
            return "Failed to open UART";

        case SS_ERROR_UART_READ:
            return "UART read failed";

        case SS_ERROR_UART_WRITE:
            return "UART write failed";

        /* Packet Errors */
        case SS_ERROR_INVALID_LENGTH:
            return "Invalid packet length";

        case SS_ERROR_INVALID_VERSION:
            return "Invalid protocol version";

        case SS_ERROR_INVALID_COMMAND:
            return "Invalid command";

        case SS_ERROR_INVALID_ADDRESS:
            return "Invalid address";

        case SS_ERROR_INVALID_SEQUENCE:
            return "Invalid sequence number";

        /* Framing Errors */
        case SS_ERROR_INVALID_SOF:
            return "Invalid Start-of-Frame (SOF)";

        case SS_ERROR_INVALID_EOF:
            return "Invalid End-of-Frame (EOF)";

        /* Integrity Errors */
        case SS_ERROR_CRC:
            return "CRC check failed";

        /* General Errors */
        case SS_ERROR_TIMEOUT:
            return "Operation timed out";

        case SS_ERROR_BUFFER_OVERFLOW:
            return "Buffer overflow";

        case SS_ERROR_NULL_POINTER:
            return "Null pointer";

        case SS_ERROR_UNKNOWN:
            return "Unknown error";

        default:
            return "Unrecognized SerialStack error";
    }
}
