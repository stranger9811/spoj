/*
Author :-  Ashok Kumar    (11164)
We are assuming that the input expression is correct and do not consist of any long long int ing number like 4.0
Input only contains long long int iger
 */
#include<stdio.h>                                                               	
#include<stdlib.h>													
long long int  x=1,y=1;										
long long int  power(long long int  num1,long long int  num2)							//power used to calculate powers like 2^2=4
{
	long long int  num3;
	long long int  i;
	num3=1;
	for(i=0;i<num2;i++)								//multiplying num1 num2 times
		num3=num3*num1;
	return num3;									//returning answer num1^num2
}	
struct node										//node used in stack having isnumber which denoted that this node 
{											//is used in Ostack or Nstack
	char operator;									//operator stores operator if node is of Ostack other wise '\0'
	long long int  number;									//number stores number if node is of Nstack otherwise -3
	long long int  isnumber;									// 1 if node is for number 0 if node used in Ostack
	struct node *prev;								//polong long int er polong long int s to lower node
};	
struct node *push(struct node *head,long long int  number,char operator,long long int  isnumber)		//push function adds a node to stack
{
	struct node *new_node;
	new_node = (struct node *)malloc(sizeof(struct node));				//creating new node 
	new_node->prev=head;
	new_node->number=number;
	new_node->operator=operator;
	new_node->isnumber=isnumber;
	head=new_node;
	return head;
}
long long int  InsideStackPriority(char operator)							//inside priorites and outside priorites of operators are used to solve 
{											//problems with different operators like ^ and brackets and = operator
	if(operator=='-'||operator=='+')
		return 1;
	if(operator=='/'||operator=='*')
		return 1;
	if(operator=='^')
		return 3;
	if(operator=='('||operator=='=')
		return 0;
	if(operator=='$')
		return -1;
}
long long int  OutsideStackPriority(char operator)
{
	if(operator=='-'||operator=='+')
		return 1;
	if(operator=='/'||operator=='*')
		return 1;
	if(operator=='^')                       					//here priority of ^ in insidestack and outsidestack is different is different
		return 4;								//becaused ^ is right associative
	if(operator=='('||operator=='=')
		return 5;
}
long long int  ApplyOperator(long long int  num1,long long int  num2,char operator)  				//this function returns num1(operator)num2
{
	long long int  z;
	if(num2==-1)									//we stored -1 to denote x 
		num2=x;
	if(num2==-2)									//we store -2 to denote y
		num2=y;
	if(operator=='=')								//assigning value to x or y in case of '=' operator
	{											
		if(num1==-1)								//storing value of expression to right side of '=' long long int o x
			x=num2;
		if(num1==-2)								//storing long long int o y
			y=num2;		
		return num2;
	}
	if(num1==-1)
		num1=x;
	if(num1==-2)
		num1=y;
	if(operator=='+')								//applying operator to number and storing result in z
		z= num1+num2;
	if(operator=='-')
		z= num1-num2;
	if(operator=='*')
		z= num1*num2;
	if(operator=='/')
		z= num1/num2;
	if(operator=='^')
		z= power(num1,num2);							//power function calculates num1^num2
	return z;									//returning final value
}									
struct node *pop(struct node *head)                          				//pop function deletes upper node and returns polong long int er to lower node
{
	struct node *head1;
	head1=head->prev;
	head->prev=NULL;
	free(head);
	head=head1;
	return head;
}
long long int  topN(struct node *head)                                          			//Return topmost number stored by Nstack 
{
	return head->number;
}
char topO(struct node *head)								//returns topmost operator stored by Ostack
{
	return head->operator;
}
struct node *Execute(struct node *Nstack,char operator)					//Execute function takes Nstack and operator(which we are going to apply)
{											//This function  pops two numbers from stack and applies that operator on two 
	long long int  number1,number2,number3;							//numbers and than puts value of  n1(operator)n2 in stack again.
	number2=topN(Nstack);
	Nstack=pop(Nstack);
	number1=topN(Nstack);
	Nstack=pop(Nstack);
	number3=ApplyOperator(number1,number2,operator);
	Nstack=push(Nstack,number3,'\0',1);
	return Nstack;									//and finally we return the address of Nstack after making changes to it
}
int  main()
{
	long long int  cases,q=0;
	scanf("%lld",&cases);
	while(cases--)
	{	
		struct node *Nstack;	
		struct node *Ostack;
		char a;		
		char operator;									
		long long int  number;									//numbers used in program for different purpose
		Ostack=NULL;									//In starting polong long int ing to NULL
		Nstack=NULL;
		if(q==0)
		{
			scanf("%c",&a);
			q=50;

		}
		Ostack=push(Ostack,-3,'$',0);							//In starting pushing $ which denotes operator stack is finished or not
		while(1)									//This loop breaks whenever we encounter '\n' character
		{
			scanf("%c",&a);
			if(a==' '||a=='\n')
				continue;

			if(a>='0'&&a<='9')							//case when we encounter a number
			{
				number=a-'0';							//storing number as long long int iger
				scanf("%c",&a);		
				while(a==' '||a=='=')
					scanf("%c",&a);
				while(a>='0'&&a<='9')		
				{
					number=number*10 + a-'0';
					scanf("%c",&a);
					while(a==' '||a=='=')
						scanf("%c",&a);
				}
				Nstack=push(Nstack,number,'\0',1);
			}
			if(a=='\n')                              						
			{
				while(topO(Ostack)!='$')	
				{
					operator=topO(Ostack);
					Ostack=pop(Ostack);
					Nstack=Execute(Nstack,operator);
				}
				break;		 
			}
			if(a==')')	
			{
				while(topO(Ostack)!='(')	
				{
					operator=topO(Ostack);			
					Ostack=pop(Ostack);
					Nstack=Execute(Nstack,operator);
				}
				Ostack=pop(Ostack);	
			}
			else
			{
				while(InsideStackPriority(Ostack->operator)>=OutsideStackPriority(a)) 
				{							
					operator=topO(Ostack);						
					Ostack=pop(Ostack);
					Nstack=Execute(Nstack,operator);
				}
				Ostack=push(Ostack,-3,a,0);    			
			}
		}
		printf("%lld\n",Nstack->number);
	}
	return 0;			
}	


