#ifndef PROTOCOL_H
#define PROTOCOL_H

#include "errors.h"
#include "packet.h"

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief Initializes the SerialStack protocol layer
 * 
 * This function initilizes all protocol subsystsms
 * 
 * @return SS_OK on success
 * @return error code on failure
 */
ss_error_t protocol_init(void);

/**
 * @brief sends a SerialStack packet.
 * 
 * packet is encoded, framed, CRC protected and transmitted
 * 
 * @param fd UART file descriptor
 * @param packet packet to transmit
 *
 * @return SS_OK on success
 * @return error code on failure
 */
ss_error_t protocol_send(int fd,
                        const ss_packet_t *packet);

/**
 * @brief Receives a SerialStack packet.
 * 
 * Reads a frame from UART, decodes it and validates it,
 * and retuns the resulting packet
 *
 * @param fd UART file descriptor
 * @param packet Destination packet
 *
 * @return SS_OK on success
 * @return Error code on failure
 */
ss_error_t protocol_receive(int fd,
                            ss_packet_t *packet);

/**
 * @brief Validates a packet.
 *
 * Performs protocol-level checks including
 * command validation, version checks,
 * address verification and CRC validation.
 *
 * @param packet Packet to validate.
 *
 * @return SS_OK if packet is valid.
 * @return Error code otherwise.
 */
ss_error_t protocol_validate(const ss_packet_t *packet);

#ifdef __cplusplus
}
#endif

#endif /* PROTOCOL_H */

