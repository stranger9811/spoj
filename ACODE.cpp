#include<cstdio>
#include<string.h>
using namespace std;
int len;
char s[5005];
int dip[5005];
long long find_number(int index)
{
	int number;
	long long answer;
	if(index>len)
		return 0;
	if(index==len)
		return 1;
	if(dip[index])
		return dip[index];
	if(s[index]=='0') return 0;
	answer=0;
	answer+=find_number(index+1);
	if(index+1<len)
	{
		number=10*(s[index]-'0')+(s[index+1]-'0');
		if(number>=1&&number<=26)
			answer+=find_number(index+2);
	}
	dip[index]=answer;
	return answer;


}
int main()
{
	while(1)
	{
		scanf("%s",s);
		len=strlen(s);
		if(s[0]=='0')
			break;
		memset(dip,0,sizeof(dip));
		printf("%d\n",find_number(0));

	}
	return 0;

}


