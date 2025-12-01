#include <stdio.h> 
#include <stdlib.h> 
#include <time.h>
#include <locale.h>
#include <math.h>
#include <limits.h>


// Основные функции для дз к лаб. 11
double* fill_array_random(double* array, int size);
int find_max_element(double* array, int size, double* max_value);
int count_positive_before_index(double* array, int size, int index);
int print_array_double(double* array, int size);

// Функции для задания 2.1 и 2.2
int delete_each_kth_element(double* array, int size, int k);
double* insert_after_each_kth(double* array, int* size, int k, double value);

// Функции для дз к лаб. 16
double* create_random_array(int* size);
int print_array_info(double* array, int size, const char* name);
double* combine_arrays(double* a, int n, double* b, int m, double* c, int l, int* result_size);
double calculate_cumulative_sum(double* array, int size);

// Функции для дз к лаб. 14
int* create_int_array(int size);
int fill_int_array(int* array, int size);
int find_max_in_range(int* array, int size, int K, int L);
void print_int_array(int* array, int size);

void execute_main_task();
void execute_three_arrays_task();
void execute_max_in_range_task();

int main() {
    setlocale(LC_CTYPE, "RUS");
    srand(time(NULL));

    int choice;

    
    printf("Выберите задание для выполнения:\n");
    printf("1 - Основное задание (удаление/вставка элементов)\n");
    printf("2 - Дополнительное задание (генерация и объединение 3 массивов)\n");
    printf("3 - Задание: поиск максимума в диапазоне\n");
    printf("4 - Выполнить все задания\n");
    printf("Ваш выбор: ");

    if (scanf("%d", &choice) != 1) {
        printf("Ошибка ввода выбора!\n");
        return 1;
    }

    switch (choice) {
    case 1:
        execute_main_task();
        break;
    case 2:
        execute_three_arrays_task();
        break;
    case 3:
        execute_max_in_range_task();
        break;
    case 4:
        execute_main_task();
        printf("\n\n");
        execute_three_arrays_task();
        printf("\n\n");
        execute_max_in_range_task();
        break;
    default:
        printf("Неверный выбор!\n");
        break;
    }

    printf("\n==============================\n");
    printf("Программа успешно завершена.\n");
    printf("==============================\n");

    return 0;
}

// === РЕАЛИЗАЦИИ ФУНКЦИЙ ===

// Заполнение массива случайными числами
double* fill_array_random(double* array, int size) {
    if (array == NULL || size <= 0) {
        return NULL;
    }

    for (int i = 0; i < size; i++) {
        array[i] = (double)rand() / RAND_MAX * 200.0 - 100.0;
    }

    return array;
}

// Поиск максимального элемента в массиве и его индекса
int find_max_element(double* array, int size, double* max_value) {
    if (array == NULL || size <= 0 || max_value == NULL) {
        return -1;
    }

    int max_index = 0;
    *max_value = array[0];

    for (int i = 1; i < size; i++) {
        if (array[i] > *max_value) {
            *max_value = array[i];
            max_index = i;
        }
    }

    return max_index;
}

// Подсчет положительных элементов до указанного индекса
int count_positive_before_index(double* array, int size, int index) {
    if (array == NULL || size <= 0 || index < 0 || index >= size) {
        return 0;
    }

    int count = 0;
    for (int i = 0; i < index; i++) {
        if (array[i] > 0) {
            count++;
        }
    }

    return count;
}

// Вывод массива double на экран
int print_array_double(double* array, int size) {
    if (array == NULL) {
        printf("Массив пуст!\n");
        return -1;
    }

    if (size <= 0) {
        printf("Неверный размер массива!\n");
        return -1;
    }

    printf("Элементы массива (%d элементов):\n", size);
    for (int i = 0; i < size; i++) {
        printf("[%3d] = %8.2f", i, array[i]);
        if ((i + 1) % 5 == 0) printf("\n");
    }
    if (size % 5 != 0) printf("\n");

    return 0;
}

// Удаление каждого k-го элемента
int delete_each_kth_element(double* array, int size, int k) {
    if (array == NULL || k <= 0 || size <= 0) {
        return size;
    }

    if (k == 1) {
        return 0;
    }

    int new_index = 0;
    int deleted_count = 0;

    for (int i = 0; i < size; i++) {
        if ((i + 1) % k == 0) {
            deleted_count++;
        }
        else {
            array[new_index] = array[i];
            new_index++;
        }
    }

    printf("Удалено %d элементов\n", deleted_count);
    return new_index;
}

