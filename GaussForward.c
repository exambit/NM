#include <stdio.h>

double gaussForward(double x[], double y[], int n, double x0) {
    int i, j;
    double h, u, p = 1.0, sum = y[0];

    // Check if number of terms is valid
    if (n <= 0) {
        printf("Invalid number of terms\n");
        return -1;
    }

    // Calculate constant difference
    h = x[1] - x[0];

    // Build the divided difference table (optional for visualization)
    /*
    for (i = 0; i < n; i++) {
        printf("%lf ", x[i]);
        for (j = 0; j <= i; j++) {
            // Divided differences can be calculated here
            printf("%.2lf ", y[i]);
        }
        printf("\n");
    }
    */

    // Find the index of the interval containing x0
    for (i = 0; i < n - 1; i++) {
        if (x0 >= x[i] && x0 <= x[i + 1]) {
            break;
        }
    }

    // Check if x0 is outside the range of interpolation
    if (i == n - 1) {
        printf("Value of x is outside the range of interpolation\n");
        return -1;
    }

    // Calculate u
    u = (x0 - x[i]) / h;

    // Apply Gauss Forward Interpolation formula
    for (j = 1; j < n - i; j++) {
        p *= (u - j + 1) / j;
        sum += p * y[i + j];
    }

    return sum;
}

int main() {
    int n, i;
    double x[10], y[10], x0, result;

    printf("Enter the number of terms: ");
    scanf("%d", &n);

    printf("Enter the values of x in increasing order:\n");
    for (i = 0; i < n; i++) {
        scanf("%lf", &x[i]);
    }

    printf("Enter the corresponding values of y:\n");
    for (i = 0; i < n; i++) {
        scanf("%lf", &y[i]);
    }

    printf("Enter the value of x for which you want to interpolate: ");
    scanf("%lf", &x0);

    result = gaussForward(x, y, n, x0);

    if (result != -1) {
        printf("Interpolated value of f(%.2lf) = %.4lf\n", x0, result);
    }

    return 0;
}
	
