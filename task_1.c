// Задача 1. По одному разу
// В файле .txt даны два слова не более 100 символов каждое, разделенные
// одним пробелом. Найдите только те символы слов, которые встречаются в
// обоих словах только один раз. Напечатайте их через пробел в файл .txt в
// лексикографическом порядке.
// Данные на входе: Два слова из маленьких английских букв через
// пробел. Длинна каждого слова не больше 100 символов.
// Данные на выходе: Маленькие английские буквы через пробел.
// Пример №1
// Данные на входе: hello world
// Данные на выходе: o
// Данные на входе: aabcd bcef
// Данные на выходе: b c

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define MIN(a, b) ((a) < (b) ? (a) : (b))
#define ALPHABET_SIZE 26
#define MAX_SIZE 101

char print_letters(char* word) {
    for(int i = 0; word[i] != '\0'; i++) {
        printf("%c ", word[i]);
    }
    printf("\n");
}

void print_letters_to_file(FILE* f, const char* word) {
    for (int i = 0; word[i] != '\0'; i++) {
        fprintf(f, "%c ", word[i]);
    }
    fprintf(f, "\n");
}

void fill_arr_by_zeros(int *arr, int size) {
    for(int i = 0; i < size; i++) {
        arr[i] = 0;
    }
}

char* find_letters(char* str1, char* str2) {
    // create arrays to store the frequency of each character in both words
    int freq1[ALPHABET_SIZE];
    int freq2[ALPHABET_SIZE];
    int max_size = MIN(strlen(str1), strlen(str2));

    fill_arr_by_zeros(freq1, ALPHABET_SIZE);
    fill_arr_by_zeros(freq2, ALPHABET_SIZE);

    for(int i = 0; str1[i] != '\0'; i++) {
        freq1[str1[i] - 'a']++;
    }

    for(int i = 0; str2[i] != '\0'; i++) {
        freq2[str2[i] - 'a']++;
    }

    char* result = (char*)malloc(sizeof(char) * max_size + 1);
    int index = 0;

    for(int i = 0; i < ALPHABET_SIZE; i++) {
        if(freq1[i] == 1 && freq2[i] == 1) {
            result[index++] = 'a' + i;
            }
    }
    result[index] = 0;
    return result;
}

int main(void) {
    char my_string_arr[2][MAX_SIZE];

    FILE* f_read = fopen("input.txt", "r");
    for(int i = 0; i < 2; i++) {
        fscanf(f_read, "%s", my_string_arr[i]);
    }
    fclose(f_read);
    
    char* my_result = find_letters(my_string_arr[0], my_string_arr[1]);
    print_letters(my_result);
    FILE* f_write = fopen("output.txt", "w");
    print_letters_to_file(f_write, my_result);
    
    fclose(f_write);
    free(my_result);

    return 0;
}
