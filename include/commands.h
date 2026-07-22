#ifndef COMMANDS_H
#define COMMANDS_H

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief SerialStack commands
 */
typedef enum
{
    SS_CMD_RESERVED          = 0x00,

    SS_CMD_PING              = 0x01,
    SS_CMD_PONG              = 0x02,
    SS_CMD_ACK               = 0x03,
    SS_CMD_NACK              = 0x04,
    SS_CMD_HEARTBEAT         = 0x05,
    SS_CMD_STATUS_REQUEST    = 0x06,
    SS_CMD_STATUS_RESPONSE   = 0x07,

    SS_CMD_EXTENDED          = 0xFF

} ss_command_t;

/**
 * @brief Determines whether a command identifier is valid.
 * 
 * @param command Command identifier
 *
 * @return 1 if valid
 * @return 0 otherwise 
 */
int command_is_valid(uint8_t command);

/**
 * @brief Returns the textual name of a command.
 * 
 * @param command Command identifier
 *
 * @return constant string representing the command.
 */
const char *commnad_name (uint8_t command);

#ifdef __cplusplus
}
#endif

#endif /* COMMANDS_H */
