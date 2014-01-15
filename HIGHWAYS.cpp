#include<queue>
#include<ios>
#include<vector>
#include <cstdio>
#define INFINITY 100000000
#define MAX 100001
#define pii pair< int, int >

using namespace std;

vector< pii > G[MAX];
int process(int nodes,int edges,int start,int end)
{
	int u,v,len,weight,weightu,weightv;
	int visited[100001],distance[100001];
	for(int i=0;i<=nodes;i++)
	{
		G[i].clear();
		visited[i]=0;
		distance[i]=INFINITY;
	}
	for(int i=0;i<edges;i++)
	{	
		scanf(" %d %d %d",&u,&v,&weight);
		G[u].push_back(pii(weight,v));
		G[v].push_back(pii(weight,u));
	}
	priority_queue < pii , vector <pii> , greater<pii> > Q;
	distance[start]=0;
	Q.push(pii(0,start));
	while(!Q.empty())
	{
		u=Q.top().second;
		weightu=Q.top().first;
		Q.pop();
		len=G[u].size();
		for(int i=0;i<len;i++)
		{
			v=G[u][i].second;
			weightv=G[u][i].first;
			if(!visited[v]&&(weightu+weightv<=distance[v]))
			{
				distance[v]=weightu+weightv;
				Q.push(pii(distance[v],v));
			}
		}
		visited[u]=1;
	}
	return distance[end];
}

int main()
{
	int cases,nodes,edges,start,end,answer;
	scanf("%d",&cases);
	while(cases--)
	{
		scanf(" %d %d %d %d",&nodes,&edges,&start,&end);
		answer=process(nodes,edges,start,end);
		if(answer==INFINITY)
			printf("NONE\n");
		else
			printf("%d\n",answer);

	}
	return 0;
}


