#include <stdio.h>
#include <conio.h>	
#include <math.h>
#include <process.h>
#include <string.h>

#define f(x)     3*x-cos(x)-1
#define df(x)    3+sin(x)

void New_Rap();
int main()
{
	printf("\n solution by newton raphson method\n");
	printf("\n equation is ");
	printf("\n\t\t\t 3*X-cos X-1=0\n\n");
	New_Rap();
	getch();
}
void New_Rap()
{
	 float x1,x0;
	 float f0,f1;
	 float df0;
	int i=1;
	int itr;
	float EPS;
	float error;
	for(x1=0;x1+=0.01;)
	{
		f1=f(x1);
		if(f1>0)
		{
			break;
		}
	}
	x0=x1-0.01;
	f0=f(x0);
	printf("Enter the number of iteration:\n");
	scanf("%d",&itr);
	printf("Enter the maximum possible error: \n");
	scanf("%f",&EPS);
	if(fabs(f0)>f1)
	{
		printf("\n\t\t The root is near to %.4f\n",x1);
	}
	if(f1>fabs(f(x0)))
	{
		printf("\n\t\t the root is near to %.4f\n",x0);
	}
	x0=(x0+x1)/2;
	for(;i<=itr;i++)
	{
		f0=f(x0);
		df0=df(x0);
		x1=x0-(f0/df0);
		printf("\n\t\t the %d approximation to the root is %f",i,x1);
		error=fabs(x1-x0);
		if(error<EPS)
		{
			break;
		}
		x0=x1;
		
	}
	if(error>EPS)
	{
		printf("\n\n\t NOTE:-");
		printf("The number of iterations are not sufficient");
	}
	printf("\n\n\n\t\t\t------------------------------------");
	printf("\n\t\t\t The root is %.4f",x1);
	printf("\n\t\t\t ---------------------------------------");
	
}
