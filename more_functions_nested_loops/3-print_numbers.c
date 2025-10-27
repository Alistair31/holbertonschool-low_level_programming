#include "main.h"
 /**
 * print_numbers- function used to print all digits
 * Return: Always 0 (Success)
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
