#include "packet.h"

#include <string.h>

void packet_init(ss_packet_t *packet)
{
    if(packet == NULL)
    {
        return;
    }

    memset(packet, 0, sizeof(ss_packet_t));
}

void packet_clear(ss_packet_t *packet)
{
    if(packet == NULL)
    {
        return;
    }

    memset(packet, 0, sizeof(ss_packet_t));
}

void packet_copy(ss_packet_t *destination,
                const ss_packet_t *source)
{
    if((destination == NULL) || (source == NULL))
    {
        return;
    }

    memcpy(destination, source, sizeof(ss_packet_t));
}

