#include<stdio.h>

int main()
{
int a[1000007];
int i=1,k=2,index=1,count,number=1,cases,n;
a[1] = 1;
number=2;
while(k<1000001)
{
	count=a[i];
	while(count>0 && k<1000001)
	{
		a[k]=number;
		k++;
		count--;
	}
	number++;
	i++;
}		
scanf("%d",&cases);
for(i=1;i<=cases;i++)
{
	scanf("%d",&n);
	printf("Case #%d: %d\n",i,a[n]);
}
//for(i=1;i<12;i++)
//	printf("%d",a[i]);
//printf("\n");
return 0;
}


