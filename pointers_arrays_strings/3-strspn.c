#include "main.h"

/**
 * _strspn - gets the length of a prefix substring
 * @s: string to analyze
 * @accept: segment of bytes to get
 * Return: number of bytes in the initial
 * segment of s which consist only of bytes from accept
 */
unsigned int _strspn(char *s, char *accept)
{
	unsigned int cpt = 0;
	char *a;
	int count;

	while (*s != '\0')
	{
		count = 0;
		for (a = accept; *a != '\0'; a++)
		{
			if (*s == *a)
			{
				count = 1;
				break;
			}
		}
		if (!count)
			break;
		cpt++;
		s++;
	}
	return (cpt);
}
