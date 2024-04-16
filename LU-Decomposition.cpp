/*#include<stdio.h>
#include<conio.h>
int main()
{
    float A[20][20]= {0},L[20][20]= {0}, U[20][20];
    float B[20]= {0}, X[20]= {0},Y[20]= {0};
    int i,j,k,n;
    printf("Enter the order of square matrix: ");
    scanf("%d",&n);
    printf("\nEnter matrix element:\n");
    for(i=0; i<n; i++)
    {
        for(j=0; j<n; j++)
        {
            printf("Enter A[%d][%d] element: ", i,j);
            scanf("%f",&A[i][j]);
        }
    }
    printf("\nEnter the constant terms: \n");
    for(i=0; i<n; i++)
    {
        printf("B[%d]",i);
        scanf("%f",&B[i]);
    }
    for(j=0; j<n; j++)
    {
        for(i=0; i<n; i++)
        {
            if(i<=j)
            {
                U[i][j]=A[i][j];
                for(k=0; k<i-1; k++)
                    U[i][j]-=L[i][k]*U[k][j];
                if(i==j)
                    L[i][j]=1;
                else
                    L[i][j]=0;
            }
            else
            {
                L[i][j]=A[i][j];
                for(k=0; k<=j-1; k++)
                    L[i][j]-=L[i][k]*U[k][j];
                L[i][j]/=U[j][j];
                U[i][j]=0;
            }
        }
    }
    printf("[L]: \n");
    for(i=0; i<n; i++)
    {
        for(j=0; j<n; j++)
            printf("%9.3f",L[i][j]);
        printf("\n");
    }
    printf("\n\n[U]: \n");
    for(i=0; i<n; i++)
    {
        for(j=0; j<n; j++)
            printf("%9.3f",U[i][j]);
        printf("\n");
    }
    for(i=0; i<n; i++)
    {
        Y[i]=B[i];
        for(j=0; j<i; j++)
        {
            Y[i]-=L[i][j]*Y[j];
        }
    }
    printf("\n\n[Y]: \n");
    for(i=0; i<n; i++)
    {
        printf("%9.3f",Y[i]);
    }
    for(i=n-1; i>=0; i--)
    {
        X[i]= Y[i];
        for(j=i+1; j<n; j++)
        {
            X[i]-=U[i][j]*X[j];
        }
        X[i]/=U[i][i];
    }
    printf("\n\n[X]: \n");
    for(i=0; i<n; i++)
    {
        printf("%9.3f",X[i]);
    }
    return(0);
}*/

#include<stdio.h>

 int main()
 {
 	float a[10][10],l[10][10],u[10][10],z[10],x[10],b[10];
 	int i,j,k,n;

 	printf("\nEnter the size of the coefficient matrix: ");
 	scanf("%d",&n);
 	printf("Enter the elements row-wise: ");
 	for(i=0;i<n;i++)
 		for(j=0;j<n;j++)
 			scanf("%f",&a[i][j]);
 	printf("Enter the right hand vector: ");
 	for(i=0;i<n;i++)
 		scanf("%f",&b[i]);

 	//Computation oof L and U matrices
 	for(i=0;i<n;i++)
 		l[i][1]=a[i][1];
 	for(j=2;j<=n;j++)
 		u[1][j]=a[1][j]/l[1][1];
 	for(i=0;i<n;i++)
 		u[i][i]=1;
 	for(i=2;i<=n;i++)
 		for(j=2;j<=n;j++)
 			if(i>=j)
 			{
 				l[i][j]=a[i][j];
 				for(k=1;k<=j-1;k++)
 					l[i][j]-=l[i][k]*u[k][j];
 			}
 			else
 			{
 				u[i][j]=a[i][j];
 				for(k=1;k<=j-1;k++)
 					u[i][j]=-l[i][k]*u[k][j];
 				u[i][j]/=l[i][i];
 			}
 		printf("\nThe lower triangular matrix L: \n");
 		for(i=0;i<=n;i++)
 		{
 			for(j=0;j<n;j++)
 				printf("%f ",l[i][j]);
 			printf("\n");
 		}
 		printf("\nThe upper triangular matrix U: \n");
 		for(i=0;i<=n;i++)
 		{
 			for(j=0;j<i;j++)
 				printf(" ");
 			for(j=i;j<n;j++)
 				printf("%f ",l[i][j]);
 			printf("\n");
 		}

 		//solve Lz=b by forward substitution
 		z[1]=b[1]/l[1][1];
 		for(j=1;i<n;i++)
 		{
 			z[i]=b[i];
 			for(j=0;j<i-1;j++)
 				z[i]-=l[i][j]*z[j];
 			z[i]/=l[i][i];
 		}

 		//solve Ux=z by backward substitution
 		x[n]=z[n];
 		for(i=n-1;i>=0;i--)
 		{
 			x[i]=z[i];
 			for(j=i+1;j<n;j++)
 				x[i]-=u[i][j]*x[j];
 		}
 		printf("The solution is: ");
 		for(i=0;i<n;i++)
 			printf("%f ",x[i]);
 			
 			return(0);
 }
