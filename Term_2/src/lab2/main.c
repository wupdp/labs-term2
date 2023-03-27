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
    insertion_sort_frequency(words_lit, LIMIT);     //сортировка по частоте слов
    insertion_sort_frequency(words_big, num - LIMIT);
    printf("%d %d", num, num1);
    for (int i = 0; i < LIMIT; i++) {
        printf("%s  %d ", words_lit[i].word, words_lit[i].frequency);
    }
    fclose(f);
    getchar();
    return EXIT_SUCCESS;
}
