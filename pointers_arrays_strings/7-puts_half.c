#include "main.h"
#include <stdio.h>
#include "2-strlen.c"
/**
 * puts_half - print only half of a string
 * @str: string of characters
 * Return: void
 */
void puts_half(char *str)
{
	int l;
	int j;

	l = _strlen(str);
	j = ((l + 1) / 2);

	while (j < l)
	{
		_putchar(str[j]);
		j++;
	}
	_putchar('\n');
}
