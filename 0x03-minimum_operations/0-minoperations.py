"""
Minimum Operations
"""

def isPremium(n):
    """ Checks if a number is premium """
    for i in range(2,n):
        if n % i == 0:
            return False
    return True

def minOperations(n):
    """ defines minimum operations"""
    if n < 2:
        return 0
    i = 2
    opp = 0
    while(n != 1):
        if (isPremium(i)):
            if (n % i == 0):
                n = n / i
                opp = opp + i
            else:
                i += 1
        else:
            i += 1
    return opp