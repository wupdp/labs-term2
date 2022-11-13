#include <stdio.h>
#include <stdlib.h>
#include "array.h"
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
int switchInit()
{
printf("enter 1 to enter the array elements yourself\n");  //выбор пользователя
	printf("enter 2 to randomly enter array elements\n");
	int x;
	while (scanf_s("%d", &x) != 1 || x<1 || x>2||getchar() != '\n')
	{
		printf("incorrect enter\n");
		rewind(stdin);
	}
    return x;
}