// Вставка после каждого k-го элемента
double* insert_after_each_kth(double* array, int* size, int k, double value) {
    if (array == NULL || size == NULL || k <= 0) {
        return array;
    }

    int insert_count = 0;
    for (int i = 1; i <= *size; i++) {
        if (i % k == 0) {
            insert_count++;
        }
    }

    if (insert_count == 0) {
        printf("Нет элементов для вставки после (k=%d, размер=%d)\n", k, *size);
        return array;
    }

    int new_size = *size + insert_count;
    double* new_array = (double*)realloc(array, new_size * sizeof(double));

    if (new_array == NULL) {
        printf("Ошибка выделения памяти!\n");
        return array;
    }

    int write_pos = new_size - 1;
    int read_pos = *size - 1;

    for (int i = *size; i >= 1; i--) {
        new_array[write_pos--] = new_array[read_pos--];

        if (i % k == 0) {
            new_array[write_pos--] = value;
        }
    }

    *size = new_size;
    printf("Выполнено %d вставок\n", insert_count);

    return new_array;
}

// Создание массива со случайными числами
double* create_random_array(int* size) {
    if (size == NULL) {
        return NULL;
    }

    *size = rand() % 41 + 10; // 10-50
    double* array = (double*)malloc(*size * sizeof(double));

    if (array == NULL) {
        printf("Ошибка выделения памяти для массива!\n");
        return NULL;
    }

    for (int i = 0; i < *size; i++) {
        array[i] = (double)rand() / RAND_MAX * 100.0 - 50.0;
    }

    return array;
}

// Вывод информации о массиве
int print_array_info(double* array, int size, const char* name) {
    if (array == NULL || size <= 0 || name == NULL) {
        return -1;
    }

    printf("\nМассив %s (размер %d):\n", name, size);
    for (int i = 0; i < size; i++) {
        printf("%s[%d] = %.2f  ", name, i, array[i]);
        if ((i + 1) % 5 == 0) printf("\n");
    }
    if (size % 5 != 0) printf("\n");

    return 0;
}

// Объединение трех массивов по правилам
double* combine_arrays(double* a, int n, double* b, int m, double* c, int l, int* result_size) {
    if (a == NULL || b == NULL || c == NULL || result_size == NULL) {
        return NULL;
    }

    *result_size = n + m + 1;
    double* result = (double*)malloc(*result_size * sizeof(double));

    if (result == NULL) {
        printf("Ошибка выделения памяти для результирующего массива!\n");
        return NULL;
    }

    int index = 0;

    // Копирование массива A
    for (int i = 0; i < n; i++) {
        result[index++] = a[i];
    }

    // Копирование массива B в обратном порядке
    for (int i = m - 1; i >= 0; i--) {
        result[index++] = b[i];
    }

    // Добавление накопленной суммы массива C
    double sum = calculate_cumulative_sum(c, l);
    result[index] = sum;

    return result;
}

// Вычисление накопленной суммы массива
double calculate_cumulative_sum(double* array, int size) {
    if (array == NULL || size <= 0) {
        return 0.0;
    }

    double sum = 0.0;
    for (int i = 0; i < size; i++) {
        sum += array[i];
    }

    return sum;
}

// Создание целочисленного массива
int* create_int_array(int size) {
    if (size <= 0) {
        return NULL;
    }

    int* array = (int*)malloc(size * sizeof(int));
    return array;
}

// Заполнение целочисленного массива
int fill_int_array(int* array, int size) {
    if (array == NULL || size <= 0) {
        return -1;
    }

    printf("Введите %d элементов массива:\n", size);
    for (int i = 0; i < size; i++) {
        printf("Элемент [%d]: ", i);
        if (scanf("%d", &array[i]) != 1) {
            printf("Ошибка ввода элемента [%d]!\n", i);
            return -1;
        }
    }

    return 0;
}

// Поиск максимума в диапазоне [K, L]
int find_max_in_range(int* array, int size, int K, int L) {
    if (array == NULL || size <= 0 || K < 0 || L >= size || K > L) {
        printf("Ошибка: некорректные параметры!\n");
        return INT_MIN;
    }

    int max = array[K];

    for (int i = K + 1; i <= L; i++) {
        if (array[i] > max) {
            max = array[i];
        }
    }

    return max;
}

// Вывод целочисленного массива
void print_int_array(int* array, int size) {
    if (array == NULL || size <= 0) {
        printf("Массив пуст или некорректен!\n");
        return;
    }

    printf("Массив (%d элементов): [", size);
    for (int i = 0; i < size; i++) {
        printf("%d", array[i]);
        if (i < size - 1) {
            printf(", ");
        }
    }
    printf("]\n");
}

