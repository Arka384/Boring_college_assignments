import math

def isPrime(n):
    for i in range(2, n):
        if(n % i == 0):
            return 0
    return 1

def getPrimes(limit):
    for i in range(2, limit+1):
        if(isPrime(i)):
            yield i

limit=int(input("Enter the max limit: "))
for i in getPrimes(limit):
    print(i)