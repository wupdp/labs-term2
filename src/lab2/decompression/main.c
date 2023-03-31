#include "header.h"
// рефакторинг кода
int main() {
    Vocabulary_mas *vocabulary = NULL;
    FILE *f_compressed = NULL;
    FILE *f = NULL;
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
    mas_from_vocabulary(f_compressed, &vocabulary, &size);
    file_uncompressed_completion(f_compressed, f, vocabulary, size);
    return EXIT_SUCCESS;
}
