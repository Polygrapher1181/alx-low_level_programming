#include "main.h"

/**
 * get_endianness - check
 *
 * return - 0 or 1
 */

int get_endianness(void)
{
	int poll = 1;
	char *ptr = (char *)&poll;

	if (*ptr == 1)
		return (1);
	else
		return (0);
}
