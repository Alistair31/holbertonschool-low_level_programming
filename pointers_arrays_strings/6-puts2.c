#include "main.h"
#include <stdio.h>
/**
 * puts2 - print only pair numbers
 * @str: string of numbers
 * Return: void
 */
void puts2(char *str)
{
	while (*str)
	{
	if ((*str % 2) <= 0)
	_putchar(*str);
	str++;
	}
	_putchar('\n');
}
