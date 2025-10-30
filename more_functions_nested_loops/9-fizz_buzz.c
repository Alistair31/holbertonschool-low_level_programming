#include "main.h"
#include <stdio.h>
#include "_putchar.c"
 /**
 * fizz_buzz - print fizz or buzz instead of multiple of 3 and 5 respectfully
 * Return: 0
 */

int main(void)

{
	int nb, dz, un;

	for (nb = 1; nb <= 100; nb++)
	{
		if (nb >= 100)
		{
			_putchar('1');
			_putchar('0');
			_putchar('0');
		}
		else if (nb >= 10)
		{
			if ((nb % 3) == 0)
			{
				_putchar('f');
				_putchar('i');
				_putchar('z');
				_putchar('z');
			}
			else if ((nb % 5) == 0)
			{
				_putchar('b');
				_putchar('u');
				_putchar('z');
				_putchar('z');
			}
			else
			{
			dz = nb / 10;
			un = nb % 10;
			_putchar(dz + '0');
			_putchar(un + '0');
			}
		}
		else
		{
			_putchar(nb + '0');
		}
		_putchar(' ');
	}
	_putchar('\n');
	return (0);
}
