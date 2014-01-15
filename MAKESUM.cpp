#include<iostream>
#include<vector>
#include<algorithm>
#include<stdio.h>
using namespace std;
int nc2,n;
vector <int> A,B,elements,T;
vector <int>::iterator it;
bool construction(int first_value)
{
	int i,j;
	A.resize(n);
	B.resize(nc2);
	for(i=0;i<nc2;i++)
		B[i]=elements[i];
	A[0]=first_value;
	for(i=1;i<n;i++)
	{
		for(j=0;j<i-1;j++)
		{
			it=find(B.begin(),B.end(),A[j]+A[i-1]);
			if(it==B.end())
				return false;
			B.erase(it);
		}
		A[i]=B[0]-A[0];
		if(A[i]<0)
			return false;
	}
	return true;
}

int main()
{
	int val;
	int i;
	scanf(" %d",&nc2);
	for(i=0;i<=10;i++)
	{
		if((i*(i-1))/2==nc2)
			n=i;
	}
	for(i=0;i<nc2;i++)
	{
		cin >> val;
		elements.push_back(val);
	}
	for(i=1;i<=elements[0]/2;i++)
	{
		if(construction(i))
		{
			sort(A.begin(),A.end());
			if(T.empty())
				T=A;
			else if(A<T)
				T=A;
		}

	}
	for(i=0;i<n;i++)
		printf("%d ",T[i]);
	cout << "\n";
	return 0;

}


