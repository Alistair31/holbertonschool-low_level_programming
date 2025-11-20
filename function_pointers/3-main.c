#include <stdio.h>
#include <stdlib.h>
#include "3-calc.h"
/**
 * main - check the code
 * @argc: Number of arguments
 * @argv: Array of argument strings
 * Return: 0 on success, exits with error codes if failure
 */

int main(int argc, char *argv[])
{
	int nb1;
	int nb2;
	int (*op)(int, int);
	char *endline = argv[2];

	if (argc != 4)
	{
		printf("Error\n");
		exit(98);
	}
	nb1 = atoi(argv[1]);
	nb2 = atoi(argv[3]);

	op = get_op_func(argv[2]);
	if (op == NULL || endline[1] != '\0')
	{
		printf("Error\n");
		exit(99);
	}
	if ((nb2 == 0) && (argv[2][0] == '/' || argv[2][0] == '%'))
	{
		printf("Error\n");
		exit(100);
	}
	printf("%d\n", op(nb1, nb2));
	return (0);
}
