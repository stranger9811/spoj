x=int(raw_input())
for i in range(0,x):
	y=raw_input()
	a=int(y.split(" ")[0]);
        b=int(y.split(" ")[1]);
	flag=0
	if a==b or (a-2)==b:
		flag=1
	if flag==0:
		print "No Number"
	else:
		answer=2*a
		if a%2!=0:
			answer=answer-1
		if a==b:
			print answer
		else:
			print answer-2



