#include<stdio.h>
#include<string.h>
int gcd(int a, int b)
{
	if (b==0)
		return a;
	else
		return gcd(b,a%b);
}
int main()

{

	int cases,A,i,len,val,result;
	char B[300];
	scanf("%d",&cases);
	while(cases--)
	{
		scanf("%d",&A);
		scanf("%s",B);
		if(A==0)
			printf("%s\n",B);
		else
		{
			len=strlen(B);
			val=1;
			result=0;
			for(i=len-1;i>=0;i--)
			{
				result=(result+(B[i]-'0')*val)%A;
				val=(val*10)%A;
			}
			printf("%d\n",gcd(A,result));
		}

	}
	return 0;
}


