#!/usr/bin/python3
""" Prime Game """


def SieveOfEratosthenes(nums):
    """ Using Sieve Of Eratos thenes to get prime numbers"""
    n = max(nums)
    if n < 1:
        return None
    prime_nums = [0] * len(nums)
    prime = [True for _ in range(n+1)]
    p = 2
    while(p * p <= n):
        if prime[p]:
            for i in range(p * 2, n + 1, p):
                prime[i] = False
        p += 1
    for i in range(len(nums)):
        cnt = 0
        for j in range(nums[i] + 1):
            if (prime[j]):
                cnt += 1
        prime_nums[i] = cnt
    return prime_nums


def isWinner(x, nums):
    """ Prime game winner """
    if x <= 0 or nums is None or min(nums) < 0:
        return None
    prime_cnt = SieveOfEratosthenes(nums)
    if prime_cnt is None:
        return None
    loses = 0
    for i in prime_cnt:
        if i % 2 == 0:
            loses += 1
    if x < 2 * loses:
        return "Ben"
    if x == 2 * loses:
        return None
    return "Maria"
