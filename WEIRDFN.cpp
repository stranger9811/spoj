#include<cstdio>
#include<queue>

#define MAX 1000000007

using namespace std;
long long sum;
long long a,b,c,n,value;
int get_value(int median, int i) {
	return ( a*median + b*i+c )%MAX;
}
int main() {
	int cases;scanf("%d",&cases);
	
	while(cases--) {
		scanf("%lld %lld %lld %lld",&a,&b,&c,&n);
		priority_queue <int , vector<int> , less<int> > left;
		priority_queue <int , vector<int> , greater<int> > right;
		left.push(1);
		sum = 1;
		for(int i=1; i<n; i++) {
			 value = get_value(left.top(),i+1);	
			 
			 if(value < left.top()) {
				 if( i&1) {
					 right.push(left.top());
					 left.pop();
				 }
				 left.push(value);
			 }
			 else if (right.empty()) {
				 right.push(value);
				// printf("right is empty\n");
			 }
			 else if (left.top() <= value && right.top()>=value) {
				 if(i&1)
					 right.push(value);
				 else
					 left.push(value);
			 }
			 else {
				 if(i&1) {
					right.push(value);
					//printf("pushed in right\n");
				 }
				 else {
					// printf("pushed in right else part\n");
					// printf("case1..\n");
					 left.push(right.top());
					// printf("case2..\n");
					 right.pop();
					 right.push(value);
				 }
			 }
			// printf("value = %d,median = %d\n",value,left.top());
			 sum += value;
		}
		printf("%lld\n",sum);
	}
	return 0;
}
