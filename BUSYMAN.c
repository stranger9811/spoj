#include<stdio.h>
int overlap(int a[][3],int i,int j)
{
	if(a[i][1] > a[j][0])
		return 1;
	else
		return 0;
}

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
		for(x=0;x<2;x++)
			a[i][x] = c[i-low][x];
	}	
}
int main()
{
	int tasks,i,j,d,n,index,temp,x,m,answer;

	int k=0;
	scanf("%d",&tasks);
	while(tasks--)	
	{
		answer=0;
		scanf("%d",&n);
		int a[n][3];
		answer=0;
		k=0;
		for(i=0;i<n;i++)
		{
			scanf(" %d %d",&a[i][0],&a[i][1]);
			a[i][2] = 1;
		}
		mergesort(a,0,n-1,1);
		for(i=0;i<n;i++)
		{
			if(a[i][2] == 1)
			{		
				j = i+1;
				while(j<n)
				{
					if(overlap(a,i,j))
					{
						a[j][2] = 0;
					}
					j++;
				}
			}
		}
		for(i=0;i<n;i++)
			if(a[i][2]==1)
				answer++;
		printf("%d\n",answer);
	}
		return 0;
}

