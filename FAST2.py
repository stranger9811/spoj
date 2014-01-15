mod =1298074214633706835075030044377087

def mod_pow(a, b):
	r = 1
	pw = a
	while b > 0:
		if b & 1:
			r = (r*pw)%mod
		pw = (pw * pw)%mod
		b >>= 1
	return (r-1)%mod

test = int(raw_input())
for x in range(0,test):
	k = int(raw_input())
	a = mod_pow(2,k+1)
	print a


