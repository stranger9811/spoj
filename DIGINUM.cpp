#include<string.h>
#include<cstdio>

#define MAX 1000
using namespace std;

int main()
{
	char string1[MAX],string2[MAX],string3[MAX];
	while(scanf("%c",&string1[0])!=EOF)
	{
		int i=0;
		while(string1[i]!='\n')
		{
			i++;
			scanf("%c",&string1[i]);
		}
		i=0;
		scanf("%c",&string2[0]);
		while(string2[i]!='\n')
                {
                        i++;
                        scanf("%c",&string2[i]);
                }
		i=0;
		scanf("%c",&string3[0]);
		while(string1[i]!='\n')
                {
                        i++;
                        scanf("%c",&string3[i]);
                }
		
		for(int j=0; j<i; )
		{
			if(string1[j]==' '&&string1[j+1]==' '&&string1[j+2]==' '&&string2[j]==' '&&string2[j+1]==' '&&string2[j+2]=='|'&&string3[j]==' '&&string3[j+1]==' '&&string3[j+2]=='|')
			printf("1");
			else if(string1[j]==' '&&string1[j+1]=='_'&&string1[j+2]==' '&&string2[j]==' '&&string2[j+1]=='_'&&string2[j+2]=='|'&&string3[j]=='|'&&string3[j+1]=='_'&&string3[j+2]==' ')
                        printf("2");
			else if(string1[j]==' '&&string1[j+1]=='_'&&string1[j+2]==' '&&string2[j]==' '&&string2[j+1]=='_'&&string2[j+2]=='|'&&string3[j]==' '&&string3[j+1]=='_'&&string3[j+2]=='|')
                        printf("3");
			else if(string1[j]==' '&&string1[j+1]==' '&&string1[j+2]==' '&&string2[j]=='|'&&string2[j+1]=='_'&&string2[j+2]=='|'&&string3[j]==' '&&string3[j+1]==' '&&string3[j+2]=='|')
                        printf("4");
			else if(string1[j]==' '&&string1[j+1]=='_'&&string1[j+2]==' '&&string2[j]=='|'&&string2[j+1]=='_'&&string2[j+2]==' '&&string3[j]==' '&&string3[j+1]=='_'&&string3[j+2]=='|')
                        printf("5");
			else if(string1[j]==' '&&string1[j+1]=='_'&&string1[j+2]==' '&&string2[j]=='|'&&string2[j+1]=='_'&&string2[j+2]==' '&&string3[j]=='|'&&string3[j+1]=='_'&&string3[j+2]=='|')
                        printf("6");
			else if(string1[j]==' '&&string1[j+1]=='_'&&string1[j+2]==' '&&string2[j]==' '&&string2[j+1]==' '&&string2[j+2]=='|'&&string3[j]==' '&&string3[j+1]==' '&&string3[j+2]=='|')
                        printf("7");
			else if(string1[j]==' '&&string1[j+1]=='_'&&string1[j+2]==' '&&string2[j]=='|'&&string2[j+1]=='_'&&string2[j+2]=='|'&&string3[j]=='|'&&string3[j+1]=='_'&&string3[j+2]=='|')
                        printf("8");
			else if(string1[j]==' '&&string1[j+1]=='_'&&string1[j+2]==' '&&string2[j]=='|'&&string2[j+1]=='_'&&string2[j+2]=='|'&&string3[j]==' '&&string3[j+1]==' '&&string3[j+2]=='|')
                        printf("9");
			else if(string1[j]==' '&&string1[j+1]=='_'&&string1[j+2]==' '&&string2[j]=='|'&&string2[j+1]==' '&&string2[j+2]=='|'&&string3[j]=='|'&&string3[j+1]=='_'&&string3[j+2]=='|')
                        printf("0");	
			j+=3;
		}	
		printf("\n");	
	}
	
}
