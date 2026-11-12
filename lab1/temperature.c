#include <stdio.h>

int main() {
    double t;
    char unit;

    printf("Input temperature: ");
    // Читаем число и сразу за ним символ (например 36.6c)
    if (scanf("%lf%c", &t, &unit) != 2) {
        printf("Output error\n");
        return 1;
    }

    if (unit == 'c' || unit == 'C') {
        // Цельсий -> Фаренгейт
        printf("Output temperature: %.1ff\n", t * 9.0 / 5.0 + 32.0);
    } else if (unit == 'f' || unit == 'F') {
        // Фаренгейт -> Цельсий
        printf("Output temperature: %.1fc\n", (t - 32.0) * 5.0 / 9.0);
    } else {
        printf("Output error\n");
    }

    return 0;
}
