#include "main.h"
 /**
 * print_square - function that print a square of hashtags
 * @size: size of the square
 * @ln: numbers of line of the square
 * @ht: numbers of column of the square
 */
void print_square(int size)
{
	int ln;
	int b;

	for (ln = 1; ln <= size; ln++)
	{
		for (b = 1; b <= size; b++)
		{
			_putchar('#');
		}
		_putchar('\n');
	}
}
