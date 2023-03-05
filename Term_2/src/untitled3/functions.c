#include "header.h"
#include "stdio.h"
#include "stdlib.h"

#define STACK_OVERFLOW  (-100)
#define STACK_UNDERFLOW (-101)
#define OUT_OF_MEMORY   (-102)

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