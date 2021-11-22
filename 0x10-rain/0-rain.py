#!/usr/bin/python3

"""
Rain program
"""


def rain(walls):
    
    result = 0
    if len(walls) == 0:
        return 0
    for i in range(1, len(walls) - 1):
        a = walls[i]
        b = walls[i]
        for j in range(i):
            a = max(a, walls[j])
        for j in range(i + 1, len(walls)):
            b = max(b, walls[j])
        result = result + (min(a, b) - walls[i])
    return result