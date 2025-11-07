#include <stdio.h>
/**
 * main - check the code
 * @argc: number of argument
 * @argv: array of argument
 * Return: 0 (success)
 */
int main(int argc, char **argv)
{
	int i;

	i = -1;
	for (i = 0; i < argc; i++)
	{
	printf("%s\n", argv[i]);
	}
	return (0);
}
