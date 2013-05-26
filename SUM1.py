x=int(raw_input())
for i in range(0,x):
	n=int(raw_input())
	n=n-1
	n_3=n/3;
	val_3=(3*n_3*(n_3+1))/2;
	n_5=n/5
	val_5=(5*n_5*(n_5+1))/2
	n_15=n/15
	val_15=(15*n_15*(n_15+1))/2
	print val_5+val_3-val_15


