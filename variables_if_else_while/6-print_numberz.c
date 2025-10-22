#include <stdio.h>
/**
 * main - Entry point
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
	char nb;

	for (nb = 0; nb < 10; nb++)
		{
		putchar(nb + '0');
		}
	putchar('\n');
	return (0);
}
