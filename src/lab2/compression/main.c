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
    stack_completion(f, &head, &num1);              //заполнение стека текстом
    mas_completion_from_stack(&head, &num, &words); //перенос стека в массив с подсчетом частоты
    free_stack(&head);
    insertion_sort(words, num);         //сортировка основного массива по длине слов
    Book_frequency *words_lit = (Book_frequency *) calloc(LIMIT, sizeof(Book_frequency));
    Book_frequency *words_big = (Book_frequency *) calloc(num - LIMIT, sizeof(Book_frequency));
    separation(&num, &words_lit, &words_big, &words);       //разделение на 2 массива
    free(words);
    insertion_sort_frequency_lit(words_lit, LIMIT);     //сортировка по частоте слов
    insertion_sort_frequency_big(words_big, num - LIMIT);
    FILE *f_compressed = NULL;
    f_compressed = fopen("HOBBIT_cmpr.txt", "w");
    if (f_compressed == NULL) {
        perror("ERROR_0");
        return 0;
    }
    rewind(f);
    file_compressed_completion(f, f_compressed, words_lit, words_big);
    printf("%d %d\n", num, num1);
    printf("Compression is complete\n");
    long long memory1 = get_file_size("HOBBIT.txt");
    long long memory2 = get_file_size("HOBBIT_cmpr.txt");
    float percent = 100 - (float)memory2 / (float)memory1 * 100;
    printf("Size of file is %lld bite\n", memory1);
    printf("Size of compressed file is %lld bite\n", memory2);
    printf("%f %%\n", percent);
    //print_vocabulary(words_big);
    fclose(f);
    fclose(f_compressed);
    return EXIT_SUCCESS;
}
