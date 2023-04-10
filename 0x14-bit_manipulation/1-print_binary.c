#include "main.h"

/**
 *print_binary - function to print binary rep
 *@n: the number
 *Return: void
 *
 */

void print_binary(unsigned long int n)
{
	int keepCount = 0;

	int j;

	for (j = 63; j >= 0; j--)
	{
		int bitNo = (n >> j) & 1;

		if (bitNo)
		{
			_putchar('1');
			keepCount++;
		}
		else if (keepCount > 0)
		{
			_putchar('0');
		}
	}
	if (keepCount == 0)
	{
		_putchar('0');
	}
}
