#include<cstdio>
#include<string.h>
#include<cmath>
#include<iostream>
int prime[500000];
using namespace std;
int prime_finder(int n)
{
        int A[1000007],rootn,i,j,size;
        rootn=sqrt(n)+1;
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
int main()
{
	int size;
	long long result,len,val,flag,L;
	char B[103];
	size=prime_finder(1000007);
	while(1)
	{
		scanf(" %s",B);
		scanf("%lld",&L);
		if(L==0)
			break;
		len=strlen(B);
		for(int x=0; x<size; x++)
		{
			flag=0;
			if(prime[x]>=L)
				break;
			
			result=0;
			int i=0;
			while(i!=len)
			{
				result=(result*10+B[i]-'0')%prime[x];
				i++;
			}
			if(result==0)
			{
				printf("BAD %d\n",prime[x]);
				flag=1;
				break;
			}
		
		}
		if(flag==0)
			printf("GOOD\n");
		
	}
	return 0;
}


