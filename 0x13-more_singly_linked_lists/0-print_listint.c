#include "lists.h"
#include <stdio.h>

/**
 * print_listint - Prints all the elements of a linked list of integers
 * @head: Pointer to the first node of the list
 * @printf: Prints elements in the list
 *
 *
 * Return: The number of nodes in the list
 */

size_t print_listint(const listint_t *head)
{
	size_t count = 0;

	while (head != NULL)
	{
		printf("%d\n", head->n);
		head = head->next;
		count++;

	}
	return (count);
}
