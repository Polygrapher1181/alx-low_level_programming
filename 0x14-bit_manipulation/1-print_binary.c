#include "main.h"
#include <stdio.h>

/**
 * print_binary - binary version of a number
 * @n: number to be printed as binary
 */

void print_binary(unsigned long int n)
{
	unsigned long int num;
	int count;

	if (n == 0)
	{
		_putchar("0");
		return;
	}

	for (num = n, count = 0;
			(num >>= 1) > 0;
			count++);

	for (; count >= 0; count--)
	{
		if ((n >> count) & 1)
			_putchar("1");
		else
			_putchar("0");
	}
}
