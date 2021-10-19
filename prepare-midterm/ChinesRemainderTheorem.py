def findMinX(num, rem, k):
    x = 1  # Initialize result

    # As per the Chinise remainder
    # theorem, this loop will
    # always break.
    while(True):
        j = 0
        while(j < k):
            if (x % num[j] != rem[j]):
                break
            j += 1

        if (j == k):
            return x
        x += 1


if __name__ == "__main__":
    # Driver Code
    num = [3, 4, 5]
    rem = [2, 3, 1]
    k = len(num)
    print("x is", findMinX(num, rem, k))

    # This code is contributed by mits
