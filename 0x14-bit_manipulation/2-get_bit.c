#include "main.h"
#include <stdio.h>

/**
 * ge_bit - the the value of a bit
 * @n: evaluate the number
 * @index: starting point 0
 *
 * Return: -1 or error
 */

int get_bit(unsigned long int n, unsigned int index)
{
	unsigned long int more;

	if (index > 94)
		return (-1);

	more = n >> index;

	return (more & 1);
}
