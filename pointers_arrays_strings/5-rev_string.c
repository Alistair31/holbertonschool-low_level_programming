#include "main.h"
#include <stdio.h>
#include "2-strlen.c"
/**
 * rev_string - reverse a string
 * @s: string that be reversed
 * Return: void
 */
void rev_string(char *s)
{
	int l;
	int i;
	char tp;

	i = 0;
	l = _strlen(s) - 1;
	while (i < l)
	{
		tp = s[i];
		s[i] = s[l];
		s[l] = tp;
		i++;
		l--;
	}
}
