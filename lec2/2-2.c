#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void) {
    int x, y;
    int count = 0;
    int max = 1, i;

    /* 乱数の種を初期化 */
    srand(time(NULL));

    for (i = 0; i < max; i++){
        x = rand() % 6;
        y = rand() % 6;;
        if( x * y == 1) count+=1;
    }
    double answer = (double)count / max;
    printf("確率 = %f", answer);
    return 0;
}