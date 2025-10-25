#include "main.h"
/**
 * print_sign - Entry point
 * @n: a numbers that will be checked
 * Return: 1 when n is positive, -1 when c is negative or 0 when c equal 0
 */

int print_sign(int n)

{
	if (n > 0)
	{
		_putchar('+');
		return (1);
	}
	else if (n < 0)
	{
		_putchar('-');
		return (-1);
	}
	else
	{
		_putchar('0');
		return (0);
	}
}
