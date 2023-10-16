#include <stdio.h>
#include <math.h>

int main() {
    double a, b, c;

    scanf("%lf %lf %lf", &a, &b, &c);
    double d = b * b - 4 * a * c;

    if (d < 0) {
        printf("NO SOLUTION\n");
    } else if (d == 0) {
        double x0 = -b / (2 * a);
        printf("%.2lf\n", x0);
    } else {
        double x1 = (-b - sqrt(d)) / (2 * a);
        double x2 = (-b + sqrt(d)) / (2 * a);
        printf("%.2lf %.2lf\n", x1, x2);
    }

    return 0;
}