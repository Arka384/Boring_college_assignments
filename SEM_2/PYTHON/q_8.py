foo = lambda value: True if value%5 == 0 else False

numList = list()
for i in range(51):
    if foo(i):
        numList.append(i)

print("Numbers multiple of 5 are: ")
for i in numList:
    print(i, end=", ")
