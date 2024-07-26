// 修正オイラー
#include <stdio.h>

#define N 100

double f(double x, double y);

int main(void) {
    double a, b, x, y, h;

    a = 0.1;
    b = 12.0;

    h = (b - a) / (double) N;

    x = 0.1;
    y = 0.1;
    printf("%lf\t%lf\n", x, y);

    for (int i = 0; i < N; i++) {
        double k1 = h * f(x, y);
        double k2 = h * f(x + h, y + k1);
        y = y + 0.5 * (k1 + k2);
        x = x + h;
        printf("%lf\t%lf\n", x, y);
    }

    return 0;
}

double f(double x, double y) {
    return 2 * y / x;
}