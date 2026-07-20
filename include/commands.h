#ifndef CRC8_H
#define CRC8_H

#include <stddef.h>
#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief calculates the SerialStack CRC-8 checksum
 * 
 * CRC is calcualted excluding SOF CRC8 and EOF fields
 *
 * @param data pointer to input data.
 * @param length number of bytes.
 * 
 * @return calculated crc-8 value
 */
uint8_t crc8_calulate(const uint8_t *data, size_t length);

/**
 * @brief verifies a CRC-8 checksum
 * 
 * @param data pointer to input data
 * @param length number of bytes
 * @param expected expected CRC value
 *
 * @return 1 if CRC matches
 * @return 0 otherwise 
 */
int crc8_verify(const uint8_t *data,
                size_t length,
                uint8_t expected);

#ifdef __cplusplus
}
#endif

#endif /* CRC8_H */
