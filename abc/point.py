import numpy as np
from matplotlib import pyplot as plt


def pair_distance(pair_1, pair_2):
    return np.sqrt(np.sum((pair_1-pair_2)**2))


def _raw_recursive(pairs):
    if pairs.shape[0] <= 3:
        x_i, y_i, distance = 0, 1, pair_distance(pairs[0], pairs[1])
        for i in range(0, pairs.shape[0]-1):
            for j in range(i+1, pairs.shape[0]):
                if (temp := pair_distance(pairs[i], pairs[j])) < distance:
                    x_i, y_i, distance = i, j, temp
        return x_i, y_i, distance

    mid_i = pairs.shape[0]//2
    be_x_i, be_y_i, be_dis = _raw_recursive(pairs[:mid_i])
    af_x_i, af_y_i, af_dis = _raw_recursive(pairs[mid_i:])
    x_i, y_i, distance = (be_x_i, be_y_i, be_dis) if be_dis < af_dis else (
        af_x_i+mid_i, af_y_i+mid_i, af_dis)
    left = mid_i-1
    right = mid_i+1
    while left > 0 and pairs[mid_i, 0]-pairs[left, 0] < distance:
        left -= 1
    while right < pairs.shape[0] and pairs[right, 0]-pairs[mid_i, 0] < distance:
        right += 1
    for i in range(left, mid_i):
        for j in range(mid_i, right):
            if (temp := pair_distance(pairs[i], pairs[j])) < distance:
                x_i, y_i, distance = i, j, temp
    return x_i, y_i, distance


def closest_pair(pairs):
    pairs = np.array(pairs)
    # sắp xếp theo chiều tăng của x
    for i in range(pairs.shape[0]-1):
        for j in range(i, pairs.shape[0]):
            if pairs[i, 0] > pairs[j, 0]:
                # swap 2 diem
                pairs[[i, j]] = pairs[[j, i]]
    x_i, y_i, distance = _raw_recursive(pairs)
    return pairs[[x_i, y_i]], distance


x = np.random.randint(-100, 100, 20)
y = np.random.randint(-100, 100, 20)
plt.scatter(x, y)

pairs = np.hstack((x.reshape(x.size, 1), y.reshape(y.size, 1)))

pair, dis = closest_pair(pairs)
print(pair)
plt.scatter(pair[:, 0], pair[:, 1])

plt.show()
