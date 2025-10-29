#include "main.h"
#include <stdio.h>
#include "2-strlen.c"
/**
 * print_rev - print in reverse
 * @s: string to print
 * Return: void
 */
void print_rev(char *s)
{
	int l;

	l = _strlen(s);

	while (l > 0)
	{
		_putchar(s[l - 1]);
		l--;
	}
	_putchar('\n');

}
