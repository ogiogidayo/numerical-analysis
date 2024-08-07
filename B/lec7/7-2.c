// 4次 ルンゲ・クッタ法
#include <stdio.h>

#define N 200

double f(double x, double y);

int main(void) {
    double a, b, x, y, h;

    a = 0.0;
    b = 4.0;

    h = (b - a) / (double) N;

    x = 0.0;
    y = 0.0;
    printf("%lf\t%lf\n", x, y);

    for (int i = 0; i < N; i++) {
        double k1 = h * f(x, y);
        double k2 = h * f(x + h / 2.0, y + k1 / 2.0);
        double k3 = h * f(x + h / 2.0, y + k2 / 2.0);
        double k4 = h * f(x + h, y + k3);
        y = y + (k1 + 2 * k2 + 2 * k3 + k4) / 6.0;
        x = x + h;
        printf("%lf\t%lf\n", x, y);
    }

    return 0;
}

double f(double x, double y) {
    double RC = 1 / (60e3 * 4e-6);
    float decimal_part = x - (int)x;
    double E = (decimal_part >= 0.0 && decimal_part <= 0.5) ? 1 : 0;
    return -y * RC + E * RC;
}