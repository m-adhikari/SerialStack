#ifndef CODEC_H
#define CODEC_H

#include <stddef.h>
#include <stdint.h>

#include "errors.h"
#include "packet.h"

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief SerialStack frame const.  
 */

#define SS_FRAME_SOF            0xAA
#define SS_FRAME_EOF            0x55

#define SS_MAX_PAYLOAD_SIZE     64
#define SS_FRAME_SIZE           73

/**
 * @brief encodes a SerialStack packet into a transmission frame
 * 
 * The genrated frame constants
 * SOF, LEN, VER, DST, SRC, CMD, SEQ, PayLoad, CRC8, EOF
 * 
 * @param packet Packet to encode
 * @param  frame Destination frame buffer
 * @param length size of destination buffer
 *
 * @return SS_OK on success
 * @return Error code on failure
 */
ss_error_t codec_encode(const ss_packet_t *packet,
                        uint8_t *frame,
                        size_t length);

/**
 * @brief Decodes a SerialStack frame into a packet.
 * 
 * Structural decoding only. Protocol validation is performed by validator module.
 * 
 * @param frame Received frame
 * @param length Frame length
 * @param packet destination packet
 * 
 * @return SS_OK on success
 * @return Error code on failure
 */
ss_error_t codec_decode(const uint8_t *frame,
                        size_t length,
                        ss_packet_t *packet);

#ifdef __cplusplus
}
#endif

#endif /* CODEC_H */

