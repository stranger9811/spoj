#include<algorithm>
#include<cstdio>

#define MAX 524288
#define VAL 362144

using namespace std;

int A[MAX],negative=0;

long long sum1(int i,int j)
{
	long long sum=A[i];
	if(j>i)
		sum=sum+A[j];
	while(i/2!=j/2)
	{
		if(i%2==0)
		{
			sum=sum+A[i+1];
		}
		if(j%2!=0)
		{
			sum=sum+A[j-1];
		}
		i=i/2;
		j=j/2;
	}
	return sum;
}
int update(int i,int value)
{
	while(i!=1)
	{
		A[i]=A[i]+value;
		i=i/2;
	}

}
int main()
{
	int Query,operation,numbers;
	for(int i=0; i<MAX; i++)
		A[i]=0;
	
	// Scanning part

	scanf("%d",&numbers);
	negative=0;


	for(int i=1; i<=numbers; i++)
		scanf("%d",&A[VAL+i]);

	for(int i=262143; i>=0; i--)
		A[i] = A[2*i] + A[2*i + 1];

	scanf("%d",&Query);

	int delta,current,min,max;
	
	while(Query--)
	{
		scanf("%d",&operation);
		
		if(operation==1)
		{
			scanf("%d %d",&min,&max);
			min=min+VAL+negative;
			max=max+VAL+negative;
			printf("%lld\n",sum1(min,max));
		}
		if(operation==2)
		{
			scanf("%d",&delta);
			current=VAL+negative;
			update(current,delta);
			negative--;
		}

	}
	return 0;

}
