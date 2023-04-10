#include "main.h"

/**
 * print_binary - Prints the binary representation of a number
 *
 * @n: The number to print in binary
 */
void print_binary(unsigned long int n)

{
    int count = 0 
    if (n == 0)
    {
        _putchar('0');
        return;
    }

    int i;

    int size = sizeof(unsigned long int) * 8;

    for (i = size - 1; i >= 0; i--)

    {
        if ((n >> i) & 1)
            _putchar('1');

        else
            _putchar('0');
    }
}

