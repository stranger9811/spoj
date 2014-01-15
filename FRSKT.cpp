#include<string.h>
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int number_of_primes;
int prime[100000],factor[100][2],A[100007];
long long periods[100007][40];
int prime_finder(int n)
{
	int k;
	int rootn,i,j,size;
	rootn=sqrt(n)+100;
	for(i=0;i<n;i++)
		A[i]=1;
	for(i=2;i<rootn;i++)
	{
		if(A[i]==1)
		{
			for(j=(i*i);j<n;j=j+i)
				A[j]=0;
		}
	}
	//printf("%d",A[5]);
	A[1]=0;
	A[0]=0;
	j=0;
	for(i=0;i<n;i++)
	{
		if(A[i])
		{
			k=1;	
			prime[j] = i;
			periods[i][0]=1;
			while(periods[i][k-1]*i <= 1000000000)
			{

				periods[i][k]=i*periods[i][k-1];
				//if(i==5)
				//	printf("%lld ",periods[i][k]);
				k++;
			}
			j++;
		}
	}
	return j;
}
int factor_finder(long long number,int size)
{
	int i,j;
	for(i=0;i<1000;i++)
		factor[i][1]=0;
	j=0;
	int trash;
	for(i=0;i<size;i++)
	{

		if(number<100000)
		{
			if(A[number]==1)
				break;

		}
		if(number==1)
			break;

		if(number%prime[i]==0)
			j++;
		while(number%prime[i]==0)
		{
			factor[j-1][0]=prime[i];
			number=number/prime[i];
			factor[j-1][1]++;
		}
	}

	if(number!=1)
	{
		factor[j][0]=number;
		factor[j][1]=1;
		j++;
	}
	return j;
}

long long  m[2][2];

long long  matrix_multiply(long long  x[][2],long long  y[][2],long long mod_value)
{
	long long  i,j;
	long long a[2][2],b[2][2];
	for(i=0;i<2;i++)
	{
		for(j=0;j<2;j++)
		{
			a[i][j]=x[i][j];
			b[i][j]=y[i][j];
		}
	}
	m[0][0]=((a[0][0]*b[0][0])%mod_value+(a[0][1]*b[1][0])%mod_value)%mod_value;
	m[0][1]=((a[0][0]*b[0][1])%mod_value+(a[0][1]*b[1][1])%mod_value)%mod_value;
	m[1][0]=((a[1][0]*b[0][0])%mod_value+(a[1][1]*b[1][0])%mod_value)%mod_value;
	m[1][1]=((a[1][0]*b[0][1])%mod_value+(a[1][1]*b[1][1])%mod_value)%mod_value;
	return        i;
}

long long fib_matrix(long long a[][2],long long n,long long mod_value)

{
	if(n==1)
		return 0;
	if(n%2==0)
	{
		fib_matrix(a,n/2,mod_value);
		matrix_multiply(m,m,mod_value);
		return 0;
	}
	if(n%2!=0)
	{
		fib_matrix(a,n/2,mod_value);
		matrix_multiply(m,m,mod_value);
		matrix_multiply(m,a,mod_value);
		return 0;
	}

}

void declare_all(long long m[][2],long long a[][2])
{
	a[0][0]=1; a[0][1]=1;a[1][0]=1;a[1][1]=0;
	m[0][0]=1;m[0][1]=1;m[1][0]=1;m[1][1]=0;
}

long long gcd(long long m, long long n)
{
	long long tmp;
	while(m) { tmp = m; m = n % m; n = tmp; }       
	return n;
}

long long lcm(long long m, long long n)
{
	return m / gcd(m, n) * n;
}

long long periodicity(long long mod_value)
{
	int i=0,count=0;
	//printf("periodicity begins %lld\n",mod_value);
	int number_of_factors = factor_finder(mod_value,number_of_primes);
	long long pie[number_of_factors],answer=1;	
	for(i=0;i<number_of_factors;i++)
	{
		//printf("%lld %lld\n",factor[i][0],factor[i][1]);
		if(factor[i][0] >= 100000)
		{
			if(factor[i][0]%5 == 0)
				pie[i] = 20;
			else if(factor[i][0]%5==2 || factor[i][0]%5==3)
				pie[i] = 2*factor[i][0] + 2;
			else if(factor[i][0]%5==1 || factor[i][0]%5==4)
				pie[i] = factor[i][0] - 1;

		}
		else
		{	
			if(factor[i][0]%5 == 0)
			{
				pie[i] = 20;
				//printf("%lld\n",periods[5][3]);
				pie[i] = pie[i]*periods[factor[i][0]][factor[i][1]-1];
			}
			else if(factor[i][0]%5==2 || factor[i][0]%5==3)
			{

				pie[i] = 2*factor[i][0] + 2;
				pie[i] = pie[i]*periods[factor[i][0]][factor[i][1]-1];
			}	
			else if(factor[i][0]%5==1 || factor[i][0]%5==4)
			{

				pie[i] = factor[i][0] - 1;
				pie[i] = pie[i]*periods[factor[i][0]][factor[i][1]-1];
			}
		}


	}
	//printf("hiiiiiii\n");
	answer = pie[0];
	for(i=1;i<number_of_factors;i++)
	{

		answer = lcm(answer,pie[i]);
	}


	return answer;
}

main()

{
	number_of_primes = prime_finder(100000);
	int cases,i;
	long long k,n,mod_value;
	long long t[102];
	scanf("%d",&cases);
	while(cases--)
	{

		long long a[2][2],number,result,mod_value,val;
		int check;                                                      
		declare_all(m,a);
		scanf("%lld %lld %lld",&k,&n,&mod_value);
		t[0] = mod_value;
		for(i=1;i<=k;i++)
		{
			t[i] = periodicity(mod_value);
			mod_value = t[i];
		}
		//printf("%lld %lld\n",n,t[k]);
		n = n%t[k];
		//printf("%lld\n",n);
		//return 0;
		for(i=k-1;i>=0;i--)
		{
			declare_all(m,a);
			//			printf("%lld %lld\n",t[i],n);
			if(n==0)
				n=0;
			else if (n==1)
				n=1;
			else
			{
				n=n+1;	
				//printf("%lld %lld\n",t[i],n);	
				fib_matrix(a,n-2, t[i]);
				n = m[0][0];
				//printf("%lld %lld\n",t[i],n);
				//printf("%lld %lld\n",t[i],n);
			}	
		}
		printf("%lld\n",n);


	}
	return 0;
}


