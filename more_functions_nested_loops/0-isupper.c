#include <stdio.h>
#include "main.h"
/**
 * _isupper - Entry point
 * @c: a character that will be checked
 * Return: 1 when c is a uppercase alphabetical character
 */

int _isupper(int c)

{
	if (c >= 65 && c <= 90)
	{
		return (1);
	}
	else
	return (0);
}
