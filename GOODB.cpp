#include<stdio.h>
long long MOD= 1000000007;
long long modulo[100000],invm[100000];
int expon(int a,int m){
	long long int a2=a,extra=1;
	while(m!=0){
		if(m%2==0){a2=(a2*a2)%MOD;m/=2;}
		else{extra=(extra*a2)%MOD;m--;}
	}
	return (extra)%MOD;
}
long long combination(long long i,long long j)
{
	long long answer;
	answer=modulo[i];
	answer=(modulo[i]*invm[j])%MOD;
	answer=(answer*invm[i-j])%MOD;
	return answer;
}
int main()
{
	int i,j,m,n;
	long long int temp=1;
	for(i=1;i<=10000;i++)
	{
		temp*=i;
		temp=temp%MOD;
		modulo[i]=temp;
	}
	temp=1;
	for(i=1;i<=10000;i++)
	{
		temp*=expon(i,MOD-2);
		temp=temp%MOD;
		invm[i]=temp;
	}
	modulo[0]=1;
	invm[0]=1;
	int N,W,R,T;
	scanf("%d %d %d %d",&N,&W,&T,&R);
	long long answer= ((combination(N,W)*combination(N-W,R))%MOD)*combination(N-W-R,T)%MOD;
	printf("%lld\n",answer);
	

	return 0;
	

}
