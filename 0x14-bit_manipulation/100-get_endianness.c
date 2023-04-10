#include "main.h"

/**
 * get_endianness - check
 *
 * return - 0 or 1
 */

int get_endianness(void)
{
	int x = 1;
	char *ptr = (char *)&x;

	if (*ptr == 1)
		return (1);
	else
		return (0);
}
