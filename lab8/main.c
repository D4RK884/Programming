#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void matrix(int *matrix, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%3d ", matrix[i * n + j]);
        }
        printf("\n");
    }
}

int main() {
    srand(time(NULL));

    int n;
    printf("Введите размер матрицы n: ");
    if (scanf("%d", &n) != 1 || n <= 0) {
        printf("Неправильный ввод\n");
        return 1;
    }

    int *a = (int*)malloc(n * n * sizeof(int));
    int *b = (int*)malloc(n * n * sizeof(int));
    int *orig = (int*)malloc(n * n * sizeof(int));

    if (a == NULL || b == NULL || orig == NULL) {
        printf("Ошибка выделения памяти\n");
        free(a);
        free(b);
        free(orig);
        return 1;
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int val = rand() % 99 + 1;
            a[i * n + j] = val;
            orig[i * n + j] = val;
        }
    }

    printf("\nИсходная матрица\n");
    matrix(a, n);

    for (int step = 1; step <= 4; step++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                b[j * n + (n - 1 - i)] = a[i * n + j];
            }
        }

        printf("\nПоворот на %d градусов:\n", step * 90);
        matrix(b, n);

        for (int i = 0; i < n * n; i++) {
            a[i] = b[i];
        }
    }


    int is_equal = 1; 
    for (int i = 0; i < n * n; i++) {
        if (b[i] != orig[i]) {
            is_equal = 0;
            break;
        }
    }


    if (is_equal) {
        printf("\nМатрица совпала с исходной\n");
    } else {
        printf("\nЭлементы не совпали\n");
    }

    free(a);
    free(b);
    free(orig);

    return 0;
}