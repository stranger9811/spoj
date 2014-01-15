#include<stdio.h>
#include<string.h>
int main()
{
	int cases,i,j,digits,len,current_number,diff,index;
	int A[10][100002],valid[100002],count[10],iterator[10];
	char number[100002];
	scanf("%d",&cases);
	while(cases--)
	{
		for(i=0;i<10;i++)
		{
			count[i]=0;
			iterator[i]=0;
		}
		index=0;
		scanf(" %s %d",number,&digits);	
		len=strlen(number);
		if(len<=digits)
		{
			if(cases>0)
				printf("\n");
			continue;
		}
		for(i=0;i<len;i++)
		{
			current_number=number[i]-'0';
			A[current_number][count[current_number]]=i;
			count[current_number]++;
		}
		for(i=0;i<len;i++)
			valid[i]=1;
//code
		for(i=9;i>=0;i--)
		{
			while(A[i][iterator[i]]<index)
                                iterator[i]++;
			if(iterator[i]>=count[i])
                                continue;
/*
			for(j=0;j<len;j++)
                                printf("%d ",valid[j]);
                        printf("\nA[i][iterator[i]]=%d i=%d digits=%d index=%d count[i]=%d\n",A[i][iterator[i]],i,digits,index,count[i]);
                        scanf("%d",&j);
*/
			if((A[i][iterator[i]]-index)<=digits)
			{
				for(j=index;j<A[i][iterator[i]];j++)
					valid[j]=0;
				digits=digits-(A[i][iterator[i]]-index);
				index=A[i][iterator[i]]+1;
				iterator[i]++;
				i=10;
			}
			if(digits<=0)
				break;
		}
///		
		if(digits>0)
		{
			for(j=len-1;digits>0;j--)
			{
				if(valid[j])
				{
				valid[j]=0;digits--;
				}
			}
		}

		for(i=0;i<len;i++)
		{
                        if(valid[i])
				printf("%c",number[i]);
		}
		if(cases>0)
			printf("\n");
		
	}
	printf("\n");
	return 0;
}
