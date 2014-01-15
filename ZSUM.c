#include<stdio.h>
long long int modular(long long int,long long int);
int main()
{
    long long int n,k,q,z;
    int r=10000007;
    scanf("%lld",&n);
    scanf("%lld",&k);
    while(n||k)
    {
        long long int z0=(modular(n,k)+modular(n,n))%r;
        //z0=z0%r;
        long long int z1=(2*modular(n-1,k)+2*modular(n-1,n-1))%r;
       // z1=z1%r;


        long long int c=(z0+z1)%r;
        printf("%lld\n",c);
        scanf("%lld",&n);
        scanf("%lld",&k);
    }
    return 0;
}
/*int modular(int x,int y)
{
    int l=1,t=1;
    int r=10000007;
    while(l<=y)
    {
        t=(x*t)%r;
        l=l+1;
    }
    return t;
}*/
long long int modular(long long int x,long long int y)
{
    long long int r=10000007;
    long long int result= 1;
    while(y>0)
    {
        if(y%2==1){
            result=(result*x)%r;
        }
        y=y>>1;
        x=(x*x)%r;
    }
    return result%r;
}

