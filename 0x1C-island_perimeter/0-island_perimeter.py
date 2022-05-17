#!/usr/bin/python3
""" Island Perimeter"""


def island_perimeter(grid):
    """ Function that returns the perimeter of an Island"""

    perim = 0
    for row in range(len(grid)):
        for col in range(len(grid[row])):
            if grid[row][col] == 1:
                perim += 4
                if row > 0 and grid[row - 1][col]:
                    perim -= 1
                if row < (len(grid) - 1) and grid[row + 1][col]:
                    perim -= 1
                if col > 0 and grid[row][col - 1]:
                    perim -= 1
                if col < (len(grid[row]) - 1) and grid[row][col + 1]:
                    perim -= 1
    return perim
