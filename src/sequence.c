#include "sequence.h"

#include <stdint.h>

/*
 * Internal State
 */

#define SEQUENCE_WINDOW_SIZE 8

static uint8_t tx_sequence = 0;

/* Circular buffer for recently received sequence numbers */
static uint8_t sequence_window[SEQUENCE_WINDOW_SIZE];
static uint8_t window_head = 0;   /* Next insertion index */
static uint8_t window_count = 0;  /* Number of valid entries */

void sequence_init(void)
{
    tx_sequence = 0;
    window_head = 0;
    window_count = 0;
}

uint8_t sequence_next(void)
{
    uint8_t current = tx_sequence;

    tx_sequence++;    

    return current;
}

uint8_t sequence_current(void)
{
    return tx_sequence;
}

void sequence_reset(uint8_t value)
{
    tx_sequence = value;
}

int sequence_is_duplicate(uint8_t sequence)
{
    for (uint8_t i = 0; i < window_count; i++)
    {
        uint8_t index = (window_head + SEQUENCE_WINDOW_SIZE - window_count + i)
                        % SEQUENCE_WINDOW_SIZE;

        if (sequence_window[index] == sequence)
        {
            return 1;
        }
    }

    return 0;
}

void sequence_record(uint8_t sequence)
{
    sequence_window[window_head] = sequence;

    window_head = (window_head + 1) % SEQUENCE_WINDOW_SIZE;

    if (window_count < SEQUENCE_WINDOW_SIZE)
    {
        window_count++;
    }
}
