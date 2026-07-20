#ifndef VALIDATOR_H
#define VALIDATOR_H

#include "errors.h"
#include "packet.h"

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief validates a SerialStack packet.
 * 
 * Performs protocol validation including:
 * - Protocol version
 * - Payload length
 * - command identifier
 * - destination address
 *
 * CRC and framing validation are performed
 *
 * @param packet Packet to validate.
 *
 * @return SS_OK if valid
 * @return Error code if otherwise.
 */
ss_error_t validator_validate(const ss_packet_t *packet);

/**
 * @brief Validates the protocol version.
 *
 * @param version Protocol version.
 *
 * @return SS_OK if supported.
 * @return Error code otherwise.
 */
ss_error_t validator_validate_version(uint8_t version);

/**
 * @brief Validates the payload length.
 *
 * @param length Payload length.
 *
 * @return SS_OK if valid.
 * @return Error code otherwise.
 */
ss_error_t validator_validate_length(uint8_t length);

/**
 * @brief Validates a command identifier.
 *
 * @param command Command identifier.
 *
 * @return SS_OK if valid.
 * @return Error code otherwise.
 */
ss_error_t validator_validate_command(uint8_t command);

/**
 * @brief Validates a destination address.
 *
 * @param address Destination address.
 *
 * @return SS_OK if valid.
 * @return Error code otherwise.
 */
ss_error_t validator_validate_address(uint8_t address);

#ifdef __cplusplus
}
#endif

#endif /* VALIDATOR_H */


