mod = 314159

def mod_pow(a, b):
	r = 1
	pw = a
	while b > 0:
		if b & 1:
			r = (r*pw)%mod
		pw = (pw * pw)%mod
		b >>= 1
	return r%mod

test = int(raw_input())
while(test):
	test = test-1
	n = int(raw_input())
	print (4*mod_pow(8,n-1) + 5*mod_pow(10,n-1))%mod
	






