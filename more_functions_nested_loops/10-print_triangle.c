#include "main.h"
/**
 * print_triangle - print a triangle of hashtags
 * @size: size of the triangle
 */
void print_triangle(int size)
{
	int ln;
	int ht;
	int hsh;

	if (size > 0)
	{
		for (ln = 1; ln <= size; ln++)
		{
			for (ht = size; ht > ln; ht--)
			{
				_putchar(' ');
			}
			for (hsh = 1; hsh < ln + 1; hsh++)
			{
				_putchar('#');
			}
			_putchar('\n');
		}
	}
	else
	{
		_putchar('\n');
	}
}
