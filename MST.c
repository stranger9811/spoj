#include<stdio.h>
int parent[10005],valid[100005];
void merge(int a[][3],int low,int mid,int high,int c[][3],int parameter)
{
	//printf("merge,%d,%d\n",low,high);
	int i=low,j=mid+1,k=0,x;
	while(i<=mid && j<=high)
	{
		if(a[i][parameter] < a[j][parameter])
		{
			for(x=0;x<3;x++)
				c[k][x] = a[i][x];
			k++;
			i++;
		}
		else {
			for(x=0;x<3;x++)
				c[k][x] = a[j][x];
			k++;
			j++;
		}
	}
	while(i<=mid) {
		for(x=0;x<3;x++)
			c[k][x] = a[i][x];
		i++;
		k++;
	}
	while(j<=high){
		for(x=0;x<3;x++)
			c[k][x] = a[j][x];
		k++;
		j++;
	}
}

void mergesort(int a[][3],int low,int high,int parameter)
{
	//printf("mergesort\n");
	if(high <= low)
		return;
	int i=0,x;
	int c[high-low+1][3];
	int mid = (low+high)/2;
	mergesort(a,low,mid,parameter);
	mergesort(a,mid+1,high,parameter);
	merge(a,low,mid,high,c,parameter);
	for(i=low;i<=high;i++)
	{
		for(x=0;x<3;x++)
			a[i][x] = c[i-low][x];
	}
}
int Find(int i)
{
	if(parent[i]==i)
		return i;
	else
		return Find(parent[i]);
}
int is_connected(int x,int y)
{
	if(Find(x)==Find(y))
		return 1;
	else 
		return 0;
}
int union_set(int a,int b) {
	int k;
	k=Find(b);
	parent[k]=a;
	return 0;
}

int main()
{
	int n,q,x,y,test,i,A[100005][3];
	int edges,sum=0,nodes;
	scanf(" %d %d ",&nodes,&edges);
	for(i=0;i<=nodes;i++)
	{
		parent[i]=i;
	}
	for(i=0;i<edges;i++)
	{
		valid[i]=1;
		scanf("%d",&A[i][0]);
		scanf("%d",&A[i][1]);
		scanf("%d",&A[i][2]);
	}
	mergesort(A,0,edges-1,2);
/*	for(i=0;i<3;i++)
	{
		for(x=0;x<edges;x++)
			printf("%d ",A[x][i]);
		printf("\n");
	}*/
	for(i=0;i<edges;i++)
	{
		x=A[i][0];
		y=A[i][1];
		if(is_connected(x,y)==0)
			union_set(x,y);
		else
			valid[i]=0;
	}
	for(i=0;i<edges;i++)
	{
		if(valid[i]==1)
			sum=sum+A[i][2];
	}
	printf("%d\n",sum);
	return 0;
}
