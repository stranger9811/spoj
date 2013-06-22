#include<algorithm>
#include<vector>
#include<cstdio>
#include<stack>

using namespace std; 

stack <int> Sequence;

int main()
{
	int numbers,a;
	long long answer;

	scanf("%d",&numbers);

	answer=0;
	for(int i=0; i<numbers; i++)
	{
		scanf("%d",&a);
		if(Sequence.empty())
			Sequence.push(a);
		else
		{
			if(Sequence.top()>a)
				Sequence.push(a);
			else
			{
				int TopElement=Sequence.top();
				int q,flag=0;
				Sequence.pop();
				q=TopElement;
				while(!Sequence.empty())
				{
					if(Sequence.top()>a)
					{
						flag=1;
						q=Sequence.top();
						Sequence.push(a);
						break;
					}
					else
					{
						//printf("%d %d",Sequence.top(),TopElement);
						answer=answer+min(Sequence.top(),a);
						//printf("min=%d\n",min(Sequence.top(),a));
						TopElement=Sequence.top();
						Sequence.pop();
					}
				}
				if(flag==1)
				{
					answer=answer+min(Sequence.top(),q);	
				}
				else	
				{
					answer=answer+a;	
					Sequence.push(a);
				}
			}

		}
	}
	while(!Sequence.empty())
	{
		int one=Sequence.top();
		Sequence.pop();
		int two;
		if(!Sequence.empty())
		{
			two=Sequence.top();
			Sequence.pop();
			answer=answer+max(one,two);
			Sequence.push(max(one,two));
		}

	}

	printf("%lld\n",answer);
	return 0;
}
