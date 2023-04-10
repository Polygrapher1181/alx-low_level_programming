#include "main.h"

/**
 * get_bit - returns the value of a bit at a given index
 *
 * @n: the number containing the bit to be returned
 * @index: the index of the bit to be returned
 *
 * Return: the value of the bit at the given index, or -1 if an error occurs
 */
int get_bit(unsigned long int n, unsigned int index)
{
	unsigned long int mask = 1;

	if (index >= sizeof(unsigned long int) * 8)
	{
		return (-1);
	}

	mask <<= index;

	if (n & mask)
	{
		return (1);
	}

	return (0);
}
