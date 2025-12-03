#include <stdio.h>
#include <stdlib.h>
#include "lists.h"
/**
 * add_dnodeint - adds a new node at the beginning of a list
 * @head: pointer to the beginning of the list
 * @n: data in the nodes
 * Return: address of the new element, NULL if it failed
 */
dlistint_t *add_dnodeint(dlistint_t **head, const int n)
{
	dlistint_t *new_node;
	int n1;

	new_node = malloc(sizeof(dlistint_t));
	if (new_node == NULL)
	{
		return (NULL);
	}
	if (head == NULL)
	{
		free(new_node);
		return (NULL);
	}
	n1 = n;
	new_node->n = n1;
	new_node->next = *head;
	*head = new_node;

	return (new_node);
}
