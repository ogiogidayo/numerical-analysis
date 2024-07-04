#include <stdio.h>
#include <math.h>

#define M 6
#define N (M-2)

int main(){
    int p;
    double mu, tmp, amax;

    const double x_in[M] = {0.0, 2.0, 3.0, 5.0, 7.0, 8.0};
    const double y_in[M] = {5.0, 2.0, 6.0, 9.0, 6.0, 9.0};

    double a[N][N] = {0}, b[N] = {0}, u[N+2] = {0};
    double aa[M] = {0}, bb[M] = {0}, cc[M] = {0}, dd[M] = {0}, uu[M] = {0};

    for (int i = 0; i < N; i++) {
        double h = x_in[i+1] - x_in[i];
        double h_next = x_in[i+2] - x_in[i+1];
        a[i][i] = 2 * (h + h_next);
        if (i != 0) {
            a[i][i-1] = h;
        }
        if (i != N-1) {
            a[i][i+1] = h_next;
        }
    }

    for (int i = 0; i < N; i++) {
        double y_2 = y_in[i + 2] - y_in[i + 1];
        double x_2 = x_in[i + 2] - x_in[i + 1];
        double y_1 = y_in[i + 1] - y_in[i];
        double x_1 = x_in[i + 1] - x_in[i];
        b[i] = 6 * ((y_2 / x_2) - (y_1 / x_1));
    }

    for (int k = 0; k < N; ++k) {
        amax = fabs(a[k][k]);
        p = k;
        for (int i = k + 1; i < N; i++) {
            if (fabs(a[i][k]) > amax){
                amax = fabs(a[i][k]);
                p = i;
            }
        }
        if (p != k){
            for (int j = 0; j < N; j++) {
                tmp = a[k][j];
                a[k][j] = a[p][j];
                a[p][j] = tmp;
            }
            tmp = b[k];
            b[k] = b[p];
            b[p] = tmp;
        }
        for (int i = k + 1; i < N; i++) {
            mu = -a[i][k] / a[k][k];
            for (int j = k; j < N; j++) {
                a[i][j] += mu * a[k][j];
            }
            b[i] += mu * b[k];
        }
    }

    for (int k = N - 1; k >= 0; k--) {
        tmp = b[k];
        for (int j = k + 1; j < N; j++) {
            tmp -= a[k][j] * b[j];
        }
        b[k] = tmp / a[k][k];
    }

    for (int i = 1; i <= N; ++i) {
        u[i] = b[i - 1];
    }
    u[0] = 0;
    u[N+1] = 0;

    for (int i = 0; i < M-1; i++) {
        double h = x_in[i+1] - x_in[i];
        aa[i] = (u[i+1] - u[i]) / (6 * h);
        bb[i] = u[i] / 2;
        cc[i] = (y_in[i+1] - y_in[i]) / h - h * (u[i+1] + 2 * u[i]) / 6;
        dd[i] = y_in[i];
    }

    for (int i = 0; i < M - 1; i++) {
        printf("区間 [%lf, %lf]:\n", x_in[i], x_in[i+1]);
        printf("a = %lf\n", aa[i]);
        printf("b = %lf\n", bb[i]);
        printf("c = %lf\n", cc[i]);
        printf("d = %lf\n", dd[i]);
    }

    return 0;
}
