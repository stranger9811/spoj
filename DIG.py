mod = 1000000007

def f(n):
	t=1
	t = (t*n)
	t = (t*(n-1))
	t = (t*(n-2))
	t = (t*(n-3))
	t = t/24
	return t

test = int(raw_input())
while(test > 0):
	test = test-1
	p = int(raw_input())
	print f(p)%mod
	


