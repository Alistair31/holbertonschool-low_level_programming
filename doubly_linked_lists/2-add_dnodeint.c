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

	new_node = malloc(sizeof(dlistint_t));
	if (new_node == NULL)
	{
		return (NULL);
	}

	new_node->n = n;
	new_node->prev = NULL;
	new_node->next = *head;

	if (*head != NULL)
	{
	(*head)->prev = new_node;
	}

	*head = new_node;
	return (new_node);
}
#include <stdio.h>
