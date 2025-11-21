#ifndef variadic_functions
#define variadic_functions

#include <stdarg.h>
/**
 * struct allformat - choose the type
 * @c: type of the string to print
 * @f: pointer to function that print the type
 */
typedef struct allformat
{
	char c;
	void (*f)(va_list args);
} allformat;

int sum_them_all(const unsigned int n, ...);
void print_numbers(const char *separator, const unsigned int n, ...);
void print_strings(const char *separator, const unsigned int n, ...);
void printchar(va_list args);
void printint(va_list args);
void printfloat(va_list args);
void printstring(va_list args);
void print_all(const char * const format, ...);

#endif
