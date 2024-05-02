#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void) {
    double x, y, z, pi;
    int count = 0;
    int max = 100, i;

    /* 乱数の種を初期化 */
    srand(time(NULL));

    for (i = 0; i < max; i++){
        x = (double)rand() / RAND_MAX;
        y = (double)rand() / RAND_MAX;

        z = x*x + y*y;
        if(z < 1) count++;
    }
    pi = (double)count / max * 4;
    printf("pi = %f\n", pi);
    return 0;
}