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
	list_t *new_node;
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
	new_node->next = *head;
	*head = new_node;

	return (new_node);
}
