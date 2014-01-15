#include<iostream>
#include<stdio.h>
#include<math.h>
#define  MAX 1000001
using namespace std;
int A[1000001];
int main()
{
	int  i,j;
	double right,left,v;
	A[1]=2;
	right=log(2.0);
	
	for(i=j=2;i<MAX;i++)
	{
		v=log((double)i);
		for(++j;;j++)
		{
			left=j*v;
			right+=log((double)j);
			if(left<right)
			{
				A[i]=j;
				
				break;
			}
		}	
	}
	int cases,number;
	scanf("%d",&cases);
	while(cases--)
	{
		scanf("%d",&number);
		printf("%d\n",A[number]);
	}

	return 0;
}
