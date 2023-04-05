#include "lists.h"

/**
 * delete_nodeint_at_index - Deletes a node at an index
 *
 * @head: a pointer to the list
 *
 * @main - run code output
 * 
 * @index: index of the node
 * @return null -1
 *
 * Return: Success = 1 and fail = -1
 */

int delete_nodeint_at_index(listint_t **head, unsigned int index)
{
	unsigned int i;
	listint_t *previous_node, *next_node;

	previous_node = *head;

	if (index != 0)
	{
		for (i = 0; i < index - 1 && previous_node != NULL; i++)
		{
			previous_node = previous_node->next;
		}
	}
	if (previous_node == NULL || (previous_node->next == NULL && index != 0))
	{
		return (-1);
	}

	next_node = previous_node->next;

	if (index != 0)
	{
		previous_node->next = next_node->next;
		free(next_node);
	}
	else
	{
		free(previous_node);
		*head = next_node;
	}

	return (1);
}
