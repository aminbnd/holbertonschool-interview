#!/usr/bin/python3
""" Pascal triangle """


def factorial(n):
    """ Function that computes the factorial of an integer n"""
    result = 1
    if n > 1:
        for i in range(1, n + 1):
            result *= i
    return result


def binomialCoefficient(n, k):
    """Function that computes the binomial coefficient"""
    if (k > n - k):
        k = n -k
    return int(factorial(n) / (factorial(k) * factorial(n - k)))


def pascal_triangle(n):
    """
    Function that returns a list of lists of integers representing the
    Pascal’s triangle of n
    """
    triangle = []
    if n <= 0:
        return triangle
    for i in range(n):
        row = []
        for j in range(i + 1):
            row.append(binomialCoefficient(i, j))
        triangle.append(row)
    return triangle
