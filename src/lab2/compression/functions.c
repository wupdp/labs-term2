#include "header.h"

#define STACK_OVERFLOW  (-100)
#define STACK_UNDERFLOW (-101)

//char *strncpy(char *dest, const char *src, size_t n)
//Копирует до n символов из строки, на которую указывает src, в dest.

void push(Node_word **head, char *buffer) {
    Node_word *tmp = malloc(sizeof(Node_word));
    if (tmp == NULL) {
        exit(STACK_OVERFLOW);
    }
    tmp->next = *head;
    tmp->word = buffer;
    *head = tmp;
}

char *pop(Node_word **head) {
    Node_word *out;
    char *buffer;
    if (*head == NULL) {
        exit(STACK_UNDERFLOW);
    }
    out = *head;
    *head = (*head)->next;
    buffer = out->word;
    free(out);
    return buffer;
}

void free_stack(Node_word **head) {
    Node_word *temp;
    while (*head) {
        free((*head)->word);
        *head = (*head)->next;
    }
}

void print_stack(const Node_word *head) {
    printf("stack >");
    while (head) {
        printf("%s ", head->word);
        head = head->next;
    }
}

int if_space(char c) {
    if (c == 32) return 1;
    else
        return 0;
};

void swap(Book_frequency *a, Book_frequency *b) {
    Book_frequency temp = *a;
    *a = *b;
    *b = temp;
}

void insertion_sort(Book_frequency *mas, int n) {
    for (int k = 1; k < n; k++)
        for (int i = k; i > 0 && strlen(mas[i - 1].word) >= strlen(mas[i].word); i--)
            swap(&mas[i], &mas[i - 1]);
}

void insertion_sort_frequency_lit(Book_frequency *mas, int n) {
    for (int k = 1; k < n; k++)
        for (int i = k; i > 0 && mas[i - 1].frequency >= mas[i].frequency; i--)
            swap(&mas[i], &mas[i - 1]);
}

void insertion_sort_frequency_big(Book_frequency *mas, int n) {
    for (int k = 1; k < n; k++)
        for (int i = k; i > 0 && mas[i - 1].frequency <= mas[i].frequency; i--)
            swap(&mas[i], &mas[i - 1]);
}

void stack_completion(FILE *f, Node_word **head, int *num1) {
    char *str = (char *) calloc(600, 1);
    while (!feof(f)) {
        if (NULL != fgets(str, 255, f)) {
            int i = 0;
            while (str[i] != '\0') {
                if ((if_space(str[i]) == 0 && if_space(str[i - 1]) == 1) || (i == 0 && if_space(str[i]) == 0)) {
                    int count = 0;
                    int i_start = i;
                    char *buffer = (char *) calloc(50, 1);
                    while (if_space(str[i]) == 0 && str[i] != '\n') {
                        count++;
                        i++;
                    }
                    strncpy(buffer, &str[i_start], count);
                    buffer[count] = '\0';
                    push(head, buffer);
                    (*num1)++;
                } else i++;
            }
        }
    }
    free(str);
}

void mas_completion_from_stack(Node_word **head, int *num, Book_frequency **words) {
    char *buffer = calloc(255, 1);
    while (*head) {
        buffer = pop(&(*head));
        for (int i = 0; i < (*num) + 1; i++) {
            if (i == (*num)) {
                (*num)++;
                (*words) = (Book_frequency *) realloc((*words), *num * sizeof(Book_frequency));
                (*words)[i].word = buffer;
                (*words)[i].frequency = 1;
                break;
            }
            if (strcmp(buffer, (*words)[i].word) == 0) {
                (*words)[i].frequency++;
                break;
            }
        }
    }
    free(buffer);
}

void separation(int *num, Book_frequency **words_lit, Book_frequency **words_big, Book_frequency **words) {
    for (int i = 0; i < *num; i++) {      //заполнение 2х массивов по длине слов
        if (i < LIMIT)
            (*words_lit)[i] = (*words)[i];
        else if (i > LIMIT + LIMIT_ADD)
            (*words_big)[i - LIMIT] = (*words)[i];
    }

}

void file_compressed_completion(FILE *f, FILE *f2, Book_frequency *words_lit, Book_frequency *words_big) {
    char *str = (char *) calloc(255, 1);
    while (!feof(f)) {
        if (NULL != fgets(str, 255, f)) {
            int i = 0;
            while (str[i] != '\0') {
                if ((if_space(str[i]) == 0 && if_space(str[i - 1]) == 1) || (i == 0 && if_space(str[i]) == 0)) {
                    int count = 0;
                    int i_start = i;
                    char *buffer = (char *) calloc(255, 1);
                    while (if_space(str[i]) == 0 && str[i] != '\0' && str[i] != '\n') {        //&& str[i] != '\n'
                        count++;
                        i++;
                    }
                    strncpy(buffer, &str[i_start], count);
                    buffer[count] = '\0';
                    for (int j = 0; j < LIMIT_VOCABULARY + 1; j++) {
                        if (j == LIMIT_VOCABULARY) {
                            fputs(buffer, f2);
                            fputs(" ", f2);
                            break;
                        }
                        if (strcmp(buffer, words_big[j].word) == 0) {
                            fputs(words_lit[j].word, f2);
                            fputs(" ", f2);
                            break;
                        } else if (strcmp(buffer, words_lit[j].word) == 0) {
                            fputs(words_big[j].word, f2);
                            fputs(" ", f2);
                            break;
                        }
                    }
                } else i++;
            } fputs("\n", f2);
        }
    }
    fputs("$\n", f2);
    for (int i = 0; i < LIMIT_VOCABULARY; i++) {
        fputs(words_lit[i].word, f2);
        fputs("    ", f2);
        fputs(words_big[i].word, f2);
        fputs("\n", f2);
    }
    free(str);
}

long long get_file_size(const char *file_name) {
    long long file_size = 0;
    FILE *fd = fopen(file_name, "rb");
    if (fd == NULL) {
        file_size = -1;
    } else {
        fseek(fd, 0, SEEK_END);
        file_size = ftell(fd);
    }
    return file_size;
}

void print_vocabulary(Book_frequency *words){
    for (int i = 0; i < LIMIT_VOCABULARY; i++) {
        printf("%s  %d ", words[i].word, words[i].frequency);
    }
}