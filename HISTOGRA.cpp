/* Ashok Kumar
   Stack
 */

#include<stack>
#include<cstdio>
#include<iostream>
using namespace std;

#define MAX 100005

stack <long long> MyStack_R;
stack <long long > MyStack_L;


long long R[MAX],L[MAX],Histogram[MAX];

long long find_rectangle(long long A[],long long size)
{
	long long i , index;

	// Finding value of R[i]
	MyStack_R.push(0);
	for(i=1;i<size;i++)
	{

		if(A[i]>=A[MyStack_R.top()])
		{
			MyStack_R.push(i);
		}
		else
		{
			while(!MyStack_R.empty())
			{	
				if((A[i]<A[MyStack_R.top()]))
				{
					index=MyStack_R.top();
					MyStack_R.pop();
					R[index]=i-1;
				}
				else 
					break;
			}
			MyStack_R.push(i);

		}
	}
	while(!MyStack_R.empty())
	{
		index=MyStack_R.top();
		MyStack_R.pop();
		R[index]=i-1;
	}
	// Finding value of L[i]
	MyStack_L.push(size-1);
	for(i=size-2;i>=0;i--)
	{
		if(A[i]>=A[MyStack_L.top()])
			MyStack_L.push(i);
		else
		{       
			while(!MyStack_L.empty())
			{
				if(A[i]<A[MyStack_L.top()])
				{
					index=MyStack_L.top();
					MyStack_L.pop();
					L[index]=i+1;
				}
				else
					break;
			}
			MyStack_L.push(i);
		}
	}
	while(!MyStack_L.empty())
	{
	index=MyStack_L.top();
	MyStack_L.pop();
	L[index]=0;
	}

	long long CheckI[MAX];
	long long maxi=0;
	for(i=0;i<size;i++)
	{
		CheckI[i]=A[i]*(-L[i]+R[i]+1);
		if(CheckI[i]>maxi)
			maxi=CheckI[i];
	}
	return maxi;

}
int main()
{
	long long value,size,i;
	while(1)
	{
		scanf("%lld",&size);
		if(size==0)
			break;
		for(i=0;i<size;i++)
			scanf("%d",&Histogram[i]);
		printf("%lld\n",find_rectangle(Histogram,size));
	}
	return 0;
}


