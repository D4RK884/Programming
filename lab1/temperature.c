#include <stdio.h>

int main() {
    double t;
    char unit;

    printf("Input temperature: ");
    if (scanf("%lf%c", &t, &unit) != 2) {
        printf("Output error\n");
        return 1;
    }

    if (unit == 'c' || unit == 'C') {
        printf("Output temperature: %.1ff\n", t * 9.0 / 5.0 + 32.0);
    } else if (unit == 'f' || unit == 'F') {
        printf("Output temperature: %.1fc\n", (t - 32.0) * 5.0 / 9.0);
    } else {
        printf("Output error\n");
    }

    return 0;
}
