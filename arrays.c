#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "arrays.h"

// Математическая функция для заполнения массивf
double func(double x) {
    return sin(x) + cos(2 * x) / (1 + x * x);
}

// Заполнение массива значениями функции func()
double* full_elements(double* ptr_array, int n) {
    if (ptr_array == NULL || n <= 0) {
        return NULL;
    }

    // Заполняем массив значениями функции
    // Пример: x изменяется от 0 до n-1 с шагом 0.5
    for (int i = 0; i < n; i++) {
        double x = i * 0.5;  // Можете изменить шаг по необходимости
        ptr_array[i] = func(x);
    }

    return ptr_array;
}

// Печать элементов массива
int put_elements(double* ptr_array, int n) {
    if (ptr_array == NULL || n <= 0) {
        printf("Массив пуст или некорректен!\n");
        return 0;
    }

    int printed_count = 0;
    printf("Элементы массива (%d элементов):\n", n);

    for (int i = 0; i < n; i++) {
        printf("array[%3d] = %10.4f", i, ptr_array[i]);
        printed_count++;

        if ((i + 1) % 5 == 0) {
            printf("\n");
        }
    }

    if (n % 5 != 0) {
        printf("\n");
    }

    return printed_count;
}

// Обработка элементов массива согласно индивидуальному варианту
// Пример: замена отрицательных элементов на их квадраты
double* calc_elements(double* ptr_array, int n) {
    if (ptr_array == NULL || n <= 0) {
        return NULL;
    }

    for (int i = 0; i < n; i++) {
        if (ptr_array[i] < 0) {
            ptr_array[i] = ptr_array[i] * ptr_array[i];  // Квадрат отрицательных
        }
    }

    return ptr_array;
}

// Вычисление суммы элементов массива в диапазоне [begin, end]
double sum_elements(double* ptr_array, int begin, int end) {
    if (ptr_array == NULL || begin < 0 || end < begin) {
        return 0.0;
    }

    double sum = 0.0;
    for (int i = begin; i <= end; i++) {
        sum += ptr_array[i];
    }

    return sum;
}

// Поиск элемента в массиве
int find_element(double* ptr_array, int n, double element) {
    if (ptr_array == NULL || n <= 0) {
        return -1;
    }

    const double EPSILON = 1e-6;  // Точность сравнения для double

    for (int i = 0; i < n; i++) {
        if (fabs(ptr_array[i] - element) < EPSILON) {
            return i;  // Найден элемент
        }
    }

    return -1;  // Элемент не найден
}

// Дополнительные функции (примеры)

// Поиск минимального элемента
double find_min_element(double* ptr_array, int n) {
    if (ptr_array == NULL || n <= 0) {
        return 0.0;
    }

    double min = ptr_array[0];
    for (int i = 1; i < n; i++) {
        if (ptr_array[i] < min) {
            min = ptr_array[i];
        }
    }

    return min;
}

// Подсчет элементов, удовлетворяющих условию
int count_elements_condition(double* ptr_array, int n, double threshold) {
    if (ptr_array == NULL || n <= 0) {
        return 0;
    }

    int count = 0;
    for (int i = 0; i < n; i++) {
        if (ptr_array[i] > threshold) {
            count++;
        }
    }

    return count;
}

// Сортировка массива методом пузырька
void sort_array(double* ptr_array, int n) {
    if (ptr_array == NULL || n <= 1) {
        return;
    }

    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (ptr_array[j] > ptr_array[j + 1]) {
                // Обмен элементов
                double temp = ptr_array[j];
                ptr_array[j] = ptr_array[j + 1];
                ptr_array[j + 1] = temp;
            }
        }
    }
}

// Копирование массива
double* copy_array(double* source, int n) {
    if (source == NULL || n <= 0) {
        return NULL;
    }

    double* copy = (double*)malloc(n * sizeof(double));
    if (copy == NULL) {
        return NULL;
    }

    for (int i = 0; i < n; i++) {
        copy[i] = source[i];
    }

    return copy;
}