
#include <stdio.h>
#include <stdlib.h>
#include "header.h"

void free_mas(int **mas, int r) {
    for (int i = 0; i < r; i++)
        free(mas[i]);
}

void show_string(char *str) {
    for (int i = 0; (str[i]) != '\0'; i++) {
        printf("%c", (str[i]));
    }
    printf("\n");
}

int get_length(char **s, int num) {
    int cnt = 0, i = 0;
    while (s[num][i] != '\0') {
        cnt++;
        i++;
    }
    return cnt + 1;
}

char *get_string(char *s, int *k) {
    int c, i = 0;
    while ((c = getchar()) != EOF && c != '\n') {
        s[i++] = c;
        (*k)++;
    }
    s[i] = '\0';
    return s;
}


void qi_sort(int **mas, int size) {
    int i = 0;
    int j = size - 1;

    int mid = get_length(mas, size / 2);


    do {
        while (get_length(mas, i) > mid) {
            i++;
        }
        while (get_length(mas, j) < mid) {
            j--;
        }

        if (i <= j) {
            int *tmp = mas[i];
            mas[i] = mas[j];
            mas[j] = tmp;
            i++;
            j--;
        }
    } while (i <= j);
    if (j > 0) {

        qi_sort(mas, j + 1);
    }
    if (i < size) {
        qi_sort(&mas[i], size - i);
    }
}