#ifndef SEQUENCE_H
#define SEQUENCE_H

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

/**
 *@brief Initializes the sequence nubmer generator.
 * 
 * Sequence number is implementation defined.
 */

void sequence_init(void);

/**
 * @brief returns the next transmit sequence number.
 * 
 * Sequence numbers auto-wrap in range [255, 0]
 * 
 * @return the next seqence number  
 */
uint8_t sequence_next(void);

/**
 * @brief Returns the current seq. num.
 * 
 * @return current sequence number
 */
uint8_t sequence_current(void);

/**
 * @brief reset seq. counter.
 * 
 * @param value Initial seq. number.
 */

void sequence_reset(uint8_t value);

/**
 * @brief check if given seq. num. is duplicate. 
 *
 * @param sequence Received sequence number.
 *
 * @return 1 if duplicate.
 * @return 0 otherwise.   
 */
int sequence_is_duplicate(uint8_t sequence);

/**
 *@brief Records a newly received sequence number.
 *
 * @param sequence Sequence number to record.
 */
void sequence_record(uint8_t sequence);

#ifdef __cplusplus
}
#endif

#endif /* SEQUENCE_H */

