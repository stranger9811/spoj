#include<cstdio>
#include<algorithm>
#include<vector>

#define MAX 1004

using namespace std;

vector <int> G[MAX];

int main()
{
	int cases,N,U,value,mod,div,max=0;
	scanf("%d",&cases);
	for(int p=1; p<=cases;p++)
	{
		for(int i=0;i<MAX;i++)
			G[i].clear();
		scanf("%d %d",&N,&U);
		while(N--)
		{
			scanf("%d",&value);
			div=value/U;
			mod=value%U;
			G[div].push_back(mod);
			if(div>max)
				max=div;
		}
		for(int i=0;i<MAX;i++)
                {
			sort(G[i].begin(),G[i].end());
		}
		printf("Scenario #%d:\n\n",p);
		for(int i=0;i<MAX;i++)
                {       
                        if(G[i].size())
			{
				printf("%d |",i);
				int size=G[i].size();
				for(int x=0; x<size; x++)
				{
					printf(" %d",G[i][x]);
				}
				printf("\n\n");
			
			}
                }
	}
}
