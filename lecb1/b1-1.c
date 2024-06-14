#include <stdio.h>

#define N 10
int main(void){
    int i, j;
    double a, p;

    double x[N + 1] = {0.000, 0.100, 0.150, 0.300, 0.450, 0.550, 0.700, 0.800, 0.980, 1.100, 1.200};
    double y[N + 1] = {1.000, 1.095, 1.138, 1.251, 1.335, 1.375, 1.409, 1.414, 1.388, 1.345, 1.294};

    double x_in = 0.63;

    p = 0.0;
    for (j = 0; j <= N; j++) {
        a = 1.0;
        for(i = 0; i <= N; i++){
            if (i == j) continue;
            a *= (x_in - x[i]) / (x[j] - x[i]);
        }
        p += y[j] * a;
    }

    printf("p=%lf", p);
}