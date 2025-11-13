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
	int i;
	int j;
	int len1;
	int len2;
	int lenf;
	char *nconc;

	if (s1 == NULL)
	{
		return ("");
	}
	if (s2 == NULL)
	{
		return ("");
	}
	while (s1[len1] != '\0')
	{
		len1++;
	}
	len2 = (s2[n]);
	lenf = (len1 + len2 + 1);
	nconc = malloc(sizeof(char) * lenf);
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
