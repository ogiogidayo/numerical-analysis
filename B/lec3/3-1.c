#include <stdio.h>
#include <math.h>

#define M 6
#define N 4

int main(){
    int p;
    double mu, tmp, amax;

    const double x_in[M] = {0.0, 2.0, 3.0, 5.0, 7.0, 8.0};
    const double y_in[M] = {5.0, 2.0, 6.0, 9.0, 6.0, 9.0};



    double a[N][N], b[N], u[N+2];

    double aa[M], bb[M], cc[M], dd[M], uu[M];

    for (int i = 0; i < N-1; i++) {
        double h = x_in[i+1] - x_in[i];
        double h_next = x_in[i+2] - x_in[i+1];
        a[i][i] = h;
        a[i][i+1] = 2 * (h + h_next);
        if (i < N-2) {
            a[i][i+2] = h_next;
        }
    }

// ベクトルbの構築
    for (int i = 0; i < N-1; i++) {
        double y_2 = y_in[i + 2] - y_in[i + 1];
        double x_2 = x_in[i + 2] - x_in[i + 1];
        double y_1 = y_in[i + 1] - y_in[i];
        double x_1 = x_in[i + 1] - x_in[i];
        b[i] = 6 * ((y_2 / x_2) - (y_1 / x_1));
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

    for (int i = 0; i < N + 2; ++i) {
        if (i == 0 || i == N + 1) {
            u[i] = 0;
            continue;
        }
        u[i] = b[i - 1];
    }

    for (int i = 0; i < M-1; i++) {
        double h = x_in[i+1] - x_in[i];
        aa[i] = (u[i+2] - u[i+1]) / (6 * h);
        bb[i] = u[i+1] / 2;
        cc[i] = (y_in[i+1] - y_in[i]) / h - h * (2*u[i+1] + u[i+2]) / 6;
        dd[i] = y_in[i];
    }


    for (int i = 0; i < M - 1; i++) {
        printf("区間 [%lf, %lf]:\n", x_in[i], x_in[i+1]);
        printf("a = %lf\n", aa[i]);
        printf("b = %lf\n", bb[i]);
        printf("c = %lf\n", cc[i]);
        printf("d = %lf\n", dd[i]);
    }
}