#include "stdio.h"
#include "stdlib.h"
#include "string.h"

typedef struct vocabulary_struct {
    char *word_lit;
    char *word_big;
} Vocabulary_mas;

int if_space(char c);

void mas_from_vocabulary(FILE *f, Vocabulary_mas **mas, int *num);

long long get_file_size(const char *file_name);

void file_uncompressed_completion(FILE *f, FILE *f2, Vocabulary_mas *mas, int size);