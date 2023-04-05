#include "lists.h"
/**
 * reverse_listint - reverses the list
 * @head: a pointer to the list
 * Return: a poinnter to the first node of the reversed list
 *
 * Return: to first node
 */

listint_t *reverse_listint(listint_t **head)
{
	listint_t *current, *prev;

	if (head == NULL || *head == NULL)
		return (NULL);

	prev = NULL;

	while ((*head)->next != NULL)
	{
		current = (*head)->next;
		(*head)->next = prev;
		prev = *head;
		*head = current;
	}

	(*head)->next = prev;

	return (*head);
}
