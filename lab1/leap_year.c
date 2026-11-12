#include <stdio.h>

int main() {
    int year;

    printf("Input year: ");
    if (scanf("%d", &year) != 1) {
        printf("error\n");
        return 1;
    }

    // Порядок проверок важен: сначала самые "сильные" правила
    if (year % 400 == 0) {
        printf("YES\n");          // делится на 400 - високосный
    } else if (year % 100 == 0) {
        printf("NO\n");           // делится на 100 (но не на 400) - не високосный
    } else if (year % 4 == 0) {
        printf("YES\n");          // делится на 4 (но не на 100) - високосный
    } else {
        printf("NO\n");           // все остальные - не високосные
    }

    return 0;
}
