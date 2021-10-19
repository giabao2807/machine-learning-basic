import numpy as np


def RREF(A):
    """\
    Reduced row echelon form
    """
    A = np.array(A, dtype=np.float64)
    B = list()

    pivot = 0
    for i in range(A.shape[1]):
        if len(B) == A.shape[1]-1:
            if np.isclose(A[i, i], 0):
                A[i, i] = 0
                break
        if np.isclose(A[pivot, i], 0):
            for j in range(pivot+1, A.shape[0]):
                if not np.isclose(A[j, i], 0):
                    A[[pivot, j]] = A[[j, i]]
                    break
                else:
                    A[j, i] = 0

        if not np.isclose(A[pivot, i], 0):
            A[pivot] = A[pivot]/A[pivot, i]
            for j in range(0, A.shape[0]):
                if j != pivot and A[j, i] != 0:
                    A[j] = A[j] - A[j, i]*A[pivot]
            pivot += 1
            B.append(i)
            if pivot == A.shape[0]:
                break
        else:
            A[pivot, i] == 0
    return (A, np.array(B))


def null_space(A):
    """\
    find the null space and the nullity
    """

    A = np.array(A, dtype=np.float64)
    A, x = RREF(A)

    if A.shape[1] == x.size:
        return np.zeros((A.shape[1], A.shape[1]))

    result = np.zeros((A.shape[1], A.shape[1]-x.size))
    pivot = 0
    for xi in range(A.shape[1]):
        if (x == xi).any():
            continue
        for j in range(A.shape[0]):
            for k in range(A.shape[1]):
                if k != xi and A[j, k] == 1:
                    result[k, pivot] = -A[k, xi]
                    break
        result[xi, pivot] = 1
        pivot += 1
    return result


def find_eigenvectors(A):
    B = np.empty_like(A)
    for i in range(B.shape[1]):
        B[:, i] = A[:, i]/np.linalg.norm(A[:, i], 2)
    return B


def my_svd(A):
    A = np.array(A, dtype=np.float64)
    # mutiply the transposed matrix with initial
    A_T = np.transpose(A)
    Y = A @ A_T
    eigenvalues = np.sort(np.linalg.eigvals(Y))[::-1]
    eigenvectors = np.zeros_like(Y)
    for i in range(eigenvalues.size):
        if not np.isclose(eigenvalues[i], 0):
            temp = Y.copy()
            temp -= eigenvalues[i]*np.identity(Y.shape[0])
            n_s = null_space(temp)
            eigenvectors[:, [i]] = find_eigenvectors(n_s)
        else:
            n_s = null_space(Y)
            eigenvectors[:, i:] = find_eigenvectors(n_s)
            break
    U = eigenvectors
    D = np.zeros_like(A)
    eigenvalues = eigenvalues[np.isclose(eigenvalues, 0) == False]
    D[range(eigenvalues.size), range(eigenvalues.size)] = np.sqrt(eigenvalues)
    V = np.zeros((A.shape[1], A.shape[1]))
    for i in range(eigenvalues.size):
        V[:, [i]] = 1/D[i, i]*A_T@U[:, [i]]

    while i < V.shape[0]-1:
        n_s = null_space(np.transpose(V))
        V[:, i+1] = find_eigenvectors(n_s)[:, 0]
        i += 1
    return (U, D, V)


if __name__ == '__main__':
    A = [[3, 1, 2],
         [1, 3, 1],
         [2, 1, 3]]
    U, D, V = my_svd(A)

    print('Matrix A: \n %s \n' % A)
    
    print('Matrix U: \n %s \n' % U)
    print('Matrix D: \n %s \n' % D)
    print('Matrix V: \n %s \n' % V)
