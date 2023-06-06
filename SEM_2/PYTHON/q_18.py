
def find_K_Largest(numList, k):
    items = []
    items = numList.copy()
    while k > 0:
        m = max(items)
        yield m
        items.remove(m)
        k -= 1


listSize = int(input("Enter the size of the list: "))
numList = []
print("Enter elements: ")
for i in range(1, listSize + 1):
    numList.append(int(input("")))
k = int(input("Enter k: "))

maxList = iter(find_K_Largest(numList, k))
print("Max K'th elemets are: ")
for i in range(k):
    print(maxList.__next__(), end=", ")