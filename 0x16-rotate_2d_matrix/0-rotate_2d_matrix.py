#!/usr/bin/python3
"""
Module that contains a methd
Rotating a matrix
"""

def rotate_2d_matrix(matrix):
    """
    function that rotates a matrix
    90° degrees clockwise
    """
    n =len(matrix[0])
    for i in range(0, n):
        for j in range(i, n):
            temp = matrix[i][j]
            matrix[i][j] = matrix[j][i]
            matrix[j][i] = temp
    for j in range(n):
        matrix[j].reverse()