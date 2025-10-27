#include "main.h"
 /**
 * print_diagonal - function that print characters in a diagonal form
 * @n: number of line to print
 * @ln: define 
 * @sp: incredentation of space in each printed line
 */
void print_diagonal(int n)
{
	int sp;
	int ln;
		if (n <= 0)
		{
			_putchar('\n');
		}
		else
		{
			for (ln = 0; ln < n; ln++)
			{
				if (ln > 0)
				{
					for (sp = 0; sp < ln; sp++)
					_putchar(' ');
				}
				_putchar('\\');
				_putchar('\n');
			}
		}
}
