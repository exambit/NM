#include<stdio.h>
#include<conio.h>

int main()
{
 float x[20], y[20][20];
 int i,j, n;

 // Input Section 
 printf("Enter number of data?\n");
 scanf("%d", &n);
 printf("Enter data:\n");
 for(i = 0; i < n ; i++)
 {
  printf("x[%d]=", i);
  scanf("%f", &x[i]);
  printf("y[%d]=", i);
  scanf("%f", &y[i][0]);
 }
float a ; // interpolation point
printf("\n enter the value u want to find\n");
 scanf("%f", &a);
    float h, u, sum, p;
 // Generating Forward Difference Table 
 for(i = 1; i < n; i++)
 {
  for(j = 0; j < n-i; j++)
  {
   y[j][i] = y[j+1][i-1] - y[j][i-1];
  }
 }

 // Displaying Forward Difference Table 
 printf("\nFORWARD DIFFERENCE TABLE\n\n");
 for(i = 0; i < n; i++)
 {
  printf("%0.2f", x[i]);
  for(j = 0; j < n-i ; j++)
  {
   printf("\t%0.2f", y[i][j]);
  }
  printf("\n");
 }
 p = 1.0;
    sum = y[0][0];
    h = x[1] - x[0];
    u = (a - x[0]) / h;
    for (j = 1; j < n; j++) {
        p = p * (u - j + 1) / j;
        sum = sum + p * y[0][j];
    }
    printf("\nThe value of y at x=%0.1f is %0.3f", a, sum);

 
 return 0;
}
