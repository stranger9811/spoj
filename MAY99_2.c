#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>

int main()
{
	char base[5] = {'m','a','n','k','u'};
	int output[100];
	int c[100],test;
	long long n,t=0,temp=0;
	int i=0;
	scanf("%d",&test);
	while(test--)
	{
		temp=0;i=0;
		scanf("%lld",&n);
		while((temp + powl(5,i)) <= n)
		{
			temp = temp+powl(5,i);
			output[i] = 0;
			i++;
		}
		n = n-temp;
		t=0;
		while(n != 0)
		{
			output[t] = n%5;
			n = n/5;
			t++;
		}
		for(t=i-1;t>=0;t--)
			printf("%c",base[output[t]]);
		printf("\n");
	}
	return 0;
}
