#include <stdio.h>
#include <math.h>

#define MAX_SIZE 10

float besselsInterpolation(float x, float ax[], float ay[], int n) {
    float diff[MAX_SIZE][MAX_SIZE];
    float h = ax[1] - ax[0];
    float p = (x - ax[0]) / h;
    float y = 0;

    // Calculate first order differences
    for (int i = 0; i < n; i++) {
        diff[i][1] = ay[i];
    }

    // Calculate higher order differences
    for (int j = 2; j <= n; j++) {
        for (int i = 0; i < n - j + 1; i++) {
            diff[i][j] = diff[i + 1][j - 1] - diff[i][j - 1];
        }
    }

    // Perform interpolation
    y += diff[0][1];
    float term = 1;
    for (int j = 1; j < n; j++) {
        term *= (p - j + 1) / j;
        y += term * diff[0][j + 1];
    }

    return y;
}

int main() {
    printf("\t\t !! BESSELS INTERPOLATION FORMULA !!\n\n");

    int n;
    printf("Enter the number of terms -> ");
    scanf("%d", &n);

    if (n > MAX_SIZE) {
        printf("Number of terms exceeds maximum limit.\n");
        return 1;
    }

    float ax[MAX_SIZE];
    float ay[MAX_SIZE];

    printf("\nEnter the values of x ->\n");
    for (int i = 0; i < n; i++) {
        printf("x%d: ", i + 1);
        scanf("%f", &ax[i]);
    }

    printf("\nEnter the values of y ->\n");
    for (int i = 0; i < n; i++) {
        printf("y%d: ", i + 1);
        scanf("%f", &ay[i]);
    }

    float x;
    printf("\nEnter the value of x for interpolation: ");
    scanf("%f", &x);

    float y = besselsInterpolation(x, ax, ay, n);

    printf("\nInterpolated value of y at x = %.2f is: %.8f\n", x, y);

    return 0;
}
