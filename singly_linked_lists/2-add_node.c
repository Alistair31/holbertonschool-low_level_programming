#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lists.h"
/**
 * add_node - adds a new node at the beginning of a list
 * @head: pointer to the beginning of the list
 * @str: string to add in the new node
 * Return: address of the new element, NULL if it failed
 */
list_t *add_node(list_t **head, const char *str)
{
	list_t *new_node = malloc(sizeof(head));
	char *str1;

	if (new_node == NULL)
	{
		return (NULL);
	}
	str1 = strdup(str);

	if (str1 == NULL)
	{
		free(new_node);
		return (NULL);
	}
	new_node->str = str1;
	new_node->len = strlen(str1);
	new_node->next = *head;
	*head = new_node;

	return (new_node);
}
