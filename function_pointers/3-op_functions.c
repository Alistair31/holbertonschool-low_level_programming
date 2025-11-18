#include <stdio.h>
#include "3-calc.h"
/**
 * op_add - sum operation
 * @a: first number
 * @b: second number
 * Return: result of the operation
 */
int op_add(int a, int b)
{
	return (a + b);
}

/**
 * op_sub - difference operation
 * @a: first number
 * @b: second number
 * Return: result of the operation
 */
int op_sub(int a, int b)
{
	return (a - b);
}

/**
 * op_mul - product operation
 * @a: first number
 * @b: second number
 * Return: result of the operation
 */
int op_mul(int a, int b)
{
	return (a * b);
}

/**
 * op_div - division operation
 * @a: first number
 * @b: second number
 * Return: result of the operation
 */
int op_div(int a, int b)
{
	return (a / b);
}

/**
 * op_mod - modulo operation
 * @a: first number
 * @b: second number
 * Return: result of the operation
 */
int op_mod(int a, int b)
{
	return (a % b);
}
