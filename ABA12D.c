#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int *A,*cnt,n,rootn,i,x,j,cases;
long long count;

int main()
{

int A[37] = {2, 4, 9, 16, 25, 64, 289, 729, 1681, 2401, 3481, 4096, 5041, 7921, 10201, 15625, 17161, 27889, 28561, 29929, 65536, 83521, 85849, 146689, 262144, 279841, 458329, 491401, 531441, 552049, 579121, 597529, 683929, 703921, 707281, 734449, 829921};

int test;
int answer,i,j;
int low,high;
scanf("%d",&test);
while(test--)
{
	answer=0;i=0;
	scanf("%d %d",&low,&high);
	while(A[i] < low)
		i++;
	while(A[i] <= high)
	{
		answer++;	
		i++;
	}	
	printf("%d\n",answer);
}
	return 0;
}
