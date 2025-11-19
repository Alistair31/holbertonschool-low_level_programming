#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include "variadic_functions.h"
/**
 * print_numbers - function that prints numbers, followed by a new line
 * @separator: string that separate numbers
 * @n: numbers of integer passed to the function
 */
void print_numbers(const char *separator, const unsigned int n, ...)
{
	int x;
	unsigned int i;
	va_list args;

	va_start(args, n);

	for (i = 0; i < n; i++)
	{
		x = va_arg(args, int);
		printf("%d", x);
		if (separator != NULL && i < (n - 1))
		{
		printf("%s", separator);
		}
	}
	printf("\n");
	va_end(args);
}
