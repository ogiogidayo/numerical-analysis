#include <stdio.h>

#define N 4

int main(void) {
    int i, j, k = 1;

    double a[N][N] = {{10, -2, -1, -1}, {-2, 10, -1, -1}, {-1, -1, 10, -2}, {-1, -1, -2, 10}};
    double b[N] = {3, 15, 27, -9};
    double x[N] = {0.0, 0.0, 0.0, 0.0};
    double xn[N];

    do {
        printf("%d: ", k);

        for (i = 0; i < N; i++) {
            xn[i] = b[i];
            for (j = 0; j < N; ++j) {
                xn[i] -= a[i][j] * x[j];
            }
            xn[i] += a[i][i] *x[i];
            xn[i] /= a[i][i];
            x[i] = xn[i];
        }
        for (i = 0; i < N; ++i) {
            printf("%20.20lf", x[i]);
        }
        printf("\n");
        k++;
    } while (k < 100);

    return 0;
}
