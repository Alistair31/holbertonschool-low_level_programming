#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lists.h"
/**
 * add_node_end - adds a new node at the end of a list
 * @head: pointer to the beginning of the list
 * @str: string to add in the new node
 * Return: address of the new element, NULL if it failed
 */
list_t *add_node_end(list_t **head, const char *str)
{
	list_t *new_node;
	list_t *curr = *head;
	char *str1;
	int lenght = 0;

	new_node = malloc(sizeof(list_t));
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
	while (str1[lenght] != '\0')
	{
		lenght++;
	}

	new_node->str = str1;
	new_node->len = lenght;
	new_node->next = NULL;

	if (*head == NULL)
	{
		*head = new_node;
	}
	else
	{
		curr = *head;
		while (curr->next != NULL)
		{
		curr = curr->next;
		}
	curr->next = new_node;
	}
	return (new_node);
}
