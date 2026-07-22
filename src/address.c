#include "address.h"

int address_is_valid(uint8_t address)
{
    if (address == 0x00)
    {
        return 0;
    }
    
    return 1;
}

int address_is_broadcast(uint8_t address)
{
    return (address == SS_ADDRESS_BROADCAST);
}

int address_is_local(uint8_t local_address,
                    uint8_t destination)
{
    if(address_is_broadcast(destination))
    {
        return 1;
    }

    return(local_address == destination);
}


