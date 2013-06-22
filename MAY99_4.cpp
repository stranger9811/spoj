#include<cstdio>
#include<cmath>
#include<iostream>
#include<vector>
using namespace std;
long long SmallC(int n, int r, int MOD)
{
	vector< vector<long long> > C(2,vector<long long> (r+1,0));

	for (int i=0; i<=n; i++)
	{
		for (int k=0; k<=r && k<=i; k++)
			if (k==0 || k==i)
				C[i&1][k] = 1;
			else
				C[i&1][k] = (C[(i-1)&1][k-1] + C[(i-1)&1][k])%MOD;
	}
	return C[n&1][r];
}

long long Lucas(int n, int m, int p)
{
	if (n==0 && m==0) return 1;
	int ni = n % p;
	int mi = m % p;
	if (mi>ni) return 0;
	return Lucas(n/p, m/p, p) * SmallC(ni, mi, p);
}

long long C(int n, int r, int MOD)
{
	return Lucas(n, r, MOD);
}
int inverse(int m1,int p1)
{
	int i;
	for(i=0;;i++)
	{
		if((i*m1)%p1 == 1)
			return i;
	}
}
int chinese_remainder(int nis[],int pis[],int size)
{
	int mis[1000];
	int is[1000];
	int m=1,i;
	int ans=0;
	for(i=0;i<size;i++)
		m=m*pis[i];
	for(i=0;i<size;i++)
	{
		mis[i]=m/pis[i];
		is[i] = inverse(mis[i],pis[i]);
	}
	for(i=0;i<size;i++)
		ans = (nis[i]*mis[i]*is[i]+ans)%m;

	ans = ans%m;
	return ans;
}
int chinese_remainder1(long long n1,long long n2)
{
        int p1=941,p2=10627;
        long long m1,m2;
        long long i1,i2;
        long long m;
        int ans;
        m = p1*p2;
        m1 = m/p1;m2=m/p2;
        i1 = inverse(m1,p1);i2=inverse(m2,p2);
        ans = (n1*m1*i1)%m+(n2*m2*i2)%m ;
        ans = ans%m;
        return ans;
        //printf("%d\n",ans);
}

int main()
{
	int i,size,value,r,number,fact[10],chinese[10];
	scanf("%d %d",&number,&r);
	number=number-r;
	if(number<0)
	{
		printf("-1\n");
		return 0;
	}
	if(number==0)
	{
		printf("1\n");
		return 0;
	}
	number=number+r-1;
	r=r-1;
	chinese[0]=C(number,r,941);
	chinese[1]=C(number,r,10627);
	fact[0]=941;
	fact[1]=10627;
//	printf("%d %d\n",chinese[0],chinese[1]);
	size=2;
	long long answer=chinese_remainder1(chinese[0],chinese[1]);
	printf("%lld\n",answer);
	return 0;
}


