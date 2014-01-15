#include<iostream>
#include<cstdio>
#include<cstring>

using namespace std;

int matrix[1025][1025];

void update(int n,int x, int y,int val) {
	int y1;
	while(x<=n) {
		y1=y;
		while(y1<=n) {
			matrix[x][y1]+=val;
			y1+=( y1 & -y1 );
		}
		x+=( x & -x);
	}
}

int calculate_sum(int x, int y) {
	int y1,sum=0;
	while(x>0) {
		y1=y;
		while(y1>0) {
			sum+=matrix[x][y1];
			y1-= (y1 & -y1);	
		}
		x -= (x & -x);
	}
	return sum;
}

void process(int n) {

	int x1,x2,y1,y2;
	int v1,v2,v3,v4,val;
	char command[10];

	memset(matrix,0,sizeof(matrix));

	while(scanf("%s",command) == 1) {

		if(!strcmp(command,"END")) break;

		if(!strcmp(command,"SUM")) {
			scanf("%d %d %d %d",&x1,&y1,&x2,&y2);
			
			v1 = calculate_sum(x2+1,y2+1);
			v2 = calculate_sum(x2+1,y1);
			v3 = calculate_sum(x1,y1);
			v4 = calculate_sum(x1,y2+1);
			printf("%d\n",v1-v2-v4+v3);
									
		}

		if(!strcmp(command,"SET")) {
			scanf("%d %d %d",&x1,&y1,&val);
			v1 = calculate_sum(x1+1,y1+1);
                        v2 = calculate_sum(x1+1,y1);
                        v3 = calculate_sum(x1,y1);
                        v4 = calculate_sum(x1,y1+1);
                        update(n,x1+1,y1+1,val -(v1-v2-v4+v3));
		}

	}
}
int main() {
	int cases; scanf("%d",&cases);
	while(cases--) {
		int n; scanf("%d",&n);
		process(n);
		printf("\n");
	}
}
