#include<stdio.h>
int a[200007][2];
int b_41[200007][2],b_148721[200007][2];

long long power(long long i,long long j,int mod)
{
	if(j==0)
		return 1;
	long long d;
	d=power(i,j/(long long)2,mod);
	if(j%2==0)
		return (d*d)%mod;
	else
		return ((d*d)%mod * i)%mod;
}

int inverse2(int m1,int p1)
{
	int i=1;
	while(1)
	{
		if((m1*i)%p1==1)
			return i;
		i++;
	}

}
long long inverse(int m1,int p1)
{
	return power(m1,p1-2,p1);
}

int chinese_remainder_2(long long n1,long long n2,long long n3)
{
	int p1=2,p2=1681,p3=148721;
	long long m1,m2,m3;
	long long i1,i2,i3;
	long long m;
	int ans;
	m = p1*p2*p3;
	m1 = m/p1;m2=m/p2;m3=m/p3;
	i1 = inverse(m1,p1);i2=inverse2(m2,p2);i3=inverse(m3,p3);
	//printf("i1 = %lld   i2 = %lld\n",i1,i2);
	ans = (n1*m1*i1)%m+(n2*m2*i2)%m + (n3*m3*i3)%m ;
	ans = ans%m;
	return ans;
	//printf("%d\n",ans);
}

int chinese_remainder(long long n1,long long n2)
{
	int p1=2,p2=500000003;
	long long m1,m2;
	long long i1,i2;
	long long m;
	int ans;
	m = p1*p2;
	m1 = m/p1;m2=m/p2;
	i1 = inverse(m1,p1);i2=inverse(m2,p2);
	//printf("i1 = %lld   i2 = %lld\n",i1,i2);
	ans = (n1*m1*i1)%m+(n2*m2*i2)%m ;
	ans = ans%m;
	return ans;
	//printf("%d\n",ans);
}

int main()
{
	long long i,n,r,t,t1,t2,t3,t4,t5,crt;
	int cases,A,B;
	a[0][0]=1;a[0][1]=1;
	a[1][0]=1;a[1][1]=1;
	for(i=1;i<200007;i++){
		a[i][0] = (i*a[i-1][0])%2;
		//        printf("%d\n",a[i][0]);
		a[i][1] = (i*a[i-1][1])%500000003;
	}
	b_41[0][0]=1;b_41[0][1]=0;
	b_148721[0][0]=1;b_148721[0][1]=0;
	for(i=1;i<200007;i++){
		t=i;
		b_41[i][1]=b_41[i-1][1];
		while(t%41 == 0){t=t/41;b_41[i][1]++;}
		b_41[i][0] = (t*b_41[i-1][0])%1681;

		b_148721[i][0]=(i*b_148721[i-1][0])%148721;
		b_148721[i][1]=0;
	}
	//                printf("\n");
	scanf("%d",&cases);
	while(cases--)
	{
		scanf("%d %d %lld",&A,&B,&n);
		if(A==0 && B==0)
		{
			printf("1\n");
			continue;
		}        
		t3 = (a[2*n][0]*power(a[n][0],0,2))%2;
		t3 = (t3*power(a[n][0],0,2))%2;

		t4 = (b_41[2*n][0]*inverse2(b_41[n][0],1681))%1681;
		t4 = (t4*inverse2(b_41[n][0],1681))%1681;
		t4 = (t4*power(41,b_41[2*n][1]-2*b_41[n][1],1681))%1681;
//		printf("%lld",t4);
//		return 0;
		t5 = (b_148721[2*n][0]*power(b_148721[n][0],148719,148721))%148721;
		t5 = (t5*power(b_148721[n][0],148719,148721))%148721;
		//printf("t3=%lld t4=%lld t5=%lld\n",t3,t4,t5);
		crt = chinese_remainder_2(t3,t4,t5);

		t2 = power(B,crt,500000003);
		t1 = power(B,0,2);
		//printf("crt1=%lld t1=%lld t2=%lld\n",crt,t1,t2);
		//        t2 = (a[2*n][1]*power(a[n][1],500000001,500000003))%500000003;
		//       t2 = (t2*power(a[n][1],500000001,500000003))%500000003;
		//        printf("%lld\n",t2);
		crt = chinese_remainder(t1,t2);

		//printf("A=%d crt = %d\n",A,crt);
		printf("%lld\n",power(A,crt,1000000007));
	}
	return 0;

}
