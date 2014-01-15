/*
	Ashok Kumar
	Algorithm: math,sieve 
*/
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<iostream>

#define MAX 10000007

long long A[MAX][3];
using namespace std;

int prime_finder(int n)
{
        int rootn,i,j,size;
        rootn=sqrt(n)+1000;
        for(i=0;i<n;i++)
	{
                A[i][0]=1;
		A[i][1]=0;
	}
        for(i=2;i<rootn;i++)
        {
                if(A[i][0]==1)
                {
			A[i][1]=i;
                        for(j=(i*i);j<n;j=j+i)
			{
                                A[j][0]=0;
				if(A[j][1]==0)
					A[j][1]=i;
			}
                }
        }
	for(i=i-2;i<MAX;i++)
	{
		if(A[i][1]==0)
			A[i][1]=i;
	}
        A[1][0]=0;
        A[0][1]=0;
}
int main()
{
	int i,cases;
	long long answer=0,past=0;
	prime_finder(MAX);
	for(int j=2;j<MAX;j++)
	{
		answer=A[j][1]+past;
		A[j][2]=answer;
		past=answer;
	}
	scanf("%d",&cases);
	while(cases--)
	{
		scanf("%d",&i);
		if(i==1)
			printf("0\n");
		else
		{
			printf("%lld\n",A[i][2]);
		}
	}
	return 0;
}
