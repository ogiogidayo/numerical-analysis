#include <stdio.h>
#include <math.h>

#define N 4

int main(void) {
    int i, j, k, p;
    double mu, tmp, amax;

    double a[4][4] = {{2.0, 4.0, 1.0, -3.0}, {-1.0, -2.0, 2.0, 4.0}, {4, 2, -3, 5}, {5, -4, -3, 1}};
    double b[4] = {2, 20, 4.0, 12};

    for (k = 1; k < N; ++k) {
        //
        amax = fabs(a[k-1][k-1]);
        p = k;
        for (i = k + 1; i <= N; i++) {
            if (fabs(a[i-1][k-1]) > amax){
                amax = fabs(a[i-1][k-1]);
                p = i;
            }
        }
        if (p != k){
            for (j = 0; j < N; j++) {
                tmp = a[k-1][j];
                a[k-1][j] = a[p-1][j];
                a[p-1][j] = tmp;
            }
            tmp = b[k-1];
            b[k-1] = b[p-1];
            b[p-1] = tmp;
        }
        //
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