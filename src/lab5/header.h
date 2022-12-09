#include <stdio.h>
#include <stdlib.h>
#include "array.c"
int InitX(int x, int min, int max);
int* MassiveInit(int l);
int** MatricsInit(int l);
int** massive2Init(int l);
void massive2Show(int** mas, int l);
void RowInit( int l,int* mas);   
void matricsInput(int** mas,int l);
void massive1Show(int* mas, int l);
void matricsShow(int** mas,int l);
int mincheck(int *mas);
void DeleteNeg(int* mas, int* length);
void ex2(int** mas,int rows);
void ex3(int** mas,int length);
void freemassive(int** mas, int length);
int switchInit();
