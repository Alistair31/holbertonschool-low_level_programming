#include "main.h"
#include <stdio.h>
/**
 * puts2 - print only pair numbers
 * @str: string of numbers
 * Return: void
 */
void puts2(char *str)
{
	int i = 0;

	while (str[i] != '\0')
	{
		_putchar(str[i]);
		i = i + 2;
	}

	_putchar('\n');
}
