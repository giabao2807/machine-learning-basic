from numpy import sign
import Prime as pr
import numpy as np


def InversesOfModularArithmetic(n, m):
    n = n % m
    my_list = []
    while (n != 1):
        quotient, remainder = np.divmod(m, n)
        my_list.append((m, quotient))
        m = n
        n = remainder
    A, B = 0, 1
    my_list.reverse()
    for temp, quotient in my_list:
        n = m
        m = temp
        B_new = A + B*-quotient
        A = B
        B = B_new
    return m + B if B != 1 else 1


def China(l):
    l = np.array(l, dtype=np.int64)
    M = np.prod(l[:, 1])
    Mn = M//l[:, 1]
    yn = np.array([InversesOfModularArithmetic(o, p) for o, p in np.hstack(
        (Mn.reshape((Mn.size, 1)), l[:, [1]]))], dtype=np.int64)
    return np.sum(l[:, 0]*Mn*yn) % M


def main():
    print(China([(2, 3), (3, 5), (4, 11)]))


if __name__ == 'main':
    main()
