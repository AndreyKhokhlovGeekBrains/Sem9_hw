// Задача 2. Заменить a на b
// В файле .txt дана символьная строка не более 1000 символов. Необходимо
// заменить все буквы "а" на буквы "b" и наоборот, как заглавные, так и
// строчные. Результат записать в .txt.
// Данные на входе: Строка из маленьких и больших английских букв,
// знаков препинания и пробелов.
// Данные на выходе: Строка из маленьких и больших английских
// букв, знаков препинания и пробелов.
// Пример
// Данные на входе: aabbccddABCD
// Данные на выходе: bbaaccddBACD

#include <stdio.h>
#include <string.h>

#define MAX_SIZE 1000

void print_line_to_file(FILE* f, const char* line) {
    fprintf(f, "%s\n", line);
}

void replace_a_to_b(char* str) {
    int size = strlen(str);
    for(int i = 0; i < size; i++) {
        switch (str[i])
        {
        case 'a':
            str[i] = 'b';
            break;
        case 'b':
            str[i] = 'a';
            break;
        case 'A':
            str[i] = 'B';
            break;
        case 'B':
            str[i] = 'A';
            break;
        
        default:
            break;
        }
    }
}

int main(void) {
    char my_string[MAX_SIZE];
    FILE* f_read = fopen("input.txt", "r");
    fscanf(f_read, "%[^\n]", my_string);
    fclose(f_read);

    replace_a_to_b(my_string);
    FILE* f_write = fopen("output.txt", "w");
    print_line_to_file(f_write, my_string);
    fclose(f_write);

    return 0;
}
