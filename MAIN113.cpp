#include<cstdio>

long long c[32];

int main()
{
	c[1]=3;
	c[2]=9;
	for(int j=3;j<32;j++)
		c[j]=2*c[j-1]+c[j-2];
	int cases;
	scanf("%d",&cases);
	while(cases--)
	{
		int number;
		scanf("%d",&number);
		printf("%lld\n",c[number]);
	}
	return 0;
}
