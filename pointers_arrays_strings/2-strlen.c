#include "main.h"
#include <stdio.h>
/**
 * _strlen - return the lenght of a string
 * @s: string to measure
 * Return: result of the length .
 */
int _strlen(char *s)
{
	int stg;

	stg = 0;
	while (*s != '\0')
	{
		stg++;
		s++;
	}
	return (stg);
}
