from itertools import compress

num_list = [1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20]
list_Even = [True if x%2 == 0 else False for x in num_list]
list_Odd = [True if x%2 != 0 else False for x in num_list]

print("Even numbers are: ")
for i in compress(num_list, list_Even):
    print(i, end=", ")
print("\nOdd numbers are: ")
for i in compress(num_list, list_Odd):
    print(i, end=", ")
