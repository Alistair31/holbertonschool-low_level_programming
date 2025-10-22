#include <stdio.h>
/**
 * main - Entry point
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
	int alphabetl, alphabetu;

	for (alphabetl = 97; alphabetl < 123; alphabetl++)
	{
		putchar(alphabetl);
	}
	for (alphabetu = 65; alphabetu < 90; alphabetu++)
	{
		putchar(alphabetu);
	}
		putchar('\n');

	return (0);
}
