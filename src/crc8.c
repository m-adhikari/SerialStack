#include "crc8.h"

#define CRC8_POLYNOMIAL 0x07
#define CRC8_INITIAL    0x00

uint8_t crc8_calculate(const uint8_t *data, size_t length)
{
    uint8_t crc = CRC8_INITIAL;

    if (data == NULL)
    {
        return 0;
    }

    for (size_t i = 0; i < length; i++)
    {
        crc ^= data[i];

        for (uint8_t bit = 0; bit < 8; bit++)
        {
            if (crc & 0x80)
            {
                crc = (crc << 1) ^ CRC8_POLYNOMIAL;
            }
            else
            {
                crc <<= 1;
            }
        }
    }

    return crc;
}

int crc8_verify(const uint8_t *data,
                size_t length,
                uint8_t expected)
{
    return (crc8_calculate(data, length) == expected);
}


