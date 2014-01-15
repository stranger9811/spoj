#include<algorithm>
#include<stdio.h>
int A[10000];
int main()
{
	int number,i,j,r,q,count=0,bob_friend;
	scanf("%d",&number);
	for(i=0;i<10000;i++)
		A[i]=0;
	for(i=0;i<number;i++)
	{
		scanf("%d",&bob_friend);
		A[bob_friend]=2;
		scanf("%d",&q);
		for(j=0;j<q;j++)
		{
			scanf("%d",&r);
			if(A[r]!=2)
				A[r]=1;
		}
	}
	for(i=0;i<10000;i++)
	{
		if(A[i]==1)
			count++;
	}
	printf("%d\n",count);
	
	return 0;
}
