#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#define LIMIT 440
#define LIMIT_ADD 3000
#define LIMIT_VOCABULARY 400

typedef struct Book_frequency_struct{
    char* word;
    int frequency;
} Book_frequency;

typedef struct Node_tag {
    char *word;
    struct Node_tag *next;
} Node_word;

void push(Node_word **head, char *buffer);

void print_stack(const Node_word *head);

char *pop(Node_word **head);

int if_space(char c);

void insertion_sort (Book_frequency *mas, int n);

void insertion_sort_frequency_lit (Book_frequency *mas, int n);

void insertion_sort_frequency_big (Book_frequency *mas, int n);

void free_stack(Node_word **head);

void stack_completion(FILE* f, Node_word **head, int* num1);

void mas_completion_from_stack(Node_word **head, int* num, Book_frequency **words);

void separation(int* num, Book_frequency **words_lit, Book_frequency **words_big, Book_frequency **words);

void file_compressed_completion(FILE *f, FILE *f2, Book_frequency *words_lit, Book_frequency *words_big);

long long get_file_size(const char* file_name);

void print_vocabulary(Book_frequency *words);