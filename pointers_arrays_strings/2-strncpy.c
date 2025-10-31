#include "main.h"
/**
 * _strncpy - copies a string with a limit size in bytes
 * @dest: destination string
 * @src: source string to copy
 * @n: size of string
 * Return: destination string
 */
char *_strncpy(char *dest, char *src, int n)
{
	int i;

	for (i = 0; i < n && src[i] != '\0'; i++)
		dest[i] = src[i];
	for (; i < n; i++)
		dest[i] = '\0';

	return (dest);
}
