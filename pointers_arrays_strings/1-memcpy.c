#include "main.h"
/**
 * _memcpy - copies memory area.
 * @dest: memory area
 * @src: memory to cpy
 * @n: numbers of bytes to copy
 * Return: pointer to the memory area
 */
char *_memcpy(char *dest, char *src, unsigned int n)
{
	unsigned int i;

	for (i = 0; i < n; i++)
	{
		dest[i] = src[i];
	}
	return (dest);
}
