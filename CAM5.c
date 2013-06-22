/* Ashok Kumar
   Algo:  DFS,connected component
*/
#include<stdio.h>
#include<stdlib.h>
struct node
{
	int value;
	struct node *next;
};
int nodes;
struct node *list[100005],*current;
int *visited;
int vertices,edges,u,v,i;
void make_link(struct node *list[],int u,int v)
{
	struct node *current,*new,*new2;
	current = list[u];
	new2=current->next;
	new=(struct node *)malloc(sizeof(struct node));
	new->value=v;
	new->next=new2;
	current->next=new;
}
void DFS(int v)
{
	struct node *current;
	visited[v]=1;
	current=list[v]->next;
	while(current!=NULL)
	{
		//printf("hiii");
		if(visited[current->value]==0)
		{
			nodes++;
			DFS(current->value);
		}
		current=current->next;
	}
}	
int main()
{
	int cases,no_connected;
	long long captain;
	scanf("%d",&cases);
	while(cases--)
	{
		captain=1;
		no_connected=0;
		scanf("%d %d",&vertices,&edges);
		visited=(int *)malloc(sizeof(int)*(vertices+1));
		for(i=1;i<=vertices;i++)
		{
			visited[i]=0;
			free(list[i]);
			list[i]=(struct node *)malloc(sizeof(struct node));
			list[i]->value=i;
			list[i]->next=NULL;
		}
		for(i=0;i<edges;i++)
		{
			scanf("%d %d",&u,&v);
			u++;
			v++;
			make_link(list,u,v);
			make_link(list,v,u);
		}
		for(i=1;i<=vertices;i++)
		{
			if(visited[i]==0)
			{
				nodes=1;
				no_connected++;
				DFS(i);
				captain=(captain*nodes)%1000000007;
			}
		}
		printf("%d\n",no_connected);
		// free(list);
		free(visited);
	}
	return 0;
}

