#include "header.h"
#define LIMIT 6000
int main() {
    FILE *f = NULL;
    Node_word *head = NULL;
    Book_frequency *words = (Book_frequency *) calloc(1, sizeof(Book_frequency));
    int num = 0;
    int num1 = 0;
    f = fopen("HOBBIT.txt", "r");
    if (f == NULL) {
        perror("ERROR_0");
        return 0;
    }
    char *str = (char *) calloc(600, 1);
    while (!feof(f)) {
        if (NULL != fgets(str, 255, f)) {
            int i = 0;
            while (str[i] != '\0') {
                if ((if_space(str[i]) == 0 && if_space(str[i - 1]) == 1) || (i == 0 && if_space(str[i]) == 0)) {
                    int count = 0;
                    int i_start = i;
                    char *buffer = (char *) calloc(255, 1);
                    while (if_space(str[i]) == 0 && str[i]!='\n') {
                        count++;
                        i++;
                    }
                    strncpy(buffer, &str[i_start], count);
                    buffer[count] = '\0';
                    push(&head, buffer);
                    num1++;
                } else i++;
            }
        }
    }
    free(str);
    char *buffer = calloc(1, 1);
    while (head) {
        buffer = pop(&head);
        for (int i = 0; i < num + 1; i++) {
            if (i == num) {
                num++;
                words = (Book_frequency *) realloc(words, num * sizeof(Book_frequency));
                words[i].word = buffer;
                words[i].frequency = 1;
                break;
            }
            if (strcmp(buffer, words[i].word) == 0) {
                words[i].frequency++;
                break;
            }
        }
    }
    free_stack(&head);
    free(buffer);
    insertion_sort(words, num);         //сортировка основного массива по длине слов
    Book_frequency *words_lit = (Book_frequency *) calloc(LIMIT, sizeof(Book_frequency));
    Book_frequency *words_big = (Book_frequency *) calloc(num - LIMIT, sizeof(Book_frequency));
    for (int i = 0; i < num; i++){      //заполнение 2х массивов по длине слов
        if(i < LIMIT)
            words_lit[i] = words[i];
        else
            words_big[i - LIMIT] = words[i];
    }
    free(words);
    insertion_sort_frequency(words_lit, LIMIT);
    insertion_sort_frequency(words_big, num - LIMIT);
    printf("%d %d", num, num1);
    for (int i = 0; i < LIMIT; i++) {
        printf("%s  %d ", words_lit[i].word, words_lit[i].frequency);
    }
    fclose(f);
    getchar();
    return EXIT_SUCCESS;
}
