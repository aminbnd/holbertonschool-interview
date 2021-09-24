#include "sandpiles.h"


/**
 * print_grid - Prints a grid
 * @grid: sandpile
 * Return: void
 */
void print_sandpile(int grid[3][3])
{
	int i, j;

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			if (j)
				printf(" ");
			printf("%d", grid[i][j]);
		}
	printf("\n");
	}
}

/**
 * check_sandpiles -  Checks is sandpiles are stable
 * @grid: sandpile to check
 * Return: 1 if stable 0 otherwise
 */
int check_sandpiles(int grid[3][3])
{
	int i, j;

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			if (grid[i][j] && grid[i][j] > 3)
				return (0);
		}
	}
	return (1);
}

/**
 * compute_sandpiles - Makkes simple addition of two grids of integers
 * @grid1: first grid
 * @grid2: second grid
 */

void compute_sandpiles(int (*grid1)[3], int grid2[3][3])
{
	int i, j;

	i = 0;
	while (i < 3)
	{
		for (j = 0; j < 3; j++)
		{
			(*grid1)[j] +=  grid2[i][j];
		}
		(*grid1++);
		i++; /* To be checked after running the code */
	}
}

/**
 * toppling_sandpiles - topples the sandpiles
 * @grid1: old grid values are replaced with the new one
 * @grid2: old grid values
 * Return: void
 */
void toppling_sandpiles(int(*grid1)[3], int grid2[3][3])
{
	int i, j;

	i = 0;
	while (i < 3)
	{
		j = 0;
		while (j < 3)
		{
			if (grid2[i][j] > 3)
				(*grid1)[j] -= 4;
			if (j - 1 >= 0)
			{
				if (grid2[i][j - 1] > 3)
					(*grid1)[j] += 1;
			}
			if (j + 1 < 3)
			{
				if (grid2[i][j + 1] > 3)
					(*grid1)[j] += 1;
			}
			if (i - 1 >= 0)
			{
				if (grid2[i - 1][j] > 3)
					(*grid1)[j] += 1;
			}
			if (i + 1 < 3)
			{
				if (grid2[i + 1][j] > 3)
					(*grid1)[j] += 1;
			}
			j++;
		}
		(*grid1++);
		i++;
	}
}

/**
 * sandpiles_sum - computes the sum of two sandpiles
 * @grid1: first sandpile
 * @grid2: second sandpile
 * Return: void
 */
void sandpiles_sum(int grid1[3][3], int grid2[3][3])
{
	int check_sand = -1;
	int i, j;

	compute_sandpiles(grid1, grid2);
	while (check_sand != 1)
	{
		for (i = 0; i < 3; i++)
		{
			for (j = 0; j < 3; j++)
			{
				grid2[i][j] = grid1[i][j];
			}
		}
		/** If the grid is unstable **/
		check_sand = check_sandpiles(grid1);
		if (check_sand == 0)
		{
			printf("=\n");
			print_sandpile(grid1);
		}
		else
			return;
		toppling_sandpiles(grid1, grid2);
	}
}
