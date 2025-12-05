#include <stdio.h>
#include <stdlib.h>
#include "lists.h"
/**
 * sum_dlistint - function that returns the sum of all data of a linked list
 * @head: pointer to the biggining of a list
 * Return: sum of all the data in list / 0 if list is empty
 */
int sum_dlistint(dlistint_t *head)
{
	int sum = 0;

	while (head != NULL)
	{
		sum += head->n;
		head = head->next;
	}

	return (sum);
}
