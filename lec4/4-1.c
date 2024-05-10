// 3.2
#include <stdio.h>
#include <math.h>

#define NMAX 20

double f(double x);
double df(double x);

int main(void) {
    int n = 0;
    double x = 2;
    do {
        x = - (f(x)/ df(x)) + x;
        n++;
        printf("%.201f\n", x);
    } while (n < NMAX);
}

double f(double x){
    return x * x - 5;
}

double df(double x){
    return 2 * x;
}