import time
import math

def getGPTerms(a,q):
    x = 0
    while(True):
        temp = a*(math.pow(x, q)) 
        if (temp > 100000):
            return False
        yield temp
        x += 1
    
start = time.time()
a = int(input("Enter the initial term :"))
q = int(input("Enter the common difference :"))

c = 0
n = int(input("Enter limit :"))

checkpoint = time.time()
terms = getGPTerms(a,q)
for i in terms:
    if i and c <= n:
        print(i)
        c += 1
end = time.time()

print("Time taken for execution is: ",(end-start))
print("Time taken in loop :", (end-checkpoint))
