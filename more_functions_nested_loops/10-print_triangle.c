#include "main.h"
 /**
 * print_square - function that print a triangle of hashtags
 * @size: size of the triangle
 * @ln: numbers of line
 * @ht: numbers of column
 */
void print_triangle(int size)
{
	int ln;
	int ht;
	int hsh;

	if (size > 0)
	{
		for (ln = 0; ln < size; ln++)
		{
			for (ht = size; ht > ln; ht--)
			{
				_putchar(' ');
			}
			for (hsh = 1; hsh <= ln + 1; hsh++)
			{
				_putchar('#');
			}
			_putchar('\n');
		}
	}
}
