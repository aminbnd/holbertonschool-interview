#!/usr/bin/python3
""" Pascal triangle """


def factorial(n):
    """ Function that computes the factorial of an integer n"""
    if n <= 1:
        return 1
    else:
        return n * factorial(n - 1)


def binomialCoefficient(n, k):
    """Function that computes the binomial coefficient"""
    return (factorial(n) // (factorial(k) * factorial(n - k)))


def pascal_triangle(n):
    """
    Function that returns a list of lists of integers representing the
    Pascal’s triangle of n
    """
    if n <= 0:
        return []
    triangle = []
    for i in range(n):
        row = []
        for j in range(i + 1):
            row.append(binomialCoefficient(i, j))
        triangle.append(row)
    return triangle
