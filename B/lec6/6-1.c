#include <stdio.h>

#define N 40

double f(double x, double y);
int main(void){
    double a, b, x, y, h, E;
    E = 10;

    a = 0.0;
    b = 10.0;

    h = (b - a) / (double) N;

    x = 0.0;
    y = E;
    printf("x=%lf, y = %lf\n", x, y);

    for (int i = 0; i < N; i++) {
        y = y + h * f(x, y);
        x = x + h;
        printf("x=%lf, y = %lf\n", x, y);
    }

    return 0;
}

double f (double x, double y) {
    double RC = 1 /(40e3 * 200e-6);
    return - y * RC;
}