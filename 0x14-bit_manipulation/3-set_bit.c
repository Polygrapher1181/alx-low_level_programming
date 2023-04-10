#include "main.h"
/**
 *set_bit - sets a certain bit to 1
 *@n: the set of bits given
 *@index: the chosen index
 *Return: int type
 */
int set_bit(unsigned long int *n, unsigned int index)
{
	unsigned long int changeBit = 1;

	if (index >= sizeof(unsigned long int) * 8)
	{
		return (-1);
	}

	changeBit <<= index;

	*n |= changeBit;

	return (1);
}


