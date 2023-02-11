#include <stdio.h>
#include <stdlib.h>
#include "array.c"
int init_x(int x, int min, int max);
int* massive_init(int l);
int** matrics_init(int l);
int** massive2_init(int l);
void massive2_show(int** mas, int l);
void row_init( int l,int* mas);   
void matrics_input(int** mas,int l);
void massive1_show(int* mas, int l);
void matrics_show(int** mas,int l);
int min_check(int *mas);
void delete_neg(int* mas, int* length);
void ex2(int** mas,int rows);
void ex3(int** mas,int length);
void free_massive(int** mas, int length);
int switch_init();
