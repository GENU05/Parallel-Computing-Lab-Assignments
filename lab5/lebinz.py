from time import time
def pi():
    N = 10**6
    p = 0.0 
    start = time()
    for i in range(1,N):
        if i %2 == 0:
            p = p - 1/(2*i-1)
        else:
            p = p + (1/(2*i-1))
        # print(p)
    p = 4 * p
    print("Time Taken : " , time()-start)
    print("Pi : ",p)

if __name__ == '__main__':
    pi()