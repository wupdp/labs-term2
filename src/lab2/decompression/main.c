#include "header.h"
// запись словаря в массив
// рефакторинг кода
// запись слов в очередь
int main() {
    Node_word *head = NULL;
    Vocabulary_mas *vocabulary = NULL;
    FILE *f_compressed = NULL;
    FILE *f = NULL;
    FILE *f_vocabulary = NULL;
    int size = 0;
    f_compressed = fopen("C:\\c\\src\\lab2\\compression\\cmake-build-debug\\HOBBIT_cmpr.txt", "r");
    if (f_compressed == NULL) {
        perror("ERROR_0");
        return 0;
    }
    f = fopen("HOBBIT.txt", "w");
    if (f == NULL) {
        perror("ERROR_0");
        return 0;
    }
    f_vocabulary = fopen("C:\\c\\src\\lab2\\compression\\cmake-build-debug\\HOBBIT_cmpr.txt", "r");
    if (f_compressed == NULL) {
        perror("ERROR_0");
        return 0;
    }
    stack_completion(f_compressed, &head);
    mas_from_vocabulary(f_compressed, vocabulary, size);
    //char *buffer = (char *) calloc(255, 1);
    //while (strcmp("$\n", buffer) != 0 || feof(f_compressed) != 0) {
      //  fgets(buffer, 255, f_compressed);
    //}
    //fputs(buffer, f_compressed);
    //long int vocabulary_pos = ftell(f_compressed);
    //file_uncompressed_completion(f_compressed, f, f_vocabulary, vocabulary_pos);
    free_stack(&head);
    return EXIT_SUCCESS;
}
