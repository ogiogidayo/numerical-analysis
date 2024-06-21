#include <stdio.h>
#include <math.h>

#define M 11
#define N 2

double xSum(double* dataset, int n) {
    if (n == 0) return M;
    double sum = 0.0;
    for (int i = 0; i < M; i++) {
        sum += pow(dataset[i], n);
    }
    return sum;
}

double ySum(double* datasetx, const double* datasety, int n) {
    double sum = 0.0;
    for (int i = 0; i < M; i++) {
        sum += pow(datasetx[i], n) * datasety[i];
    }
    return sum;
}

int main(void) {
    double x_in[M] = {0.1, 0.2, 0.3, 0.4, 0.5, 0.6, 0.7, 0.8, 0.9, 1.0};
    double y_in[M] = {2.40, 2.15, 1.85, 1.75, 1.80, 1.85, 2.50, 2.35, 2.90, 3.85, 3.33};

    double a[N][N];
    double b[N];
    double x[N];
    int p;
    double mu, tmp, amax;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            a[i][j] = xSum(x_in, i + j);
        }
        b[i] = ySum(x_in, y_in, i);
    }

    for (int k = 1; k < N; ++k) {
        amax = fabs(a[k-1][k-1]);
        p = k;
        for (int i = k + 1; i <= N; i++) {
            if (fabs(a[i-1][k-1]) > amax){
                amax = fabs(a[i-1][k-1]);
                p = i;
            }
        }
        if (p != k){
            for (int j = 0; j < N; j++) {
                tmp = a[k-1][j];
                a[k-1][j] = a[p-1][j];
                a[p-1][j] = tmp;
            }
            tmp = b[k-1];
            b[k-1] = b[p-1];
            b[p-1] = tmp;
        }
        //
        for (int i = k + 1; i <= N; i++) {
            mu = -a[i - 1][k - 1] / a[k - 1][k - 1];
            for (int j = k + 1; j <= N; j++) {
                a[i - 1][j - 1] += mu * a[k - 1][j - 1];
            }
            b[i - 1] += mu * b[k - 1];
        }
    }

    b[N-1] = b[N-1]/ a[N-1][N-1];
    for (int k = N - 1; 1 <= k; k--) {
        tmp = b[k-1];
        for (int j = k + 1; j <= N; j++) {
            tmp -= a[k-1][j-1] * b[j-1];
        }
        b[k-1] = tmp / a[k-1][k-1];
    }
    for (int i = 0; i < N; i++) {
        printf("a%d=%lf\n", i, b[i]);
    }
}