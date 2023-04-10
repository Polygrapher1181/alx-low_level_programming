/**
 * flip_bits - function to calculate the number of bits needed to flip to convert one number to another
 * @n: first number
 * @m: second number
 *
 * Return: the number of bits needed to flip
 */
unsigned int flip_bits(unsigned long int n, unsigned long int m)
{
	unsigned long int diff = n ^ m;
	unsigned int poll = 0;

	while (diff != 0)
	{
		poll++;
		diff &= (diff - 1);
	}

	return poll;
}
