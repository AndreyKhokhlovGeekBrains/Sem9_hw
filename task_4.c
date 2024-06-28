// Задача 4. Удалить повторяющиеся символы
// В файле .txt строка из маленьких и больших английских букв, знаков
// препинания и пробелов. Требуется удалить из нее повторяющиеся символы и
// все пробелы. Результат записать в файл .txt.
// Данные на входе: Строка из маленьких и больших английских букв,
// знаков препинания и пробелов. Размер строки не более 1000 символов.
// Данные на выходе: Строка из маленьких и больших английских
// букв.
// Пример
// Данные на входе: abc cde def
// Данные на выходе: abcdef

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_SIZE 1000

void print_line_to_file(FILE* f, const char* line) {
    fprintf(f, "%s\n", line);
}

int char_is_present(char* str, char chr) {
    for(int i = 0; str[i] != '\0'; i++) {
        if(str[i] == chr) {
            return 1;
        }
    }
    return 0;
}

char* unique_chars(char* str) {
    printf("%s", str);
    int size = strlen(str);
    char* result_str = (char*)malloc((sizeof(char) * size) + 1);
    int count = 0;

    for(int i = 0; i < size; i++) {
       if(str[i] != ' ' && !char_is_present(result_str, str[i])) {
            result_str[count++] = str[i];
            result_str[count] = 0; 
        } 
    }
    
    result_str = (char*)realloc(result_str, (sizeof(char) * count) + 1);
    return result_str;
}

int main(void) {
    char my_string[MAX_SIZE];
    FILE* f_read = fopen("input.txt", "r");
    fscanf(f_read, "%[^\n]", my_string);
    fclose(f_read);

    char* my_result = unique_chars(my_string);
    
    FILE* f_write = fopen("output.txt", "w");
    print_line_to_file(f_write, my_result);
    fclose(f_write);

    return 0;
}