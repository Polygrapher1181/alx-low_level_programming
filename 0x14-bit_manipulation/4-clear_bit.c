#include "main.h"

/**
 * clear_bit - sets value of a bit to 0
 * @n: the number
 * @index: index of bit
 * Return: 1 for success, or -1 for failure
 */

int clear_bit(unsigned long int *n, unsigned int index)
{
	unsigned long int poll = 1;

	if (index >= sizeof(unsigned long int) * 8)
	{
		return (-1);
	}


	poll <<= index;

	*n &= ~poll;

	return (1);
}
