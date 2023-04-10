#include "main.h"
/**
 *flip_bits - function to flip bits
 *@n:argument
 *@m:argument
 *Return:the count
 *
 */
unsigned int flip_bits(unsigned long int n, unsigned long int m)
{
	unsigned int count = 0;

	int p;

	unsigned long  int  theDiff = n ^ m;

	for (p = 0; p < 64; p++)
	{
		count += (theDiff >> p) & 1;
	}

	return (count);
}
