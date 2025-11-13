#include <stdio.h>
#include <stdlib.h>
#include "main.h"
/**
 * free_grid - free a 2D grid
 * @grid: grid to free
 * @height: number of lines in the grid
 * Return: void
 */
void free_grid(int **grid, int height)
{
	int i;

	for (i = 0; i < height; i++)
	{
		free(grid[i]);
	}
	free(grid);
}
