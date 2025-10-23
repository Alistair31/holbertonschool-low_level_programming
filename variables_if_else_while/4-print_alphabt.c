#include <stdio.h>
/**
 * main - Entry point
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
	int abt;

	for (abt = 97; abt < 123; abt++)
	{
		if (abt != 101 && abt != 113)
		{
			putchar(abt);
		}
	}
	putchar('\n');
	return (0);
}
