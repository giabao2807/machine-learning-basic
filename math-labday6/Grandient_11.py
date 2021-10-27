from __future__ import  division,print_function,unicode_literals
 
import matplotlib.pyplot as plt
import numpy as np
 
def cost(x):
    x = np.array(x,dtype=np.float64)
    return x**2 + 5*np.sin(x)
def  grad(x):
    return 2*x + 5*np.cos(x)
 
def myGD1(alpha,x0,gra = 1e-3 ,loop=1000):
    x = [x0]
    for i in range(loop):
        x_new = x[-1] - alpha*grad(x[-1])
        if abs(grad(x_new)) < gra:
            break
        x.append(x_new)
    return x,i
 
if __name__ == '__main__':
    x = np.linspace(-5,5,100)
    y = cost(x)
    fig,axs = plt.subplots(4,1,figsize=(5,20))
 
    x1,it1 = myGD1(.1,10)
    x2,it2 = myGD1(.1,-10)
    x3,it3 = myGD1(.4,10)
    x4,it4 = myGD1(.4,-10)
 
    axs[0].plot(x,y,linestyle='-',linewidth=.5)
    axs[0].scatter(x1,cost(x1),color="red",s=4)
    axs[1].plot(x,y,linestyle='-',linewidth=.5)
    axs[1].scatter(x2,cost(x2),color="red",s=4)
    axs[2].plot(x,y,linestyle='-',linewidth=.5)
    axs[2].scatter(x3,cost(x3),color="red",s=4)
    axs[3].plot(x,y,linestyle='-',linewidth=.5)
    axs[3].scatter(x4,cost(x4),color="red",s=4)
 
 
    axs[0].scatter([x1[-1]],[cost(x1[-1])],color="black",s=10)
    axs[1].scatter([x2[-1]],[cost(x2[-1])],color="black",s=10)
    axs[2].scatter([x3[-1]],[cost(x3[-1])],color="black",s=10)
    axs[3].scatter([x4[-1]],[cost(x4[-1])],color="black",s=10)
 
    plt.show()