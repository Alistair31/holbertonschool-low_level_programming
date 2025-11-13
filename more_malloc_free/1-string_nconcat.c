#include <stdio.h>
#include <stdlib.h>
#include "main.h"
/**
 * string_nconcat - concatenates two strings with n number
 *  of bytes of the second string
 * @s1: first string
 * @s2: second string
 * @n: number of bytes of the second string
 * Return: pointer to concatened string
 */
char *string_nconcat(char *s1, char *s2, unsigned int n)
{
	unsigned int i, j;
	unsigned int len1 = 0, len2 = 0;
	char *nconc;

	if (s1 == NULL)
	{
		s1 = ("");
	}
	if (s2 == NULL)
	{
		s2 = ("");
	}
	while (s1[len1] != '\0')
	{
		len1++;
	}
	while (s2[len2] != '\0')
	{
		len2++;
	}
	if (n < len2)
	{
		len2 = n;
	}
	nconc = malloc(sizeof(char) * (len1 + len2 + 1));
	if (nconc == NULL)
	{
		return ("");
	}
	for (i = 0; i < len1; i++)
	{
		nconc[i] = s1[i];
	}
	for (j = 0; j < len2; j++)
	{
		nconc[i + j] = s2[j];
	}
	nconc[i + j] = '\0';
	return (nconc);
}
