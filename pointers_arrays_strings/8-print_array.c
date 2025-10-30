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
	int i;

	for (i = 0; i < n; i++)
	{
		printf("%d", a[i]);
		if (i < n - 1)
		{
			printf(", ");
		}
	}
	printf("\n");
}
