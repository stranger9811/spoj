#include<queue>
#include<cstdio>

using namespace std;
int main() {
	int cases,n;scanf("%d",&cases);
	while(cases--) {
		scanf("%d",&n);
		queue <int> A;
		vector <int> B;
		int C[20005];
		for(int i=1; i<=n; i++)
			A.push(i);
		for(int i=1; i<=n; i++)	{
			int j=i;
			while(j--) {
				int val=A.front();
				A.pop();
				A.push(val);
			}
			int val=A.front();
                        A.pop();
			B.push_back(val);
		}
		for(int i=1; i<=n; i++)
			C[B[i-1]]=i;
		for(int i=1;i<=n; i++)
			printf("%d ",C[i]);
		printf("\n");
	}
	return 0;
}
