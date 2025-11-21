#include <stdio.h>
#include <stdlib.h>
#include "main.h"
/**
 * _calloc - allocates memory for an array to zero
 * @nmemb: number of elements
 * @size: size of the elements
 * Return: void
 */
void *_calloc(unsigned int nmemb, unsigned int size)
{
	char *cal;
	unsigned int i;

	if (nmemb == 0)
	{
		return (NULL);
	}
	if (size == 0)
	{
		return (NULL);
	}
	cal = malloc(nmemb * size);
	if (cal == NULL)
	{
		return (NULL);
	}
	for (i = 0; i < (nmemb * size); i++)
	{
		cal[i] = 0;
	}
	return (cal);
}
