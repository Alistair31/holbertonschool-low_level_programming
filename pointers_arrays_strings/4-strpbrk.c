#include "main.h"

/**
 * _strpbrk - function that searches a string for any of a set of bytes
 * @s: string to analyze
 * @accept: segment of bytes to get
 * Return: number of bytes in the initial
 * segment of s which consist only of bytes from accept
 */
char *_strpbrk(char *s, char *accept)
{
	char *a;

	while (*s != '\0')
	{
		for (a = accept; *a != '\0'; a++)
		{
			if (*s == *a)
			{
				return (s);
			}
		}
		s++;
	}
	return (0);
}
