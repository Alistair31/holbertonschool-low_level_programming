#include "main.h"
/**
 * _abs - Entry point
 * @anb: number that will be checked
 * Return: absolute value
 */

int _abs(int anb)

{
	if (anb < 0)
	{
		int anbm;

		anbm = anb * -1;
		return (anbm);
	}
	return (anb);
}
