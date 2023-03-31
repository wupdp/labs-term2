#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#define LIMIT 440
#define LIMIT_ADD 3000
#define LIMIT_VOCABULARY 400

typedef struct vocabulary_struct{
    char* word_lit;
    char* word_big;
} Vocabulary_mas;

typedef struct Node_tag {
    char *word;
    struct Node_tag *next;
} Node_word;

void push(Node_word **head, char *buffer);

void print_stack(const Node_word *head);

char *pop(Node_word **head);

int if_space(char c);

void free_stack(Node_word **head);

void stack_completion(FILE* f, Node_word **head);

void mas_from_vocabulary(FILE *f, Vocabulary_mas *mas, int num);

long long get_file_size(const char* file_name);

void file_uncompressed_completion(FILE *f, FILE *f2, FILE *f_vocabulary, long int vocabulary_pos);