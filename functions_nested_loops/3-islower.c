#include <stdio.h>
#include "main.h"
/**
 * _islower - Entry point
 * @c: a character that will be checked
 * Return: 1 when c is a lowercase alphabetical character
 */

int _islower(int c)

{
	if (c >= 97 && c <= 122)
	{
		return (1);
	}
	else
	return (0);
}
