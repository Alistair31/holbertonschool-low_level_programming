#include <stdio.h>
/**
 * main - Entry point
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
	char tebahpla;

	tebahpla = 'z';

	while (tebahpla >= 'a')
	{
		putchar(tebahpla);
		tebahpla--;
	}
		putchar('\n');
	return (0);
}
