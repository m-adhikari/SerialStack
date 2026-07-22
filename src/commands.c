#include "commands.h"

int command_is_valid(uint8_t command)
{
    switch (command)
    {
        case SS_CMD_PING:
        case SS_CMD_PONG:
        case SS_CMD_ACK:
        case SS_CMD_NACK:
        case SS_CMD_HEARTBEAT:
        case SS_CMD_STATUS_REQUEST:
        case SS_CMD_STATUS_RESPONSE:
        case SS_CMD_EXTENDED:
            return 1;

        case SS_CMD_RESERVED:
        default:
            return 0;
    }
}

const char *command_name(uint8_t command)
{
    switch(command)
    {
        case SS_CMD_RESERVED:
            return "RESERVED";

        case SS_CMD_PING:
            return "PING";

        case SS_CMD_PONG:
            return "PONG";

        case SS_CMD_ACK:
            return "ACK";

        case SS_CMD_NACK:
            return "NACK";

        case SS_CMD_HEARTBEAT:
            return "HEARTBEAT";

        case SS_CMD_STATUS_REQUEST:
            return "STATUS_REQUEST";

        case SS_CMD_STATUS_RESPONSE:
            return "STATUS_RESPONSE";

        case SS_CMD_EXTENDED:
            return "EXTENDED";

        default:
            return "UNKNOWN"; 
    }
}

