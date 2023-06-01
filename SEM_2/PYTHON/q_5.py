
def fibo(count):
    a,b,c=0,1,0
    while count>0:
        yield c
        a=b
        b=c
        c=a+b

fiboSeries = iter(fibo(7));
for i in range(7):
    print(fiboSeries.__next__())