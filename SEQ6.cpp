#include <cstdio>
#include<iostream>
#include <cmath>
using namespace std;

int prime[100000];
using namespace std;
int prime_finder(int n)
{
        int A[1000007],rootn,i,j,size;
        rootn=sqrt(n)+100;
        for(i=0;i<n;i++)
                A[i]=1;
        for(i=2;i<rootn;i++)
        {
                if(A[i]==1)
                {
                        for(j=(i*i);j<n;j=j+i)
                                A[j]=0;
                }
        }
        A[1]=0;
        A[0]=0;
	j=0;
	for(i=0;i<n;i++)
	{
		if(A[i])
		{
			prime[j]=i;
			j++;
		}
	}
	return j;
}
int d(int n)
{
	int ret, root, cnt, i;
	while(!(n&1)) n >>= 1;
	root = (int)sqrt((double)n);
	for(i=0,ret=1; prime[i]<=root; i++)
	{
		if(n % prime[i] == 0)
		{
			cnt = 0;
			while(n % prime[i] == 0)
			{
				n /= prime[i];
				cnt++;
			}
			ret *= ++cnt;
			
			root = (int)sqrt((double)n);
		}
	}
	if(n>2) ret <<= 1;
	return ret;
}

int main()
{
	int n;
	prime_finder(100000);
	while(scanf("%d", &n)==1 && n) printf("%d\n", d(n)<<1);
	return 0;
}
