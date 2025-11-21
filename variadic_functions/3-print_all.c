#include <stdio.h>
#include <stdarg.h>
#include "variadic_functions.h"

/**
 * printchar - prints a character from a va_list
 * @args: list of arguments containing the character
 * Return: nothing
 */
void printchar(va_list args)
{
	printf("%c", va_arg(args, int));
}

/**
 * printint - prints an integer from a va_list
 * @args: list of arguments containing the integer
 * Return: nothing
 */
void printint(va_list args)
{
	printf("%d", va_arg(args, int));
}

/**
 * printfloat - prints a float from a va_list
 * @args: list of arguments containing the float
 * Return: nothing
 */
void printfloat(va_list args)
{
	printf("%f", va_arg(args, double));
}

/**
 * printstring - prints a string from a va_list
 * @args: list of arguments containing the string
 * Return: nothing
 */
void printstring(va_list args)
{
	char *s = va_arg(args, char *);

	if (s == NULL)
	{
		s = "(nil)";
	}
	printf("%s", s);
}

/**
 * print_all - function that prints anything
 * @format: type of output to print
 */
void print_all(const char * const format, ...)
{
	int i = 0;
	int j;

	char *separator = "";

	va_list args;

	allformat formats[] = {
		{'c', printchar},
		{'i', printint},
		{'f', printfloat},
		{'s', printstring}
	};

	va_start(args, format);

	while (format != NULL && format[i] != '\0')
	{
		j = 0;
		while (j < 4)
		{
			if (format[i] == formats[j].c)
			{
				printf("%s", separator);
				formats[j].f(args);
				separator = ", ";
				break;
			}
			j++;
		}
		i++;
	}
	printf("\n");
	va_end(args);
}
