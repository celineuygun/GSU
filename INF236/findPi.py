import matplotlib.pyplot as plt
import random
import math
random.seed(42)

def newPoint():
    """
    return:
        2 boyutlu veri üret. 
        Her bir boyut $[-1, 1]$ aralığında olsun.
    """
    x = 2 * random.random() - 1
    y = 2 * random.random() - 1
    return x,y

def isInCircle(data):
    """
    parametre:
        veri 2 boyutlu 
        Her bir boyut $[-1, 1]$ aralığında 
    
    """
    x, y = data
    distance = math.sqrt(x**2 + y**2)
    if distance <= 1:
        return True
    return False

def calcPi(n = 10000):
    """
    Empirik sekilde pi'yi hesapla
    """
    datas = [newPoint() for i in range(n)]
    d = 0
    for data in datas:
        if isInCircle(data):
            d += 1
    return 4 * d / n


def mistake(n = 100, k = 20):
    pi = 0
    for i in range(k):
        pi += calcPi(n)
    pi = pi / k
    return abs(math.pi - pi)

n = int(input("Enter the number of the data which going to be used calculating pi: ")) 
pi = calcPi(n)
print(f"pi = {pi}")

ns = [i * 10 for i in range(1, 300)]
mistakes = [mistake(n = n, k = 20) for n in ns]

plt.plot(ns, mistakes)
plt.xlabel('n')
plt.ylabel('Emprik Hata')
plt.grid()
plt.show()