/* Ashok Kumar
   Algo: Geometry
*/
#include<cstdio>
#include<cmath>
#include<cstdio>


#define PI 3.14159265

double angle(double a,double b,double c)
{
	double answer;
	answer = a*a + b*b - c*c;
	answer = answer/(2*a*b);
	answer = acos (answer) * 180.0 / PI;
	return answer;
}
double length(double x1,double y1,double x2,double y2)
{
	double len=(x1-x2)*(x1-x2)+(y1-y2)*(y1-y2);
	len=sqrt(len);
	return len;
}
double round(double x)
{
	int q=x*100+.5;
	double diff = (q)/100.0;
	return diff;
}
int main()
{
	int cases;
	double A,B,C,x1,x2,x3,y1,y2,y3,angle1,angle2,angle3;
	scanf("%d",&cases);
	for(int x=1; x<=cases;x++)
	{
		printf("Scenario #%d: ",x); 
		scanf("%lf %lf",&x1,&y1);
		scanf("%lf %lf",&x2,&y2);
		scanf("%lf %lf",&x3,&y3);
		A=length(x1,y1,x2,y2);
		B=length(x2,y2,x3,y3);
		C=length(x1,y1,x3,y3);
		angle1=angle(A,B,C);
		angle2=angle(C,B,A);
		angle3=angle(A,C,B);
		A=round(A);
		B=round(B);
		C=round(C);
		angle1=round(angle1);
		angle2=round(angle2);
		angle3=round(angle3);	
		if(A==B&&B==C&&A==C)
		{
			printf("Equilateral Equiangular");
		}
		else if(A==B || C==B || A==C)
		{
			if(angle1==90||angle2==90||angle3==90)
				printf("Isosceles Right Triangle");
			else if(angle1>90||angle2>90||angle3>90)
				printf("Isosceles Obtuse");
			else
				printf("Isosceles Acute");

		}
		else
		{
			if(angle1==90||angle2==90||angle3==90)
                                printf("Scalene Right Triangle");
			else if(angle1>90||angle2>90||angle3>90)
				printf("Scalene Obtuse");
			else
				printf("Scalene Acute");
		}
		printf("\n");
	}
	return 0;
}
