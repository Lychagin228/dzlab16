/**
 * arrays.h - Заголовочный файл для работы с массивами
 * Функции для работы с одномерными массивами double и int
 */

#ifndef ARRAYS_H
#define ARRAYS_H

 /**
  * Заполнение массива случайными числами в диапазоне [-100, 100]
  * @param array указатель на массив
  * @param size размер массива
  * @return указатель на заполненный массив
  */
double* fill_array_random(double* array, int size);

/**
 * Поиск максимального элемента в массиве
 * @param array указатель на массив
 * @param size размер массива
 * @param max_value указатель на переменную для хранения максимального значения
 * @return индекс максимального элемента или -1 при ошибке
 */
int find_max_element(double* array, int size, double* max_value);

/**
 * Подсчет положительных элементов до указанного индекса
 * @param array указатель на массив
 * @param size размер массива
 * @param index индекс, до которого подсчитываются элементы
 * @return количество положительных элементов
 */
int count_positive_before_index(double* array, int size, int index);

/**
 * Вывод элементов массива double на экран
 * @param array указатель на массив
 * @param size размер массива
 * @return количество выведенных элементов или -1 при ошибке
 */
int print_array_double(double* array, int size);

/**
 * Удаление каждого k-го элемента из массива
 * @param array указатель на массив
 * @param size размер массива
 * @param k шаг удаления
 * @return новый размер массива
 */
int delete_each_kth_element(double* array, int size, int k);

/**
 * Вставка значения после каждого k-го элемента
 * @param array указатель на массив
 * @param size указатель на переменную размера массива
 * @param k шаг вставки
 * @param value значение для вставки
 * @return указатель на измененный массив
 */
double* insert_after_each_kth(double* array, int* size, int k, double value);

/**
 * Создание массива случайного размера (10-50) с случайными значениями [-50, 50]
 * @param size указатель на переменную для хранения размера массива
 * @return указатель на созданный массив
 */
double* create_random_array(int* size);

/**
 * Вывод информации о массиве double с указанием имени
 * @param array указатель на массив
 * @param size размер массива
 * @param name имя массива для вывода
 * @return 0 при успехе, -1 при ошибке
 */
int print_array_info(double* array, int size, const char* name);

/**
 * Объединение трех массивов по правилу: A + B(в обратном порядке) + сумма(C)
 * @param a указатель на массив A
 * @param n размер массива A
 * @param b указатель на массив B
 * @param m размер массива B
 * @param c указатель на массив C
 * @param l размер массива C
 * @param result_size указатель на переменную для результирующего размера
 * @return указатель на результирующий массив
 */
double* combine_arrays(double* a, int n, double* b, int m, double* c, int l, int* result_size);

/**
 * Вычисление суммы всех элементов массива
 * @param array указатель на массив
 * @param size размер массива
 * @return сумма элементов
 */
double calculate_cumulative_sum(double* array, int size);

/**
 * Создание целочисленного массива заданного размера
 * @param size размер массива
 * @return указатель на созданный массив
 */
int* create_int_array(int size);

/**
 * Заполнение целочисленного массива значениями с клавиатуры
 * @param array указатель на массив
 * @param size размер массива
 * @return 0 при успехе, -1 при ошибке
 */
int fill_int_array(int* array, int size);

/**
 * Поиск максимального элемента в целочисленном массиве в диапазоне [K, L]
 * @param array указатель на массив
 * @param size размер массива
 * @param K начальный индекс диапазона
 * @param L конечный индекс диапазона
 * @return максимальное значение или INT_MIN при ошибке
 */
int find_max_in_range(int* array, int size, int K, int L);

/**
 * Вывод элементов целочисленного массива на экран
 * @param array указатель на массив
 * @param size размер массива
 * @return 0 при успехе, -1 при ошибке
 */
int print_int_array(int* array, int size);

/**
 * Выполнение основного задания (удаление/вставка элементов)
 * @return 0 при успешном выполнении
 */
int execute_main_task();

/**
 * Выполнение задания с генерацией и объединением 3 массивов
 * @return 0 при успешном выполнении
 */
int execute_three_arrays_task();

/**
 * Выполнение задания поиска максимума в диапазоне
 * @return 0 при успешном выполнении
 */
int execute_max_in_range_task();

#endif
