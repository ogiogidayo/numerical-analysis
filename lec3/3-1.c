#include <stdio.h>
#include <math.h>

double f(double x);

int main(void){

    int count = 0;
    double a, b, c, eps;

    count = 0;

    a = 0;
    b = 4;

    eps = 0.0000001;

    do{
        c = (a + b)/2;
        if(f(a)*f(c) < 0) b = c;
        else if(f(c)*f(b) < 0) a = c;
        count ++;
        printf("%f\n",c);
    } while(fabs(b - a) > eps);
}

double f(double x){
    return (x*x-5);
}
