#include "protocol.h"

#include "address.h"
#include "codec.h"
#include "commands.h"
#include "crc8.h"
#include "packet.h"
#include "sequence.h"
#include "uart.h"


ss_error_t protocol_init(void)
{
    sequence_init();

    return SS_OK;
}


ss_error_t protocol_send(int fd,
                         const ss_packet_t *packet)
{
    uint8_t frame[SS_FRAME_SIZE];
    ss_error_t status;
    size_t frame_length;
    ssize_t bytes_written;

    if (packet == NULL)
    {
        return SS_ERROR_NULL_POINTER;
    }

    status = protocol_validate(packet);

    if (status != SS_OK)
    {
        return status;
    }


    status = codec_encode(packet,
                          frame,
                          sizeof(frame));

    if (status != SS_OK)
    {
        return status;
    }


    frame_length = packet->length + 9;


    bytes_written = uart_write(fd,
                               frame,
                               frame_length);


    if (bytes_written < 0)
    {
        return SS_ERROR_UART_WRITE;
    }


    if ((size_t)bytes_written != frame_length)
    {
        return SS_ERROR_UART_WRITE;
    }


    return SS_OK;
}


ss_error_t protocol_receive(int fd,
                            ss_packet_t *packet)
{
    uint8_t frame[SS_FRAME_SIZE];
    ssize_t bytes_read;
    ss_error_t status;


    if (packet == NULL)
    {
        return SS_ERROR_NULL_POINTER;
    }


    bytes_read = uart_read(fd,
                           frame,
                           sizeof(frame));


    if (bytes_read < 0)
    {
        return SS_ERROR_UART_READ;
    }


    status = codec_decode(frame,
                          (size_t)bytes_read,
                          packet);


    if (status != SS_OK)
    {
        return status;
    }


    status = protocol_validate(packet);

    if (status != SS_OK)
    {
        return status;
    }


    if (sequence_is_duplicate(packet->sequence))
    {
        return SS_ERROR_INVALID_SEQUENCE;
    }


    sequence_record(packet->sequence);


    return SS_OK;
}


ss_error_t protocol_validate(const ss_packet_t *packet)
{
    if (packet == NULL)
    {
        return SS_ERROR_NULL_POINTER;
    }


    if (packet->version != 1)
    {
        return SS_ERROR_INVALID_VERSION;
    }


    if (packet->length > SS_MAX_PAYLOAD_SIZE)
    {
        return SS_ERROR_INVALID_LENGTH;
    }


    if (!command_is_valid(packet->command))
    {
        return SS_ERROR_INVALID_COMMAND;
    }


    if (!address_is_valid(packet->destination))
    {
        return SS_ERROR_INVALID_ADDRESS;
    }


    return SS_OK;
}
