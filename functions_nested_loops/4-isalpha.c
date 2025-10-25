#include <stdio.h>
#include "main.h"
/**
 * _isalpha - Entry point
 * @c: a character that will be checked
 * Return: 1 when c is an alphabetical character
 */

int _isalpha(int c)

{
	if (c >= 65 && c <= 90)
	{
		return (1);
	}
	else if (c >= 97 && c <= 122)
	{
		return (1);
	}
	else
	return (0);
}
