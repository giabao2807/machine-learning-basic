import numpy as np


def CholeL(A):
    check = all(isinstance(ele, object) for ele in A)
    if not (check == True and len(A.shape) == 2 and A.shape[0] == A.shape[1]):
        return None
    L = np.zeros_like(A, dtype=np.int16)
    for i in range(0, A.shape[0]):
        for j in range(0, i+1):
            sum = 0
            for k in range(0, j):
                sum += L[i][k] * L[j][k]
            if (i == j):
                L[j][j] = np.sqrt(A[j][j]-sum)
            else:
                L[i][j] = (1.0 / L[j][j] * (A[i][j] - sum))
    return L


def CholeU(A):
    L = np.zeros_like(A, dtype=np.int16)
    for i in range(0, A.shape[0]):
        for j in range(0, A.shape[0]):
            L[i][j] = A[j][i]
    return L


if __name__ == "__main__":
    A = np.array([[2, 1, 0], [1, 2, 1], [0, 1, 2]])
    L = CholeL(A)
    U = CholeU(L)
    print("Ma tran A:")
    print(A)
    print("ma tran duoi L:")
    print(L)
    print("ma tran tren U:")
    print(U)
