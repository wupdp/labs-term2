#include "stdio.h"
#include "stdlib.h"
#include "string.h"
typedef int T;

typedef struct Book_frequency_struct{
    char* word;
    int frequency;
} Book_frequency;

typedef struct Node_tag {
    char *word;
    struct Node_tag *next;
} Node_word;

int if_letter(char c);

void push(Node_word **head, char *buffer);

void printStack(const Node_word *head);

char *pop(Node_word **head);

int if_space(char c);

void insertion_sort (Book_frequency *mas, int n);

void insertion_sort_frequency (Book_frequency *mas, int n);

void free_stack(const Node_word **head);