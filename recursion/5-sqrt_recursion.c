#include "main.h"
/**
 * _sqrt - test the value of n for square root
 * @n: number in input
 * @i: value tested for square root
 * Return: square root of n
 */
int _sqrt(int n, int i)
{
	if (i * i == n)
		return (i);
	if (i * i > n)
		return (-1);
	return (_sqrt(n, i + 1));
}
/**
 * _sqrt_recursion - function that returns the natural square root of a number
 * @n: number to square
 * Return: square root of number
 */

int _sqrt_recursion(int n)
{
	if (n < 0)
		return (-1);
	return (_sqrt(n, 0));
}
