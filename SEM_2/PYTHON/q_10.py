import math
odd = lambda x:True if x%2 != 0 else False 

limit = int(input("Enter the range: "))
squres = []
for i in range(1, limit + 1):
    squres.append(int(math.pow(i,2)))

oddSqures = []
oddSqures = filter(odd, squres)
for i in oddSqures:
    print(i)