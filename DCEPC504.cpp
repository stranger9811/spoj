#include<stdio.h>

int main()
{
int j,cases,number,ans;
long long k,i,n;

scanf("%d",&cases);
while(cases--)
{
	ans=1;
	scanf(" %d",&number);
	scanf("%lld",&k);
	n=1;
	while(n<k)
		n*=2;
	
	while(n != 1)
	{
		if(k > n/2)
		{
			k = k-(n/2);
			ans*=-1;
		}
		n/=2;
	}
	if(ans > 0)
		printf("Male\n\n");
	else
		printf("Female\n\n");
}
return 0;
}
