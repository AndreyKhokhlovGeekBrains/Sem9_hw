// Задача 5. Самое длинное слово
// В файле .txt дана строка слов, разделенных пробелами. Найти самое длинное
// слово и вывести его в файл .txt. Случай, когда самых длинных слов может быть
// несколько, не обрабатывать.
// Данные на входе: Строка из английских букв и пробелов. Не более
// 1000 символов.
// Данные на выходе: Одно слово из английских букв.
// Пример
// Данные на входе: Hello beautiful world
// Данные на выходе: beautiful

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void print_line_to_file(FILE* f, const char* line) {
    fprintf(f, "%s\n", line);
}

char* the_longest_word(FILE* f) {
    char buffer[100];
    char* result_word = (char*)malloc(sizeof(char) * 100);
    result_word[0] = '\0';
    while (fscanf(f, "%s", buffer) == 1)
    {
        if(strlen(buffer) > strlen(result_word)) {
            strcpy(result_word, buffer);
        }
    }
    
    int len = strlen(result_word) + 1;
    result_word = realloc(result_word, (sizeof(char) * len));
    result_word[len] = 0;
    // Reset the file pointer to the beginning for further reading if needed
    rewind(f);
    printf("%s", result_word);
    return result_word;
}

int main(void) {
    FILE* f_read = fopen("input.txt", "r");
    FILE* f_write = fopen("output.txt", "w");
    print_line_to_file(f_write, the_longest_word(f_read));
    fclose(f_read);
    fclose(f_write);

    return 0;
}