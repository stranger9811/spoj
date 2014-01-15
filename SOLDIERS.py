x=int(raw_input())
for i in range(0,x):
    y=raw_input()
    y=y.split(" ")
    a=int(y[0])
    b=int(y[1])
    if a%2==0:
        p=a/2
    else:
        p=(a+1)/2
    if b%2==0:
        q=b/2
    else:
        q=(b+1)/2
    answer1=a*q
    answer2=b*p
    if answer1>answer2:
        print answer1
    else:
        print answer2


