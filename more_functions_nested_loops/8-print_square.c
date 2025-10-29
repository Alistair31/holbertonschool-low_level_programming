#include "main.h"
/**
 * print_square - function that print a square of hashtags
 * @size: size of the square
 * Return: void
 */
void print_square(int size)
{
	int ln;
	int ht;

	if (size > 0)
	{
		for (ln = 1; ln <= size; ln++)
		{
			for (ht = 1; ht <= size; ht++)
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
