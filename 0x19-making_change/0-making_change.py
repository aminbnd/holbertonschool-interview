#!/usr/bin/python3
"""
"Make Change" Module
"""


def makeChange(coins, total):
    """
    determine the fewest number of coins needed to meet a given amount total
    Parameters:
        coins: list of a the values of the coins
        total: int (total amount to be met)
    Return:
        If total is 0 or less, return 0
        If total cannot be met by any number of coins you have, return -1
        else, fewest number of coins needed to meet total
    """
    if total <= 0:
        return 0
    if not coins or coins is None:
        return -1
    coins.sort(reverse=True)
    coinValue = 0
    coinNumber = 0
    i = 0
    while i < len(coins):
        if(coinValue + coins[i] > total):
            i += 1
        else:
            coinValue += coins[i]
            coinNumber += 1
    if coinValue == total:
        return (coinNumber)
    if coinValue == 0:
        return(-1)
    return (-1)
