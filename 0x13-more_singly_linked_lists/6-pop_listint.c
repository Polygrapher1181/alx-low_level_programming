#include "lists.h"

/**
 * pop_listint - deletes the head node of a listint_t linked list,
 * and returns the head node’s data (n).
 *
 * @head: pointer to head
 *
 * Return: if the linked list is empty return 0 or
 * returns the head node’s data (n)
 */

int pop_listint(listint_t **head)
{
	listint_t *tmp = *head;
	int n;

	if (!*head || !head)
		return (0);

	n = tmp->n;
	*head = (*head)->next;
	free(tmp);
	return (n);
}
