/* 	Ashok Kumar
	Dynamic Programming
*/
#include<stdio.h>

int main()
{
	int n;
	long long A[100],B[100],C[100];
	scanf("%d",&n);
	A[1]=1;B[1]=1;C[1]=1;
	for(int i=2; i<=n; i++)
	{
		A[i]=A[i-1]+B[i-1];
		B[i]=A[i-1]+B[i-1]+C[i-1];
		C[i]=B[i-1]+C[i-1];
	}
	printf("%lld\n",A[n]+B[n]+C[n]);
	return 0;

}
