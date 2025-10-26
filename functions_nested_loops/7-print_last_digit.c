#include "main.h"
/**
 * print_last_digit - check the code
 * @nb: number that will be checked
 * Return: Always 0.
 */
int print_last_digit(int nb)
{
	int ld;

	ld = nb  % 10;

	if (ld < 0)
	{
		ld = -ld;
	}
	_putchar(ld + '0');
	return (ld);
}
