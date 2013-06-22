#include<cstdio>
#include<cmath>
#include<algorithm>
#include<iostream>

#define Max 31622780

int prime[1000000],factor[1000][2];
using namespace std;
int prime_finder(int n)
{
	
        int *A,rootn,i,j,size;
        A=(int *)malloc(sizeof(int)*Max);
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
int factor_finder(int number,int size)
{
	int i,j;
	for(i=0;i<1000;i++)
		factor[i][1]=0;
	j=0;
	for(i=0;i<size;i++)
	{
		//modify your code by checking number is prime or not
		if(number%prime[i]==0)
			j++;
		while(number%prime[i]==0)
		{
			factor[j-1][0]=prime[i];
			number=number/prime[i];
			factor[j-1][1]++;
		}
	}
	if(number!=1)
	{
		factor[j][0]=number;
		factor[j][1]=1;
		j++;
	}
	return j;


}
int main()
{
	int i,size;
	size=prime_finder(Max);
	//size=factor_finder(MOD,size);
}
