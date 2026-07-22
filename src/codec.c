#include "codec.h"

#include "crc8.h"
#include <string.h>

ss_error_t codec_encode(const ss_packet_t *packet,
                        uint8_t *frame,
                        size_t length)
{
    if (packet == NULL || frame == NULL)
    {
        return SS_ERROR_NULL_POINTER;
    }

    if (packet->length > SS_MAX_PAYLOAD_SIZE)
    {
        return SS_ERROR_NULL_POINTER;
    }

    if (length < (size_t)(packet->length + 9))
    {
        return SS_ERROR_BUFFER_OVERFLOW;
    }

    frame[0] = SS_FRAME_SOF;
    frame[1] = packet->length;
    frame[2] = packet->version;
    frame[3] = packet->destination;
    frame[4] = packet->source;
    frame[5] = packet->command;
    frame[6] = packet->sequence;
    
    memcpy(&frame[7], packet->payload, packet->length);

    frame[7 + packet->length] =
        crc8_calculate(&frame[1], 6 + packet->length);
    
    frame[8 + packet->length] = SS_FRAME_EOF;

    return SS_OK;
}

ss_error_t codec_decode(const uint8_t *frame,
                        size_t length,
                        ss_packet_t *packet)
{
    if (frame == NULL || packet == NULL)
    {
        return SS_ERROR_NULL_POINTER;
    }

    if (length < 9)
    {
        return SS_ERROR_INVALID_LENGTH;
    }

    if (frame[0] != SS_FRAME_SOF)
    {
        return SS_ERROR_INVALID_SOF;
    }

    if (frame[length - 1] != SS_FRAME_EOF)
    {
        return SS_ERROR_INVALID_EOF;
    }

    packet->length = frame[1];

    if (packet->length > SS_MAX_PAYLOAD_SIZE)
    {
        return SS_ERROR_INVALID_LENGTH;
    }

    if (length != (size_t)(packet->length + 9))
    {
        return SS_ERROR_INVALID_LENGTH;
    }

    if (!crc8_verify(&frame[1],
                     6 + packet->length,
                     frame[7 + packet->length]))
    {
        return SS_ERROR_CRC;
    }

    packet->version     = frame[2];
    packet->destination = frame[3];
    packet->source      = frame[4];
    packet->command     = frame[5];
    packet->sequence    = frame[6];

    memcpy(packet->payload,
           &frame[7],
           packet->length);

    return SS_OK;
}
