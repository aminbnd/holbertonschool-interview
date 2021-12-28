#include "menger.h"

/**
 * menger - function that draws 2D Menger Sponge
 *
 * @level: int (the level of the Menger Sponge)
 */

void menger(int level)
{
	int i, j;
	int size = pow(3, level);

	if (level < 0)
		return;

	for (i = 0; i < size; i++)
	{
		for (j = 0; j < size; j++)
		{
			if (printShape(i, j))
				printf("#");
			else
			{
				printf(" ");
			}
		}
		printf("\n");
	}
}

/**
 * printShape - To decide eather print "#" or not
 *
 * @i: integer (iterator)
 * @j: integer (iterator)
 * Return: Bollean (true if we shoud print the "#", false otherwise)
 */
bool printShape(int i, int j)
{
	while (i && j)
	{
		if (i % 3 == 1 && j % 3 == 1)
			return (false);
		i = i / 3;
		j = j / 3;
	}
	return (true);
}
