#include "main.h"
#include <stdio.h>
/**
 * main - prints the numbers from 1 to 100, followed by a new line.
 * But for multiples of 3 print Fizz instead of
 * the number and for the multiples of 5 print Buzz.
 * For numbers which are multiples of both three and five print FizzBuzz
 * Return: 0
 */

int main(void)

{
	int nb;

	for (nb = 1; nb <= 100; nb++)
	{
		if ((nb % 5 == 0) && (nb % 3 == 0))
		{
			printf("FizzBuzz ");
		}
		else if (nb == 100)
		{
			printf("Buzz");
		}
		else if ((nb % 5 == 0) && (nb != 100))
		{
			printf("Buzz ");
		}
		else if (nb % 3 == 0)
		{
			printf("Fizz ");
		}
		else
		{
		printf("%i ", nb);
		}
	}
	printf("\n");
	return (0);
}
