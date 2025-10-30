#include "main.h"
#include <stdio.h>
#include "_putchar.c"
/**
 * _strcpy - copy a pointed string
 * @dest: destination of copy
 * @src: source string to copy
 * Return: void
 */
char *_strcpy(char *dest, char *src)
{
	int i = 0;

	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
