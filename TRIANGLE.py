import math
x=int(raw_input())
for i in range(0,x):
    y=raw_input()
    y=y.split(" ")
    a=int(y[0])
    b=int(y[1])
    c=int(y[2])
    delta=float(c/a)
    ans=0
    diff=delta-ans
    while diff>.0000001:
        ans=delta
        delta=(c-b*math.sin(ans))/a
        diff=delta-ans
        if diff<0:
            diff=-diff   
    print "%.6f" % delta
    


