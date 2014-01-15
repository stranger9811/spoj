#include<algorithm>
#include<iostream>
#include<stdio.h>
#include<vector>
#include<math.h>

using namespace std;

vector <int> square(317),T,A;
int ai;
void construct(int size,int index,int partition,int sum)
{
	int i;	
	if(size==partition)
	{
		if(sum==ai)
		{
			if(T.empty())
			{
				T=A;
			}
			else if(A<T)
				T=A;
		}

		return;
	}
	for(i=index;i<317;i++)
	{
		A[size]=i;
		sum=sum+square[i];
		if(!T.empty())
		{
			if(A>T)
				return;
		}
		if(sum>ai)
		{
			return;
		}
		construct(size+1,i,partition,sum);
		sum=sum-square[i];
	}
}
int main()
{
	int cases,i,ni,j;
	scanf("%d",&cases);
	for(i=0;i<317;i++)
		square[i]=pow(i,2);
	while(cases--)
	{
		vector <int> temp;
		scanf(" %d %d",&ni,&ai);
		T=temp;
		A.resize(ni);

		if(ni>=4)
		{
			construct(0,0,4,0);
			for(i=4;i<ni;i++)
				printf("0 ");
			for(i=0;i<4;i++)
				printf("%d ",T[i]);
			printf("\n");
			continue;
		}
		construct(0,0,ni,0);
		if(T.empty())
			printf("impossible\n");
		else if(!T.empty())
		{
			for(i=0;i<ni;i++)
				printf("%d ",T[i]);
			printf("\n");
		}
		
	}

}


