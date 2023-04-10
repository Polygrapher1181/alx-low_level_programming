#include "main.h"

/**
 * get_endianness - checks the endianness of the system
 *
 * Return: 0 if big endian, 1 if little endian
 */
int get_endianness(void)
{
    int num = 1;
    char *ptr = (char *)&num;

    if (*ptr == 1)
    {
        /* Little endian */
        return 1;
    }
    else
    {
        /* Big endian */
        return 0;
    }
}
