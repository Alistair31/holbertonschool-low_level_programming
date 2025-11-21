#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include "variadic_functions.h"
/**
 * print_strings - function that prints strings, followed by a new line
 * @separator: separartion characters printed between strings
 * @n: numbers of strings to print
 */
void print_strings(const char *separator, const unsigned int n, ...)
{
	char *x;
	unsigned int i;
	va_list args;

	va_start(args, n);

	for (i = 0; i < n; i++)
	{
		x = va_arg(args, char *);
		if (x == NULL)
		{
			printf("(nil)");
		}
		else
		{
			printf("%s", x);
		}
		if (separator != NULL && i < (n - 1))
		{
		printf("%s", separator);
		}
	}
	printf("\n");
	va_end(args);
}
