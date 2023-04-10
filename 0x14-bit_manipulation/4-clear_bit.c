#include "main.h"

/**
 * clear bit - sets the value to 0
 *
 * @index: given index
 * Return 1 if correct -1 if wrong
 */

int clear_bit(unsigned long int *n, unsigned int index)
{
	unsigned long int pol = 1;

	if (index >= sizeof(unsigned long int) * 8)
		return (-1);

	pol <<= index;

	if ((*n & pol) == pol)
		*n ^= pol;

	return (1);
}
