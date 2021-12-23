import numpy as np
from matplotlib import pyplot as plt


def convex_hull(points):
    temp_P = np.unique(points, axis=0)
    dtype = [('x', 'f8'), ('y', 'f8')]
    smallest_index = np.argsort(
        np.array([(_[0], _[1]) for _ in temp_P], dtype=dtype), order=('y', 'x'))[0]

    P = temp_P - temp_P[smallest_index]
    H = [P[smallest_index]]
    P = np.vstack((P[:smallest_index], P[smallest_index+1:]))
    lengths = np.linalg.norm(P, axis=1)
    angles = np.arccos(P[:, 0]/lengths)
    sorted_angle_indices = np.argsort(angles)
    for i in sorted_angle_indices:
        H.append(P[i])
        while len(H) >= 3:

            u = H[-2]-H[-3]
            v = H[-1]-H[-2]
            if np.cross(u, v) < 0:
                H.pop(-2)
            elif np.cross(u, v) == 0:
                if np.linalg.norm(H[-1]-H[-3]) < np.linalg.norm(H[-2]-H[-3]):
                    H.pop(-1)
                else:
                    H.pop(-2)
            else:
                break
    while len(H) >= 3:
        u = H[-1]-H[-2]
        v = H[0] - H[-1]
        if np.cross(u, v) < 0:
            H.pop(-1)
        else:
            break
    H = np.array(H)
    H = H+temp_P[smallest_index]
    return H


points = np.array([[3, 4],
                  [5, 3],
                  [6, 5],
                  [7, 6],
                  [8, 7],
                  [4, 9],
                  [3, 8],
                  [4, 8],
                  [7, 10],
                  [7, 4]])
rs = convex_hull(points)

print("Day bao loi cuoi cung gom: ")
print(rs)
