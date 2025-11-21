#include <stdio.h>
#include <stdlib.h>
#include "main.h"
#include "/home/alistair31/holbertonschool-low_level_programming/pointers_arrays_strings/0-memset.c"
/**
 * _calloc - allocates memory for an array to zero
 * @nmemb: number of elements
 * @size: size of the elements
 * Return: void
 */
void *_calloc(unsigned int nmemb, unsigned int size)
{
	void *cal;

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
	_memset(cal, 0, nmemb * size);
	return (cal);
}
