def SieveOfEratosthenes(n):
    prime = [True for i in range(n + 1)]
    p = 2
    while (p * p <= n):

        # If prime[p] is not changed, then it is a prime
        if (prime[p] == True):

            # Update all multiples of p
            for i in range(p ** 2, n + 1, p):
                prime[i] = False
        p += 1
    prime[0] = False
    prime[1] = False
    # in ra so nguyen to
    for p in range(n + 1):
        if prime[p]:
            print(p),


if __name__ == '__main__':
    n = 100
    print("So nguyen to be hon ", n)
    SieveOfEratosthenes(n)
