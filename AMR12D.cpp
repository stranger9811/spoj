#include<cstdio>
#include<string>
#include<iostream>
#include<string.h>
using namespace std;
char magic2[11];
int flag=1;
int reverse (string s) {
	int len=s.length();
	for (int i=0; i< len ; i++) { 

		magic2[len-1-i]=s[i];
	}
	magic2[len]='\0';
	
}
int check_sub(int k,char s1[])
{
	int len;
	string s=s1;
	len=s.length();
	int i;
	for(i=0;i+k<=len;i++)
	{
		string str = s.substr(i,k);
		reverse(str);
		str=magic2;
		if (std::string::npos == s.find(str))
			flag=0;
	}

}
int main()
{
	int cases,i,len;
	scanf("%d",&cases);
	char magic1[11];
	while(cases--)
	{
		flag=1;
		scanf("%s",magic1);	
		len = strlen(magic1);
		for(i=1;i<=len;i++)
		{
			check_sub(i,magic1);
			if(flag==0)
				break;
		}
		if(flag==1)
			printf("YES\n");
		else
			printf("NO\n");

	}
	return 0;
}


