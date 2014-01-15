#include<stdio.h>
#include<stdlib.h>
int *A,*cnt,n,rootn,i,x,j,cases;
long long count;

int main()
{
	int temp;
	n=10006;
	A=(int *)malloc(sizeof(int)*(n+1));
	rootn=110;
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
	int k=0;	
	scanf("%d",&n);
	int first=0;
	for(i=0;i<10006;i++)
	{
		if(i>n)
			break;
		if(A[i]==1)
		{
			count=0;
			for(j=i;j<=n;j=j+i)
			{	
				temp=j;
				while(temp%i==0)
				{
					count++;
					temp=temp/i;
				}
			}
			if(first==0&&count!=0)
			{
				printf("%d^%lld ",i,count);
				first=434;
			}
			else if(count!=0&&first!=0)
			{
				printf("* %d^%lld ",i,count); 
			}	

		}
	}
	printf("\n");
	return 0;

}



