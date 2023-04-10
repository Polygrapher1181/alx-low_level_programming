#include "main.h"
#include <stdio.h>

/**
 * print_binary - binary version of a number
 * @n: number to be printed as binary
 */

void print_binary(unsigned long int n)
{
	unsigned long int num;
	int shift_count;

	if (n == 0)
	{
		_putchar("0");
		return;
	}

	for (num = n, shift_count = 0;
			(num >>= 1) > 0;
			shift_count++);

	for (; shift_count >= 0; shift_count--)
	{
		if ((n >> shift_count) & 1)
			_putchar("1");
		else
			_putchar("0");
	}
}
