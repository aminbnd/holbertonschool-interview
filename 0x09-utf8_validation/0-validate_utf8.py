#!/usr/bin/python3
"""
This module contains a method that validates
UTF-8 encoding
"""


def validUTF8(data):
    """
    validateUTF8: Method
        args: data (string to check)
        return: true if data is UTF-8 encoding
                false otherwise
    """
    totalBytes = 0
    first = 1 << 7
    second = 1 << 6
    for i in data:
        other = 1 << 7
        if totalBytes == 0:
            while other & i:
                totalBytes += 1
                other = other >> 1
            if totalBytes == 0:
                continue
            if totalBytes == 1 or totalBytes > 4:
                return False
        else:
            if not (i & first and not (i & second)):
                return False
        totalBytes -= 1
    return totalBytes == 0
