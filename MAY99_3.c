#include<stdio.h>

int gcd(int a, int b)
{
	if (b==0)
		return a;
	else
		return gcd(b,a%b);
}

int main()
{
	int a,b,c;
	int test;
	scanf("%d",&test);
	while(test--)
	{
	scanf("%d %d %d",&a,&b,&c);
	if(c>b && c>a)
	{
		printf("NO\n");
		continue;
	}
	if(a>b)
	{
		if(c%gcd(a,b) == 0)
			printf("YES\n");
		else
			printf("NO\n");
	}	
	else
	{
		if(c%gcd(b,a) == 0)
			printf("YES\n");
		else
			printf("NO\n");
	}	
	}
	return 0;
}
