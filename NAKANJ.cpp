/* Ashok Kumar
   Algo used : BFS(Breadth first search)
*/
#include<vector>
#include<cstdio>
#include<queue>

using namespace std;

vector <int> G[64];
int A[8][2]={ {1,2},{2,1},{2,-1},{1,-2},{-1,-2},{-2,-1},{-2,1},{-1,2}};
int BFS(int u,int v)
{
	if(u==v)
		return 0;
	int distance[64],visited[64];
	for(int i=0; i<64; i++)
	{
		distance[i]=0;
		visited[i]=0;
	}
	queue <int> neigh;
	for(int x=0; x<G[u].size(); x++)
	{
		if(G[u][x]==v)
			return 1;
		distance[G[u][x]]=1;
		neigh.push(G[u][x]);
	}
	while(!neigh.empty())
	{
		int val=neigh.front();
		neigh.pop();
		for(int i=0; i<G[val].size(); i++)
		{
			if(visited[G[val][i]]==0)
			{
				visited[val]==1;
				distance[G[val][i]]=1+distance[val];
				neigh.push(G[val][i]);
			}
			if(G[val][i]==v)
				return distance[v];
		}
	}
}
int main()
{
	for(int i=0; i<=63; i++)
	{
		int row,column;
		int new_row,new_column;
		column=i%8;
		row=i/8;
		for(int j=0; j<8; j++)
		{
			if(((A[j][0]+row)<0)||((A[j][0]+row)>=8)||((A[j][1]+column)<0)||((A[j][1]+column)>=8))
				continue;
			new_row=A[j][0]+row;
			new_column=A[j][1]+column;
			G[i].push_back(new_row*8+new_column);
		}
	}
	int cases;
	scanf("%d",&cases);
	while(cases--)
	{
		int initial,final;
		char column1,column2;
		int row1,row2;
		scanf(" %c%d",&column1,&row1);
		scanf(" %c%d",&column2,&row2);
		initial=(row1-1)*8+(column1-'a');
		final=(row2-1)*8+(column2-'a');
		printf("%d\n",BFS(initial,final));
	}
	return 0;
}
