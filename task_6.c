// Задача 6. Заканчивается на a
// В файле .txt дано предложение. Необходимо определить, сколько слов
// заканчиваются на букву 'а'. Ответ записать в файл .txt.
// Данные на входе: Строка из английских букв и пробелов не более 1000
// символов.
// Данные на выходе: Одно целое число
// Пример
// Данные на входе: Mama mila ramu
// Данные на выходе: 2

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void print_number_to_file(FILE* f, int num) {
    fprintf(f, "%d ", num);
}

int number_of_words_ending_a(FILE* f) {
    char buffer[100];
    int result = 0;

    while (fscanf(f, "%s", buffer) == 1)
    {
        if(buffer[strlen(buffer) - 1] == 'a') {
            result++;
        }
    }
    
    // Reset the file pointer to the beginning for further reading if needed
    rewind(f);
    printf("%d", result);
    return result;
}

int main(void) {
    FILE* f_read = fopen("input.txt", "r");
    FILE* f_write = fopen("output.txt", "w");
    print_number_to_file(f_write, number_of_words_ending_a(f_read));
    fclose(f_read);
    fclose(f_write);

    return 0;
}