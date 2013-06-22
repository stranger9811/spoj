#include<vector>
#include<cstdio>
#include<iostream>

#define MAX 1000000

using namespace std;

vector <int> G[MAX];

int main()
{
	int cases;
	scanf("%d",&cases);
	while(cases--)
	{
		int numbers,x,val,side1,side2,level;
		for(int i=0; i<MAX; i++)
                        {
                               G[i].clear();
                        }
		scanf("%d",&numbers);
		while(numbers--)
		{
			scanf("%d",&val);
			val=val+MAX/2;
			if(!G[val].size())
				G[val].push_back(val);
			else
			{
				x=val;
				while(1)
				{
					side1=x-1;
					side2=x+1;
					if(G[side1].size()>=G[x].size()&&G[side2].size()>=G[x].size())
					{
						G[x].push_back(val);	
						break;
					}
					else if(G[side1].size()<G[x].size()&&G[side2].size()<G[x].size())
					{
						x=side2;
					}
					else if(G[side1].size()<G[x].size())
						x=side1;
					else if(G[side2].size()<G[x].size())
						x=side2;
				}
			}
		}

		level=1;
		while(1)
		{
			int flag=0;
			for(int i=0; i<MAX; i++)
			{
				if(G[i].size()>=level)
				{
					flag=1;
					level++;		
					break;
				}
			}
			if(flag==0)
				break;
		}
		int exact=level-1;
		level--;
		while(level)
		{
			int j;
			for(int i=0; i<MAX; i++)
			{
				if(G[i].size()>=level)
					printf("O");
				else if(G[i].size()>=1)
				{
					printf("-");
				}
			}
			level--;
			printf("\n");
		}
	}
}
