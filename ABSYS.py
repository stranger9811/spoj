test = int(raw_input())
to_find="machula"
for i in range(test):
	z=raw_input()
	y=raw_input()
	index=y.find(to_find)
	if (index+6)!=(len(y)-1):
		y=y[:index] + "12" +y[index+7:]
	else:
		y=y[:index] + "12"
	equal_to=y.find("=")
	plus=y.find("+")
	s=y.split(" ")
	number1=int(s[0])
	number2=int(s[2])
	number3=int(s[4])
	if index<plus:
		number1=number3-number2
	elif index>equal_to:
		number3=number1+number2
	else:
		number2=number3-number1
	print str(number1),"+",str(number2),"=",str(number3) 
		
		
	


