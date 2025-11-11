#include <stdio.h>
#include <stdlib.h>
#include "main.h"
/**
 * _strdup - returns a pointer to a new string
 *  which is a duplicate of the string
 * @str: string to duplicate
 * Return: copied string
 */
char *_strdup(char *str)
{
	int i;
	int len;
	char *cpy;
	char *tmpstr;

	if (str == NULL)
	{
		return (NULL);
	}
	len = 0;
	tmpstr = str;
	while (tmpstr[len] != '\0')
	{
		len++;
	}
	cpy = malloc(sizeof(char) * (len + 1));
	if (cpy == NULL)
	{
		return (NULL);
	}
	for (i = 0; i < len; i++)
	{
		cpy[i] = str[i];
	}
	return (cpy);
}
