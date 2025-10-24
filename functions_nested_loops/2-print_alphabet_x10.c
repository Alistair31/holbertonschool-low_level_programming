#include <stdio.h>
#include "main.h"
/**
 * print_alphabet_x10 - Entry point
 *
 * Return: Always 0 (Success)
 */

void print_alphabet_x10(void)
{
	int c;
	int it = 97;

	while (it <= 106)
	{
		it++;
		for (c = 97; c < 123; c++)
		{
		_putchar(c);
		}
	_putchar('\n');
	}
}
