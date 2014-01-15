/* Name :       Ashok Kumar
   Algorithm:   Stack
 */

#include<stack>
#include<cstdio>
#include<iostream>
#include<string.h>

using namespace std;

#define MAX 100005

stack <long long> MyStack_R;
stack <long long > MyStack_L;
stack <int> mystack;

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
int declare_array(int array[][1005],int row,int length)
{
	char field;
	int val;
	for(int i=0; i<length; i++)
	{
		scanf(" %c",&field);
		if(field=='F')
		{	
			mystack.push(i);
		}
		else
		{
			while(!mystack.empty())
			{
				val=mystack.top();
				mystack.pop();
				array[row][val]=i-val;
			}
			array[row][i]=0;
		}
	}
	while(!mystack.empty())
	{
		val=mystack.top();
		mystack.pop();
		array[row][val]=length-val;
	}
	return 1;

}
int main()
{
	int Array[1005][1005];
	long long cases,answer=0;
	int height,length,len;
	scanf("%lld",&cases);
	while(cases--)
	{
		answer=0;
		scanf(" %d %d",&height,&length);
		char str1[1004];
		for(int i=0; i<height; i++)
		{
			declare_array(Array,i,length);
		}
		for(int i=0;i<length;i++)
		{
			for(int j=0; j<height; j++)
				Histogram[j]=Array[j][i];
			answer=max(answer,find_rectangle(Histogram,height));
		}
		printf("%lld\n",3*answer);
	}
	return 0;
}


