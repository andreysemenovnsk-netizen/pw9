#include <stdio.h>
#include "matrixfunc.h"
#include <stddef.h>
#include <locale.h>

#define MAX_ROWS 50
#define MAX_COLS 50

void buffer_clearing(void){
    int c;
    while ((c = getchar()) != '\n' && c != EOF) {}
}
static int input_number(const char *message, int *meaning){
    setlocale(LC_ALL, "ru_RU.UTF-8");
    int res;
    while(1){
        printf("%s", message);
        res = scanf("%d", meaning);
        if (res == EOF){
            return 0;
        }
        if (res == 1){
            buffer_clearing();
            return -1;
        }
        printf("Ошибка ввода! нужно целое число\n");
        buffer_clearing();
    }
}

int set_matrix_size(size_t *rows, size_t *cols){
    setlocale(LC_ALL, "ru_RU.UTF-8");
    int r, c;

    if(input_number("Введите количество строк(1-50): ", &r) == 0){
        return 0;
    }

    if(input_number("Введи количество столбцов(1-50): ", &c) == 0){
        return 0;
    }

    if(r <= 0 || r > MAX_ROWS || c <= 0 || c > MAX_COLS){
        printf(" размер Строк и столбцов должны быть в даипозоне(1-50)\n");
        return -1;
    }
    *rows = (size_t)r;
    *cols = (size_t)c;
    printf("Рамзеры матрицы установлены: [%zu] x [%zu]\n", *rows, *cols);
    return 1;
}

int fill_the_matrix(int *matptr, size_t rows, size_t cols){
    setlocale(LC_ALL, "ru_RU.UTF-8");
    for(size_t i = 0; i < rows; i++){
        for(size_t j = 0; j < cols; j++){
            printf("Элемент [%zu][%zu]: ", i, j);
            if (input_number("", matptr + i * cols + j) == 0){
                return 0;
            }
        }
    }
    printf("Матрица успешно заполнена\n");
    return 1;
}

void show_matrix(const int* matptr, size_t rows, size_t cols) {
    setlocale(LC_ALL, "ru_RU.UTF-8");
    printf("\nМатрица (значение [адрес в памяти]):\n");
    for(size_t i = 0; i < rows; i++){
        for(size_t j = 0; j < cols; j++){
            const int *elem_ptr = matptr + i * cols + j;
            printf("%6d [%p] ", *elem_ptr, (void *)elem_ptr);
        }
        printf("\n");
    }
}

void summ_of_elements_colum_matrix(const int *matptr, size_t rows, size_t cols, int *col_sums){
    for(size_t j = 0; j < cols; j++){
        int quantit = 0;
        for(size_t i = 0; i < rows; i++){
            quantit += *(matptr + i * cols + j);
        }
        *(col_sums + j) = quantit;
    }
}

size_t numbers_below_k(const int *matptr, size_t rows, size_t cols, int k){
    size_t count = 0;
    for (size_t i = 0; i < rows; i++){
        for(size_t j = 0; j < cols; j++){
            if(*(matptr + i * cols + j) < k){
                count++;
            }
        }
    }
    return count;
}

int summ_cols_range(const int *matptr, size_t rows, size_t cols, size_t k, size_t m){
    int sum = 0;
    for(size_t i = 0; i < rows; i++){
        for(size_t j = k; j <= m; j++){
            sum += *(matptr + i * cols + j);
        }
    }
    return sum;
}

void read_summ_of_elements_colum_matrix(const int *matptr, size_t rows, size_t cols){
    setlocale(LC_ALL, "ru_RU.UTF-8");
    int col_sum[MAX_COLS];
    summ_of_elements_colum_matrix(matptr, rows, cols, col_sum);
    printf("Суммы элементов по столбцам:\n");
    for (size_t j = 0; j < cols; j++){
        printf("Столбец %zu: %d\n", j, *(col_sum + j));
    }
}

void read_numbers_below_k(const int *matptr, size_t rows, size_t cols){
    setlocale(LC_ALL, "ru_RU.UTF-8");
    int k;
    if (input_number("Введите пороговое значение k: ", &k) == 0){
        printf("\nВвод прерван (EOF)б\n");
        return;
    }
    size_t count = numbers_below_k(matptr, rows, cols, k);
    printf("Количество элементов строго меньше %d: %zu\n", k, count);
}
void read_summ_cols_range(const int *matptr, size_t rows, size_t cols){
    setlocale(LC_ALL, "ru_RU.UTF-8");
    int k, m;
    if (input_number("Введите начальный индекс столбца k: ", &k) == 0){
        printf("\nВвод прерван EOF.\n");
        return;
    }
    if (input_number("Введите начальный индекс столбца k: ", &m) == 0){
        printf("\nВвод прерван EOF.\n");
        return;
    }
    if (k < 0 || m < 0 || k > m || (size_t)m >= cols){
        printf("Ошибка: некорректный диапозон столбцов (допустимо 0 <= k <= m < %zu).\n", cols);
        return;
    }
    int total = summ_cols_range(matptr, rows, cols, (size_t)k, (size_t)m);
    printf("Сумма элементов столбцов с %d по %d: %d\n", k, m, total);
}
