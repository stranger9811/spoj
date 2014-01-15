#include<stdio.h>
#include<stdlib.h>
#include<vector>
#include<cmath>

using namespace std;
long long m[2][2],a[2][2];

void matrix_multiply(long long  x[][2],long long  y[][2],long long mod_value)
{
	
	long long temp1[2][2],temp2[2][2];
	for(int i=0;i<2;i++)
	{
		for(int j=0;j<2;j++)
		{
			temp1[i][j]=x[i][j];
			temp2[i][j]=y[i][j];
		}
	}
	for(int i=0; i<2; i++)  {
		for(int j=0; j<2; j++) {
			m[i][j]=0;
			for(int k=0; k<2; k++) {
				m[i][j]= (m[i][j]+temp1[i][k]*temp2[k][j])%mod_value;
			}
		}
	}
}

long long fib_matrix(long long n,long long mod_value)
{
	
	if(n==0)
		return 0;                                                                    //Base Case
	if(n==1)
		return 1;							//Bases Case
	else if(n%2==0)
	{
		fib_matrix(n/2,mod_value);
		matrix_multiply(m,m,mod_value);	
	}	
	else if(n%2!=0)
	{
		fib_matrix(n/2,mod_value);
		matrix_multiply(m,m,mod_value);
		matrix_multiply(m,a,mod_value);
	}	
}

void declare_all()
{
	for(int i=0; i<2; i++) {
		for(int j=0; j<2; j++) {
			if(i==0) {
				a[i][j]=1;m[i][j]=1;
			}
			else {
				if(j==i-1) {
					a[i][j]=1;m[i][j]=1;
				}
				else {
					a[i][j]=0;m[i][j]=0;	
				}
			}
		}
	}	
}
long long fibonacci(long long number , long long mod_value)
{
	if(number==0)
		return 1;
	if(number==1)
		return 2;
	declare_all();

	fib_matrix(number-2+1,mod_value);
	return m[0][0]*2+m[0][1];
}
int main()
{
	long long mod_value,number,result,cases;
	scanf("%lld",&cases);
	while(cases--)
	{
		scanf("%lld",&number);

		printf("%lld\n",fibonacci(number,1000000007));
	}
	return 0;
}
