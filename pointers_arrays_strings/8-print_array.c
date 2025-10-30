#include "main.h"
#include <stdio.h>
/**
 * print_array - print all element of an array
 * @a: element of the array
 * @n: numbers of element
 * Return: void
 */
void print_array(int *a, int n)
{
	for (n = 0; n <= 4; n++)
	{
		printf("%d", n[a]);
		if (n != 4)
		{
			printf(", ");
		}
	}
	printf("\n");
}
