#include <stdio.h>

#define N 10

double f(double x, double y);

int main(void){
    double a, b, x, y, h;

    a = 0.0;
    b = 1.0;

    h = (b - a) / (double) N;

    x = 0.0;
    y = 1.0;
    printf("x=%lf, y = %lf\n", x, y);

    for (int i = 0; i < N; i++) {
        y = y + h * f(x, y);
        x = x + h;
        printf("x=%lf, y = %lf\n", x, y);
    }

    return 0;
}

double f (double x, double y) {
    return x + y;
}