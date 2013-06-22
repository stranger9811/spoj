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
int *visited,count=0,*dia,*second_max,*max;
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
void DFS(int v)
{
	struct node *current;
	visited[v]=1;
	current=list[v]->next;
	while(current!=NULL)
	{
		if(visited[current->value]==0)
		{
			
			DFS(current->value);
			if(dia[current->value]>dia[v])
				dia[v]=dia[current->value];
			if(second_max[v]<(max[current->value]+1))
				second_max[v]=max[current->value]+1;
			if(second_max[v]>max[v])
			{
				int temp;
				temp=second_max[v];
				second_max[v]=max[v];
				max[v]=temp;
			}
		}
		current=current->next;
	}
	if((second_max[v]+max[v])>dia[v])
		dia[v]=second_max[v]+max[v];
}			
int main()
{
	int cases;
	scanf("%d",&cases);
	while(cases--)
	{
	
	scanf("%d",&vertices);
	edges=vertices-1;
	visited=(int *)malloc(sizeof(int)*vertices);
	dia=(int *)malloc(sizeof(int)*vertices);
	second_max=(int *)malloc(sizeof(int)*vertices);
	max=(int *)malloc(sizeof(int)*vertices);
	for(i=0;i<vertices;i++)
	{
		visited[i]=0;
		second_max[i]=0;
		max[i]=0;
		dia[i]=0;
		list[i]=(struct node *)malloc(sizeof(struct node));
		list[i]->value=i;
		list[i]->next=NULL;
	}
	for(i=0;i<edges;i++)
	{
		scanf("%d %d",&u,&v);
		make_link(list,u,v);
		make_link(list,v,u);	
	}
	for(i=0;i<vertices;i++)
	{
		if(visited[i]==0)
		{
			count++;
		DFS(i);
		}
	}
	if(dia[0]==1)
		printf("1\n");
	else
		printf("%d\n",dia[0]-1);
		
	}
	return 0;
}


