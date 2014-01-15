#include<stdio.h>

int main()
{

int test,a,b,n,k,mod,div,i,j,answer,count;
int power[] = {1,10,100,1000,10000,100000,1000000};
scanf("%d",&test);
for(j=1;j<=test;j++)
{
	answer=0;
	scanf("%d %d",&a,&b);
	for(i=a;i<=b;i++)
	{
		k = i;count=0;
		while(k){ k=k/10;count++;}
		count--;
		n=i;
		k=i;
		while(1)
		{
			mod = n%10;
			div = n/10;
			n = mod*power[count] + div;
			if(n==k) break;
			if(mod>0 && n>=a && n<=b)answer++;
		}
	}
	answer= answer/2;
	printf("Case #%d: %d\n",j,answer);
}
return 0;
}
