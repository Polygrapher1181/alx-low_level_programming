#include "lists.h"

/**
 * free_listint - Opens up a list
 * @head: Pointer to the list to be opened up
 *
 * Return: Null
 *
 */
void free_listint(listint_t *head)
{
	listint_t *current, *next;

	current = head;

	while (current != NULL)
	{
		next = current->next;
		free(current);
		current = next;
	}
}

