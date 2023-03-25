#include "header.h"

#define STACK_OVERFLOW  (-100)
#define STACK_UNDERFLOW (-101)
#define OUT_OF_MEMORY   (-102)

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

void free_stack(const Node_word **head) {
    Node_word* temp;
    while (*head) {
       free((*head)->word);
        *head = (*head)->next;
    }
}

char *peek(const Node_word *head) {
    if (head == NULL) {
        exit(STACK_UNDERFLOW);
    }
    return head->word;
}

void printStack(const Node_word *head) {
    printf("stack >");
    while (head) {
        printf("%s ", head->word);
        head = head->next;
    }
}

size_t getSize(const Node_word *head) {
    size_t size = 0;
    while (head) {
        size++;
        head = head->next;
    }
    return size;
}

int if_space(char c){
    if (c == 32)    return 1;
    else
        return 0;
};

int if_letter(char c) {
    if ((c >= 65 && c <= 90) || (c >= 97 && c <= 122)) return 1;
    else
        return 0;
}

void swap (Book_frequency *a, Book_frequency *b) {
    Book_frequency temp = *a;
    *a = *b;
    *b = temp;
}

void insertion_sort (Book_frequency *mas, int n) {
    for (int k = 1; k < n; k++)
        for (int i = k; i > 0 && strlen(mas[i - 1].word) >= strlen(mas[i].word); i--)
                swap(&mas[i], &mas[i - 1]);
}

void insertion_sort_frequency (Book_frequency *mas, int n) {
    for (int k = 1; k < n; k++)
        for (int i = k; i > 0 && mas[i - 1].frequency <= mas[i].frequency; i--)
            swap(&mas[i], &mas[i - 1]);
}
