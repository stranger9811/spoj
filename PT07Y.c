#include<stdio.h>
#include<stdlib.h>
struct node
{
	int value;
	struct node *next;
};
int min(int x,int y)
{
	if(x>y)
		return y;
	else
		return x;
}
struct node *list[10000],*current;
int *visited,count=0;
int vertices,edges,u,v,i;
void make_link(struct node *list[],int u,int v)
{
	struct node *current,*new;
	current = list[u];
	while(current->next!=NULL)
		current=current->next;
	new=(struct node *)malloc(sizeof(struct node));
	new->value=v;
	new->next=NULL;
	current->next=new;
}
void DFS(int v,int choice)
{
	struct node *current;
	visited[v]=1;
	current=list[v]->next;
	while(current!=NULL)
	{
		if(visited[current->value]==0)
			DFS(current->value,choice);
		current=current->next;
	}
}			
int main()
{
	
	scanf("%d %d",&vertices,&edges);
	visited=(int *)malloc(sizeof(int)*vertices);
	for(i=0;i<vertices;i++)
	{
		visited[i]=0;
		list[i]=(struct node *)malloc(sizeof(struct node));
		list[i]->value=i;
		list[i]->next=NULL;
	}
	for(i=0;i<edges;i++)
	{
		scanf("%d %d",&u,&v);
		u--;
		v--;
		make_link(list,u,v);
		make_link(list,v,u);	
	}
	for(i=0;i<vertices;i++)
	{
		if(visited[i]==0)
		{
			count++;
			DFS(i,0);
		}
	}
	if(count>1||edges>=vertices)
		printf("NO\n");
	else
		printf("YES\n");
	return 0;
}


