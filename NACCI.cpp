/*    	Ashok Kumar
	Algo : Matrix
	problem : NACCI
*/
#include<stdio.h>
#include<stdlib.h>
#include<vector>
#include<cmath>

using namespace std;
long long m[31][31],a[31][31];

long long len;

void matrix_multiply(long long  x[][31],long long  y[][31],long long mod_value)
{
	
	long long temp1[31][31],temp2[31][31];
	for(int i=0;i<len;i++)
	{
		for(int j=0;j<len;j++)
		{
			temp1[i][j]=x[i][j];
			temp2[i][j]=y[i][j];
		}
	}
	for(int i=0; i<len; i++)  {
		for(int j=0; j<len; j++) {
			m[i][j]=0;
			for(int k=0; k<len; k++) {
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
	for(int i=0; i<len; i++) {
		for(int j=0; j<len; j++) {
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
	int to_multiply[31];
	for(int i=0; i<31; i++)
		to_multiply[i]=i;
	if(len<=1||number<0)
		return 0;
	if(number<len)
		return to_multiply[number];
	declare_all();

	fib_matrix(number-len+1,mod_value);
	
	long long answer=0;
	for(int i=len-1,j=0; i>=0; j++,i--)
	{
		answer=(answer+to_multiply[len-1-j]*m[0][j])%mod_value;
	}
	return answer;
}
int main()
{
	long long mod_value,number,result,cases;
	scanf("%lld",&cases);
	while(cases--)
	{
		scanf("%lld %lld %lld",&len,&mod_value,&number);
		
		if(mod_value<=0)
		{
			printf("\n");
			continue;
		}		
		mod_value=pow(10,mod_value);

		printf("%lld\n",fibonacci(number,mod_value));
	}
	return 0;
}
