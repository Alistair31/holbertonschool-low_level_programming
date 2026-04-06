#include "main.h"
/**
 * is_prime_number - function that check input integer is a prime number
 * @n: numbers to check if it is a prime number
 * Return: 1 for prime number, 0 for other
 */
int is_prime_number(int n)
{
	int i;

	i = 1;
	if (n % 1 == 0 && n % i == 0 && i <= n)
	{
		i++;
		
		return (1);
	}
	return (0);
}

int main(void)
{
	is_prime_number(res);
}
