#ifndef ADDRESS_H
#define ADDRESS_H

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief Reserved SerialStack node addresses.
 */
#define SS_ADDRESS_BROADCAST 0xFF

/**
 * @brief Determines whether an address is valid.
 *
 * @param address Node address.
 *
 * @return 1 if valid.
 * @return 0 otherwise.
 */
int address_is_valid(uint8_t address);

/**
 * @brief Determines whether an address is the
 *        broadcast address.
 *
 * @param address Node address.
 *
 * @return 1 if broadcast.
 * @return 0 otherwise.
 */
int address_is_broadcast(uint8_t address);

/**
 * @brief Determines whether a packet is addressed
 *        to the local node.
 *
 * @param local_address Local node address.
 * @param destination Destination address.
 *
 * @return 1 if packet should be accepted.
 * @return 0 otherwise.
 */
int address_is_local(uint8_t local_address,
                     uint8_t destination);

#ifdef __cplusplus
}
#endif

#endif /* ADDRESS_H */
