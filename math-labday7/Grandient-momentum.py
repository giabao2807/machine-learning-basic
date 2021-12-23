import numpy as np

import matplotlib.pyplot as plt


def grad(x):  # f'(x)

    return 2*(np.exp(x) + 3*x - 10)*(np.exp(x)+3) + 2*x


def cost(x):  # f(x)
    return (np.exp(x) + 3*x-10)**2 + x**2


def GD_momentum(theta_init, alpha=0.1, beta=0.9, Loop=1000):

    theta = [theta_init]

    v_old = np.zeros_like(theta_init)

    for it in range(Loop):

        v_new = beta*v_old + alpha*grad(theta[-1])  # vt

        theta_new = theta[-1] - v_new

        theta.append(theta_new)

        v_old = v_new

    return (theta, it)




if __name__ == '__main__':

    X = np.linspace(-5, 5, 200)

    y = cost(X)

    plt.plot(X.T, y.T, 'r.')

    plt.axis([-5, 5, -10, 15])

    (x2, it2) = GD_momentum(1.5, 0.1)

    print('Momentum_Solution x1 = %f, cost = %f, obtained after %d iterations' % (
        x2[-1], cost(x2[-1]), it2))

    plt.plot(x2[-1], cost(x2[-1]), 'r X')

    plt.show()
