#include <stdio.h>
/**
 * main - Entry point
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
	int nb;

	for (nb = 48; nb < 58; nb++)
	{
		putchar(nb);
		if (nb < 57)
		{
			continue;
		}
	}
	putchar('\n');
	return (0);
}
