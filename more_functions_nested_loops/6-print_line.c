#include "main.h"
/**
 * print_line - function used to print a straight line
 * @n: number of underscore to print
 */
void print_line(int n)
{
	int ln;

	if (n <= 0)
	{
		_putchar('\n');
	}
	else
	{
		for (ln = 0; ln < n; ln++)
		{
			_putchar('_');
		}
			_putchar('\n');
	}
}
