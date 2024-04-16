#include<stdio.h>
#include<math.h>
#include<conio.h>

double F(double x)
{
	return (((x*x*x)-2*x)+1);
}
double G(double x)
{
	return (((x*x*x)+1)/2);
}

int main()
{
	int i,n;
	printf("enter no. of iterations\n");
	scanf("%d",&n);
	double x0,x1;
	printf("enter the initial guess\n");
	scanf("%f",&x0);
	for(i=0;i<=n;i++)
	{
		x1=G(x0);
		printf("\n value after x %d iteration is %f",i,x1);
		x0=x1;
	}
	printf("\n value of root after %d iterations=%1f,value of function %1f",n,x0,F(x0));
}
