#include<string.h>
#include<stdio.h>
#include<stdlib.h>

long long  m[2][2];

/*

   fib_recursive function is used to compute b%c using recursive method

   exponential time

 */

long long  fib_recursive(long long n,long long m)

{



	if(n==1)

	{

		return 0;

	}

	if(n==2)

	{

		return 1%m;

	}

	return ((fib_recursive(n-1,m)%m)+(fib_recursive(n-2,m)%m))%m;                                //makingrecursive calls



}

/*

   fib_itterative method is used to compute b%c using itterative method

   O(n) time

   variables a,b are used to keep track of earlier two values

 */

long long fib_itterative(long long n,long long m)

{

	long long a,b,temp,i;

	a=0;

	b=1;

	b=b%m;

	if(n==2)

	{

		return b;

	}

	if(n==1)

	{

		return 0;

	}

	for(i=3;i<=n;i++)

	{

		temp=b;                                                                                                                                        //temp is used for temprorary storage

		b=a+b;

		a=temp;

		b=b%m;

		a=a%m;



	}

	return b;

}

/*

   is_valid function is used to check whether the input values are valid
   or not

   entered values must be positive

 */

int is_valid(long long a,long long b)

{

	if(a<0||b<0)

	{

		printf("please enter numbers greater than zero\n");

		return 0;

	}

	return 1;

}

/*

   matrix_multiply is used to compute multiplication of two matrixes

   and than taking mod of each element of matrix with b

 */

long long  matrix_multiply(long long  x[][2],long long  y[][2],long long
		mod_value)

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

	m[0][0]=(a[0][0]*b[0][0]+a[0][1]*b[1][0])%mod_value;

	m[0][1]=(a[0][0]*b[0][1]+a[0][1]*b[1][1])%mod_value;

	m[1][0]=(a[1][0]*b[0][0]+a[1][1]*b[1][0])%mod_value;

	m[1][1]=(a[1][0]*b[0][1]+a[1][1]*b[1][1])%mod_value;

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

/*

   declaring all 2*2 matrix element equal to zero

 */

void declare_all(long long m[][2],long long a[][2])

{





	a[0][0]=1;

	a[0][1]=1;

	a[1][0]=1;

	a[1][1]=0;

	m[0][0]=1;

	m[0][1]=1;

	m[1][0]=1;

	m[1][1]=0;

}



main()

{
	int cases,len,i;
	char b[300];
	scanf("%d",&cases);
	while(cases--)
	{

		long long a[2][2],number,result,mod_value,val;

		int check;                                                      

		declare_all(m,a);

		scanf("%s",b);
		len=strlen(b);
		val=1;
		result=0;
		for(i=len-1;i>=0;i--)
		{
			result=(result+(b[i]-'0')*val)%329616;
			val=(val*10)%329616;
		}
		if(result==0)
			result=0;
		else if (result==1)
			result=1;
		else
		{
			result=result+1;                  


			mod_value=1000000007;



			fib_matrix(a,result-2, 2000000016);
			result = m[0][0]%2000000016;
			declare_all(m,a);
			if(result > 1)
			{
				result++;
				fib_matrix(a,result-2,mod_value);
				result = m[0][0]%mod_value;
			}

		}
		printf("%lld\n",result);
	}
	return 0;
}


