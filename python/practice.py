import numpy as np
import time
import random 

def Compute_Time(func):
    def inner1(*args, **kwargs):
        start_time = time.time()
        print(f"The result from {func.__name__} is {func(*args, **kwargs)}")
        end_time = time.time()
        print("Total time taken in : ", end_time - start_time)
    return inner1

@Compute_Time
def Product(n1, n2):
    res = 1
    for i in range(min(len(n1),len(n2))):
        res+=n1[i]*n2[i]
    return res



if __name__ == '__main__':
    print("Example of decortor wrappers:")
    #print(random.sample(range(10,50),5))
    Product(random.sample(range(10,50),5),random.sample(range(10,50),5))