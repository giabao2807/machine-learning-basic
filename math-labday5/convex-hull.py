import random
import numpy as np


def RightTurn(p1, p2, p3):
    if (p3[1]-p1[1])*(p2[0]-p1[0]) >= (p2[1]-p1[1])*(p3[0]-p1[0]):
        return False
    return True


def convexHull(P):
    P.sort()
    L_upper = [P[0], P[1]]
    for i in range(2, len(P)):
        L_upper.append(P[i])
        while len(L_upper) > 2 and not RightTurn(L_upper[-1], L_upper[-2], L_upper[-3]):
            del L_upper[-2]
    L_lower = [P[-1], P[-2]]
    for i in range(len(P)-3, -1, -1):
        L_lower.append(P[i])
        while len(L_lower) > 2 and not RightTurn(L_lower[-1], L_lower[-2], L_lower[-3]):
            del L_lower[-2]
    del L_lower[0]
    del L_lower[-1]
    L = L_upper + L_lower		# Dãy bao bọc cuối cùng
    return np.array(L)


if __name__ == '__main__':
    points = np.array([[1, 2],
                       [2, 4],
                       [3, 5],
                       [4, 3],
                       [5, 4],
                       [6, 1],
                       [7, 3]])
    c = convexHull(points)
    print(c)
