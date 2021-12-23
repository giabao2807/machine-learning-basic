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
    num = [2, 3, 5]
    rem = [3, 5, 7]
    k = len(num)
    print("x is", findMinX(num, rem, k))
