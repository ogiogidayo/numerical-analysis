#include <stdio.h>
double f(double);

int main(void) {
    int n = 10000;
    double a = 0.0;
    double b = 2.0;

    double h, res;

    h = (b - a) / (double)n;

    res = 0.0;
    for (int i = 0; i < n; i++) {
        res += (f(a + i * h) + f(a + (i + 1) * h)) * h / 2;
    }
    printf("%20.20lf\n", res);

    return 0;
}

double f(double x) {
    return 2 * x * x * x * x;
}
