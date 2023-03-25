#include "header.h"

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
    char *str = (char *) calloc(255, 1);
    while (!feof(f)) {
        if (NULL != fgets(str, 255, f)) {
            int i = 0;
            while (str[i] != '\0') {
                if (if_letter(str[i]) == 1 && if_letter(str[i - 1]) == 0) {
                    int count = 0;
                    int i_start = i;
                    char *buffer = (char *) calloc(1, 1);
                    while (if_letter(str[i]) == 1) {
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
    free(buffer);
    printf("%d %d", num, num1);
    for (int i = 0; i < num; i++) {
        printf("%s %d ", words[i].word, words[i].frequency);
    }
    fclose(f);
    getchar();
    return EXIT_SUCCESS;
}
