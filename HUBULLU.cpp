#include<stdio.h>
#include<iostream>
int main()
{
	int cases,n,player;
	scanf("%d",&cases);
	while(cases--)
	{
		scanf(" %d %d",&n,&player);
		if(player==0)
			printf("Airborne wins.\n");
		else
			printf("Pagfloyd wins.\n");
	}
	return 0;

}


