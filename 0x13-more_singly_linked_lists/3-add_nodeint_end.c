#include "lists.h"

/**
 * add_nodeint_end - adds a new node at the end of list
 *
 * @head: pointer to the address
 *
 * @main body contents
 *
 * @n: the integer for the new node
 *
 * @return - output
 *
 * Return: Null or new element
 *
 */

listint_t *add_nodeint_end(listint_t **head, const int n)
{

	listint_t *new_node;
	listint_t *temp_node;

	(void)temp_node;

	
	new_node = malloc(sizeof(listint_t));

	if (new_node == NULL)
		return (NULL);

	new_node->n = n;
	new_node->next = NULL;
	temp_node = *head;

	if (*head == NULL)
	{
		*head = new_node;
	}
	else
	{
		while (temp_node->next != NULL)
		{
			temp_node = temp_node->next;
		}
		temp_node->next = new_node;
	}
	return (*head);
}
