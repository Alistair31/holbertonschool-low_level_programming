#include "main.h"
/**
 * more_numbers - print all digits (expect 2 and 4)
 * Return: void
 */
void more_numbers(void)
{
	int nb;
	int it = 0;

	while (it <= 9)
	{
		it++;
		for (nb = 0; nb <= 14; nb++)
		{
			if (nb > 9)
			{
				_putchar((nb / 10) + '0');
			}
			_putchar((nb % 10) + '0');
		}
		_putchar('\n');
	}
}
