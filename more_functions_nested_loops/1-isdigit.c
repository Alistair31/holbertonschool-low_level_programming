#include <stdio.h>
#include "main.h"
/**
 * _isdigit - Entry point
 * @n: a character that will be checked
 * Return: 1 when c is a digit
 */

int _isdigit(int n)

{
	if (n >= 48 && n <= 57)
	{
		return (1);
	}
	else
	return (0);
}
