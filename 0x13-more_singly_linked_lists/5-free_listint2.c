#include "lists.h"

/**
 * free_listint2 - opens up a list
 *
 * @head: a pointer to the list
 *
 * @main - check code
 *
 * @return - null
 *
 *
 * Return: Nothing
 */

void free_listint2(listint_t **head)
{
	listint_t *temp_node;
	listint_t *current_node;

	if (head != NULL)
	{
		current_node = *head;
		while ((temp_node = current_node) != NULL)
		{
			current_node = current_node->next;
			free(temp_node);
		}
		*head = NULL;
	}
}
