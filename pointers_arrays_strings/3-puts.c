#include "main.h"
#include <stdio.h>
/**
 * _puts - prints a string to stdout
 * @str: string to print
 * Return: void
 */
void _puts(char *str)
{
	while (*str)
	{
	_putchar(*str);
	str++;
	}
	_putchar('\n');
}
