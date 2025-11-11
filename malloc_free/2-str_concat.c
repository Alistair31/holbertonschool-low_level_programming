#include <stdio.h>
#include <stdlib.h>
#include "main.h"
/**
 * str_concat - concatenates two strings.
 * @s1: first string
 * @s2: second string
 * Return: concatened strings
 */
char *str_concat(char *s1, char *s2)
{
	int len1;
	int len2;
	int lenf;
	int i;
	int j;
	char *conc;

	len1 = 0;
	len2 = 0;
	if (s1 == NULL || s2 == NULL)
	{
		s1 = "";
		s2 = "";
	}
	while (s1[len1] != '\0')
	{
		len1++;
	}
	while (s2[len2] != '\0')
	{
		len2++;
	}
	lenf = ((len1 + len2 + 1));
	conc = malloc(sizeof(char) * lenf);
	for (i = 0; i < len1; i++)
	{
		conc[i] = s1[i];
	}
	for (j = 0; j < len2; j++)
	{
		conc[i + j] = s2[j];
	}
	conc[i + j] = '\0';
	return (conc);
}
