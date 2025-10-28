#include "main.h"
/**
 * print_numbers - prints numbers from 0 to 9
 * Return: void
 */
void print_numbers(void)
{
	int nb;

	for (nb = 48; nb < 58; nb++)
	{
		_putchar(nb);
	}
	_putchar('\n');
}
