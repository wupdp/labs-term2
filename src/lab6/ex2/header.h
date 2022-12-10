
#include <stdio.h>
#include <stdlib.h>
#include "functions.c"
int min_find0(int *mas, int l, int i);
int min_find1(int *mas, int l, int i);
void swap(int *a, int *b);
int init_x(int min, int max);
int *massive_init(int l);
int **massive2_init(int r, int l);
void row_input(int *mas, int l);
void massive2_input(int l, int length, int **mas);
void massive1_show(int *mas, int l);
void massive2_show(int **mas, int r, int l);
void ran_input_row(int *mas, int l);
void qi_sort(int **array, int n, int m,int N,int M);
void ran_input_mas(int **mas, int r, int l);
void free_mas(int **mas, int r);