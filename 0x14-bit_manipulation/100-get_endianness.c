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
	unsigned int keepCount = 0;

	int i;

	unsigned long  int  theDiff = n ^ m;

	for (i = 0; i < 64; i++)
	{
		keepCount += (theDiff >> i) & 1;
	}

	return (keepCount);
}
