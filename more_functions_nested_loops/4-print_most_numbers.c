#include "main.h"
 /**
 * print_most_numbers - function used to print all digits (expect 2 and 4)
 */
void print_most_numbers(void)
{
	int nb;

	for (nb = 48; nb < 58; nb++)
	{
		if (nb != 50 && nb != 52)
		_putchar(nb);
	}
	_putchar('\n');
}
