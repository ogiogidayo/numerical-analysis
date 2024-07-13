#include <stdio.h>

double f(double, double, double);

int main(void){

	int i, j, k;
	int n = 200, m = 200, l = 200;
	double a = 1.0, b = 2.0;
    double ya, yb, za, zb, h1, h2, h3, res, total;
	
	h1 = (b - a) / (double)n;

	total = 0.0;

    for(i = 0; i <= n; i++) {
        double x = i * h1 + a;
        ya = 3 - x;
        yb = x * x;

        h2 = (yb - ya) / (double)m;

        res = 0.0;
        for(j = 0; j <= m; j++) {
            double y = ya + j * h2;
            za = x + y;
            zb = x + y + 3;

            h3 = (zb - za) / (double)l;

            double slice = 0.0;
            for(k = 0; k <= l; k++) {
                double z = za + k * h3;
                if(k == 0 || k == l) slice += f(x, y, z);
                else slice += 2 * f(x, y, z);
            }
            slice *= (h3 / 2.0);

            if(j == 0 || j == m) res += slice;
            else res += 2.0 * slice;
        }
        res *= (h2 / 2.0);

        if(i == 0 || i == n) total += res;
        else total += 2.0 * res;
    }
	
	total *= (h1 / 2.0);
	printf("%20.20lf\n", total);

}

double f(double x, double y, double z){
	return 7.0  * x * x + 3.0 * y + z;
}

