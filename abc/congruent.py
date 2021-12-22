from numpy import sign
import prime as pr
import numpy as np


def a_to_the_power_m_mod_n(a, m, n):
    if m == 0:
        return 1 % n
    elif m % 2 == 0:
        return a_to_the_power_m_mod_n(a, m//2, n)**2 % n
    else:
        return a % n * a_to_the_power_m_mod_n(a, m-1, n) % n


def devisibility_sign(n):
    i = 0
    sign = []
    while (r := a_to_the_power_m_mod_n(10, i, n)) not in sign:
        if r <= n//2:
            sign.append(r)
        else:
            sign.append(r-n)
        i += 1
    sign.reverse()
    return sign


def InversesOfModularArithmetic(n, m):

    n = n % m
    my_list = []
    while (n != 1):
        if n == 0:
            raise ValueError
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


def solve_diophantine(a, b, c):
    if a>b:
        rs = solve_diophantine(b,a,c)
        return None if rs==None else {'x':rs['y'],'y':rs['x']}
        
    gcd = pr.GreatestCommonDivisor(a,b)
    if c%gcd != 0:
        return None
   
    a = a//gcd
    b = b//gcd
    m,n = b,a
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

    k,l = B,A
    

    return {'x':f'{c//gcd*k} + r*{b}', 'y':f'{c//gcd*l} - r*{a}'}


