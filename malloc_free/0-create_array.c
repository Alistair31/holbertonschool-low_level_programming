#include <stdio.h>
#include <stdlib.h>
#include "main.h"
/**
 * *create_array - creates an array of chars,
 *  and initializes it with a specific char.
 * @size: size of the array
 * @c: initialize the array
 * Return: NULL if size is 0 or if it fails
 */
char *create_array(unsigned int size, char c)
{
	char *cp;
	unsigned int i;

	if (size == 0)
	{
		return (NULL);
	}
	cp = malloc(sizeof(char) * size);
	if (cp == NULL)
	{
		return (NULL);
	}
	for (i = 0; i < size; i++)
	{
		cp[i] = c;
	}
	return (cp);
}
