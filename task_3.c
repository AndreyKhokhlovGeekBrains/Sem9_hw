// Задача 3. Числа в массив
// В файле .txt дана строка, не более 1000 символов, содержащая буквы, целые
// числа и иные символы. Требуется все числа, которые встречаются в строке,
// поместить в отдельный целочисленный массив. Например, если дана строка
// "data 48 call 9 read13 blank0a", то в массиве числа 48, 9, 13 и 0. Вывести
// массив по возрастанию в файл .txt.
// Данные на входе: Строка из английских букв, цифр и знаков
// препинания
// Данные на выходе: Последовательность целых чисел
// отсортированная по возрастанию
// Пример
// Данные на входе: data 48 call 9 read13 blank0a
// Данные на выходе: 0 9 13 48

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_SIZE 1000

void print_arr_to_file(FILE* f, int* arr, int size) {
    for(int i = 0; i < size; i++) {
        fprintf(f, "%d ", arr[i]);
    }  
}

void sort_array(int size, int a[]) {
    int temp;
    for(int i = 0; i < size - 1; i++) {
        for(int j = i + 1; j < size; j++) {
            if(a[j] < a[i]) {
                temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }
    }
}

int* numbers_from_string(char* str, int* arr_size) {
    printf("%s", str);
    int size = strlen(str);
    int* my_arr = (int*)malloc(sizeof(int) * size);
    int count = 0;
    int num = 0;
    int is_num = 0;

    for(int i = 0; i < size; i++) {
        if(str[i] >= '0' && str[i] <= '9') {
            num = num * 10 + (str[i] - '0');
            is_num = 1;
        } else {
            if(is_num) {
                my_arr[count++] = num;
                num = 0;
                is_num = 0;
            }
        }
    }
    *arr_size = count;
    my_arr = (int*)realloc(my_arr, sizeof(int) * count);
    sort_array(count, my_arr);
    return my_arr;
}

int main(void) {
    char my_string[MAX_SIZE];
    FILE* f_read = fopen("input.txt", "r");
    fscanf(f_read, "%[^\n]", my_string);
    fclose(f_read);

    int size = 0;
    int* my_arr = numbers_from_string(my_string, &size);
    
    FILE* f_write = fopen("output.txt", "w");
    print_arr_to_file(f_write, my_arr, size);
    fclose(f_write);

    return 0;
}