// Выполнение основного задания
void execute_main_task() {
    printf("\n=== ОСНОВНОЕ ЗАДАНИЕ ===\n");

    int size;
    printf("Введите размер массива: ");
    if (scanf("%d", &size) != 1 || size <= 0) {
        printf("Ошибка: размер массива должен быть положительным числом!\n");
        return;
    }

    double* array = (double*)malloc(size * sizeof(double));
    if (array == NULL) {
        printf("Ошибка выделения памяти!\n");
        return;
    }

    printf("\n1. Заполнение массива случайными числами:\n");
    fill_array_random(array, size);
    print_array_double(array, size);

    double max_value;
    int max_index = find_max_element(array, size, &max_value);

    if (max_index != -1) {
        printf("\n2. Поиск максимального элемента:\n");
        printf("   Максимальный элемент: array[%d] = %.2f\n", max_index, max_value);

        int positive_count = count_positive_before_index(array, size, max_index);
        printf("   Положительных элементов до него: %d\n", positive_count);
    }

    printf("\n3. Удаление каждого k-го элемента:\n");
    int k_delete;
    printf("   Введите k: ");
    if (scanf("%d", &k_delete) == 1 && k_delete > 0) {
        if (k_delete == 1) {
            size = 0;
            printf("   При k=1 удалены все элементы\n");
        }
        else {
            size = delete_each_kth_element(array, size, k_delete);
            if (size > 0) {
                printf("   Массив после удаления:\n");
                print_array_double(array, size);
            }
            else {
                printf("   Массив пуст после удаления\n");
            }
        }
    }

    if (size > 0) {
        printf("\n4. Вставка после каждого k-го элемента:\n");
        int k_insert;
        double insert_value;

        printf("   Введите k для вставки: ");
        if (scanf("%d", &k_insert) == 1 && k_insert > 0) {
            printf("   Введите значение для вставки: ");
            if (scanf("%lf", &insert_value) == 1) {
                array = insert_after_each_kth(array, &size, k_insert, insert_value);
                if (array != NULL && size > 0) {
                    printf("   Массив после вставки:\n");
                    print_array_double(array, size);
                }
            }
        }
    }

    printf("\n5. Итоговый массив:\n");
    if (size > 0) {
        print_array_double(array, size);
    }
    else {
        printf("   Массив пуст\n");
    }

    free(array);
}

// Выполнение задания с 3 массивами
void execute_three_arrays_task() {
    printf("\n=== ЗАДАНИЕ С 3 МАССИВАМИ ===\n");

    int n, m, l;
    double* a, * b, * c;

    // Создание массивов
    a = create_random_array(&n);
    b = create_random_array(&m);
    c = create_random_array(&l);

    if (a == NULL || b == NULL || c == NULL) {
        if (a) free(a);
        if (b) free(b);
        if (c) free(c);
        return;
    }

    // Вывод исходных массивов
    print_array_info(a, n, "A");
    print_array_info(b, m, "B");
    print_array_info(c, l, "C");

    // Объединение массивов
    int d_size;
    double* d = combine_arrays(a, n, b, m, c, l, &d_size);

    if (d != NULL) {
        printf("\nРезультирующий массив D (размер %d):\n", d_size);
        printf("Структура: [A] + [B в обратном порядке] + [сумма C]\n\n");

        for (int i = 0; i < d_size; i++) {
            printf("D[%d] = %.2f", i, d[i]);

            if (i < n) {
                printf("  (элемент A[%d])", i);
            }
            else if (i < n + m) {
                printf("  (элемент B[%d] в обратном порядке)", m - 1 - (i - n));
            }
            else {
                printf("  (накопленная сумма массива C)");
            }

            if ((i + 1) % 3 == 0) printf("\n");
        }
        if (d_size % 3 != 0) printf("\n");

        printf("\nСтатистика:\n");
        printf("- Размер A: %d элементов\n", n);
        printf("- Размер B: %d элементов\n", m);
        printf("- Размер C: %d элементов\n", l);
        printf("- Размер D: %d элементов\n", d_size);
        printf("- Сумма элементов C: %.2f\n", calculate_cumulative_sum(c, l));

        free(d);
    }

    free(a);
    free(b);
    free(c);
}

// Выполнение задания поиска максимума в диапазоне
void execute_max_in_range_task() {
    printf("\n=== ПОИСК МАКСИМУМА В ДИАПАЗОНЕ ===\n");

    int size;
    printf("Введите размер массива: ");
    if (scanf("%d", &size) != 1 || size <= 0) {
        printf("Ошибка: размер массива должен быть положительным числом!\n");
        return;
    }

    int* array = create_int_array(size);
    if (array == NULL) {
        printf("Ошибка выделения памяти!\n");
        return;
    }

    if (fill_int_array(array, size) != 0) {
        free(array);
        return;
    }

    print_int_array(array, size);

    int K, L;
    printf("\nВведите диапазон [K, L]:\n");
    printf("K (0-%d): ", size - 1);
    if (scanf("%d", &K) != 1 || K < 0 || K >= size) {
        printf("Неверное значение K!\n");
        free(array);
        return;
    }

    printf("L (%d-%d): ", K, size - 1);
    if (scanf("%d", &L) != 1 || L < K || L >= size) {
        printf("Неверное значение L!\n");
        free(array);
        return;
    }

    int max_value = find_max_in_range(array, size, K, L);

    if (max_value != INT_MIN) {
        printf("\nМаксимальное значение в диапазоне [%d, %d]: %d\n", K, L, max_value);
    }

    free(array);
}