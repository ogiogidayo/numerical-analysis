#include <stdio.h>

#define N 4

int main(void) {
    int i, j, k;
    double mu, tmp;

    double a[4][4] = {{4.0, 2.0, 4.0, 2.0}, {6.0, -6.0, 6, 12}, {4, 3, 3, -3}, {1, 2, -1, 1}};
    double b[4] = {6, 18, -0.5, 5.0};

    for (k = 1; k < N; ++k) {
        for (i = k + 1; i <= N; i++) {
            mu = -a[i - 1][k - 1] / a[k - 1][k - 1];
            for (j = k + 1; j <= N; j++) {
                a[i - 1][j - 1] += mu * a[k - 1][j - 1];
            }
            b[i - 1] += mu * b[k - 1];
        }
    }

    b[N-1] = b[N-1]/ a[N-1][N-1];
    for (k = N - 1; 1 <= k; k--) {
        tmp = b[k-1];
        for (int j = k + 1; j <= N; j++) {
            tmp -= a[k-1][j-1] * b[j-1];
        }
        b[k-1] = tmp / a[k-1][k-1];
    }
    for (i = 0; i < N; i++) {
        printf("x%d=%lf\n", i+1, b[i]);
    }

}