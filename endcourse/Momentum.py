import numpy as np

import matplotlib.pyplot as plt
from matplotlib import animation


def grad(x):  # f'(x)

    return 2*(np.exp(x) + 3*x - 10)*(np.exp(x)+3) + 2*x


def cost(x):  # f(x)
    return (np.exp(x) + 3*x-10)**2 + x**2


def gradient_descent_with_momentum(start, learn_rate, n_iter=1000, gamma=0.9, tolerance=1e-5):

    w = [start]
    v_old = np.zeros_like(start)
    for i in range(n_iter):
        gr = grad(w[-1])
        if np.linalg.norm(gr)/np.array(start).size < tolerance:
            break
        v_old = gamma*v_old+learn_rate*gr
        w.append(w[-1]-v_old)
    return w


if __name__ == "__main__":
    fig, axes = plt.subplots(1, 2, figsize=(16, 9))
    w1, w2 = ([], [])

    def animate(i):
        global w1
        if len(w1) < 2:
            w1 = gradient_descent_with_momentum(1.5, 0.1)
        if len(w1) < 2:
            return
        xn = np.linspace(-6, 6, 100)
        fx = cost(xn)
        axes[0].clear()
        axes[0].plot(xn, fx)
        axes[0].scatter([w1[0]], cost(w1[0]))
        axes[0].scatter([w1[1]], cost(w1[1]))
        plt.plot([w1[0], w1[1]], [cost(w1[0]), cost(w1[1])])
        w1.pop(0)
        global w2
        if len(w2) < 2:
            w2 = gradient_descent_with_momentum(1.5, 0.1)
        xn = np.linspace(-6, 6, 100)
        fx = cost(xn)
        axes[1].clear()
        axes[1].plot(xn, fx)
        axes[1].scatter([w2[0]], cost(w2[0]))
        axes[1].scatter([w2[1]], cost(w2[1]))
        plt.plot([w2[0], w2[1]], [cost(w2[0]), cost(w2[1])])

        w2.pop(0)

    ani = animation.FuncAnimation(fig, animate, interval=1000)
    plt.show()
