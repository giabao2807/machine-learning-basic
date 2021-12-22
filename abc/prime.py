import numpy as np


def is_prime(n):
    if n > 1 and n == int(n):
        for i in range(2, int(np.sqrt(n))+1):
            if n % i == 0:
                return False
        return True
    return False


def is_composite(n):
    if n > 1 and n == int(n):
        for i in range(2, int(np.sqrt(n))+1):
            if n % i == 0:
                return True
    return False


def PrimeFactorization(n):
    if n <= 1 or (A := int(n)) != n:
        raise ValueError
    factors = []
    i = 2
    while A > 1 and i <= n:
        power = 0
        while A > 1 and A % i == 0:
            power += 1
            A = A//i
        if power > 0:
            factors.append((i, power))
        i += 1
    return factors


def NumberOfDivisors(n):
    if n <= 1 or (A := int(n)) != n:
        raise ValueError
    factors = np.array(PrimeFactorization(n), dtype=np.int64)
    return np.prod(factors[:, 1]+1)


def SumOfDivisors(n):
    factors = np.array(PrimeFactorization(n), dtype=np.int64)
    return np.prod(np.fromiter(((x[0]**(x[1]+1)-1)/(x[0]-1) for x in factors), dtype=np.int64))


def ProductOfDivisors(n):
    return n**(NumberOfDivisors(n)/2)


def FindPerfectNumber(n):
    rs = []
    for i in range(2, n+1):
        s = 1
        for j in range(2, i):
            if i % j == 0:
                s += j
        if s == i:
            rs.append(i)

    return rs


def SieveOfEratosthenes(n):
    indexs = np.arange(2, n+1)
    nums = np.ones_like(indexs, dtype=bool)
    for i in range(indexs.size):
        if nums[i] == True:
            nums[i+indexs[i]::indexs[i]] = False
    return indexs[nums]


def GreatestCommonDivisor(a, b):
    if a < b:
        return GreatestCommonDivisor(b, a)
    if (r := a % b) == 0:
        return b
    return GreatestCommonDivisor(b, r)


def LeastCommonMutiple(a, b):
    return a*b//GreatestCommonDivisor(a, b)


def EulerTotientFunction(n):
    """\Euler phi function
    """
    factors = PrimeFactorization(n)
    prod = n
    for prime, power in factors:
        prod *= (1-1/prime)
    return int(prod)
