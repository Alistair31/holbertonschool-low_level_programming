#include "main.h"
#include <stdio.h>
/**
 * swap_int - check the code
 * @a: first integer in function
 * @b: second integer to swap with the first
 * Return: Always 0.
 */
void swap_int(int *a, int *b)
{
	int trf = 0;

	trf = *b;
	*b = *a;
	*a = trf;
}
