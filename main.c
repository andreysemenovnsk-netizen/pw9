#include <stdio.h>
#include "matrixfunc.h"
#include <locale.h>
#define MAX_ROWS 50
#define MAX_COLS 50

int main(){
    setlocale(LC_ALL, "ru_RU.UTF-8");
    int matrix[MAX_ROWS][MAX_COLS];
    int *matptr = &matrix[MAX_ROWS][MAX_COLS];
    size_t rows = 0;
    size_t cols = 0;
    int is_sized = 0;
    int is_filled = 0;

    while(1){
        printf("\n--- Меню приложения ---\n");
        printf("a Задать размер матрицы (строки, столбцы)\n");
        printf("b Заполнить матрицу\n");
        printf("c Представление матрицы (значенияб адреса элемнтов)\n");
        printf("d Вычисление суммы элементов каждого столбца матрицы\n");
        printf("e Определение количества элементов ниже заданного k\n");
        printf("f Вычисление суммы элементов столбцов в диапозоне индексов k-m\n");
        printf("g Выход\n");
        printf("Выберите пункт: ");

        int ch = getchar();
        if (ch == EOF){
            printf("\nПолучен сигнал EOF\n");
            break;
        }
        if (ch == '\n'){
            continue;
        }
        buffer_clearing();

        switch (ch){
            case 'a': {
                int status = set_matrix_size(&rows, &cols);
                if (status == 0){
                    printf("\nEOF. Выход\n");
                    return 0;
                }
                if (status == 1){
                    is_sized = 1;
                    is_filled = 0;
                }
                break;
            }

            case 'b':
                if (is_sized == 0){
                    printf("Сначало задайте размер матрицы (пункт а).\n");
                } else {
                    if (fill_the_matrix(matptr, rows, cols) == 0){
                        printf("\nEOF. Выход\n");
                        return 0;
                    }
                    is_filled = 1;
                }
                break;
            
            case 'c':
                if (is_filled == 0){
                    printf("Матрица не заполнена (выполните пункты 'a' и 'b').\n");
                } else {
                    show_matrix(matptr, rows, cols);
                }
                break;

            case 'd':
                if (is_filled == 0){
                    printf("Матрциа не заполнена (выполните пункты 'a' и 'b').\n");
                } else {
                    read_summ_of_elements_colum_matrix(matptr, rows, cols);
                }
                break;
            
            case 'e':
                if (is_filled == 0){
                    printf("Матрциа не заполнена (выполните пункты 'a' и 'b').\n");
                } else {
                    read_numbers_below_k(matptr, rows, cols);
                }
                break;
            
            case 'f':
                if (is_filled == 0){
                    printf("Матрица не заполнена (выполните пункты 'a' и 'b').\n");
                } else {
                    read_summ_cols_range(matptr, rows, cols);
                }
                break;
            
            case 'g':
                printf("Выход из программы.\n");
                return 0;

            default:
                printf("Неизвестный пункт меню '%c'. Повторите выбор.\n", ch);

        }
    }
    return 0;
}