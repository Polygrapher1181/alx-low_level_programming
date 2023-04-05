#include "lists.h"

/**
 * insert_nodeint_at_index - starts a new node
 * @head: a pointer to the list
 * @idx: the index where the node will go
 * @n: an integer
 *
 * Return: Null or new address
 */

listint_t *insert_nodeint_at_index(listint_t **head, unsigned int idx, int n)
{
	listint_t *new_node, *temp = *head;
	unsigned int node_index;

	new_node = malloc(sizeof(listint_t));
	if (new_node == NULL)
		return(NULL);

	new_node->n = n;

	if (idx == 0)
	{
		new_node->next = temp;
		*head = new_node;
		return(new_node);
	}

	for (node_index = 0; node_index < (idx - 1); node_index++)
	{
		if (temp == NULL || temp->next == NULL)
			return (NULL);

		temp = temp->next;
	}

	new_node->next = temp->next;
	temp->next = new_node;

	return(new_node);
}
