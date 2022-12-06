#include <stdio.h>
#include <stdlib.h>
#include "header.h"

int minFind0(int* mas, int l, int i)
{
	int mini = mas[i];
	for (; i < l; i++)
	{
		if (mas[i] < mas[mini])
			mini = i;
	}
	return mini;
}


int minFind1(int* mas, int l, int i)
{
	int mini = mas[i];
	for (; i < l; i++)
	{
		if (mas[i] <= mas[mini])
			mini = i;
	}
	return mini;
}

void swap(int* a, int* b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}


int initX( int min, int max)
{
	int x;
	while (scanf_s("%d", &x) != 1 || x < min || x >max || getchar() != '\n')	
	{
		printf("Error\n");
		rewind(stdin);
	}
	return x;
}

int* massiveInit(int l)
{
	int* mas;
	mas = (int*)calloc(l, sizeof(int));
	return mas;
}
int** massive2Init(int r, int l)
{
	int** mas = (int**)calloc(r, sizeof(int));
	for (int i = 0; i < r; i++)
		mas[i] = massiveInit(l);
	return mas;
}


void rowInput(int* mas, int l)
{
	for (int i = 0; i < l; i++)
	{
		mas[i] = initX( -999, 999);
	}
}

void massive2Input(int l, int length, int** mas)                 
{
	for (int i = 0; i < l; i++)
	{
		printf("Input values of %d row\n", (i + 1));
		rowInput(mas[i], length);
	}
}

void massive1Show(int* mas, int l)                               
{
	for (int i = 0; i < l; i++)
	{
		printf("%4d", mas[i]);
	}
	printf("\n");
}


void massive2Show(int** mas, int r, int l)                               
{
	for (int i = 0; i < r; i++)
		massive1Show(mas[i], l);
}

void ranInputRow(int* mas, int l)
{
	for (int i = 0; i < l; i++)
		mas[i] = rand() % 2000 - 1000;
}

void ranInputMas(int** mas, int r, int l)
{
	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < l; j++)
			mas[i][j] = rand() % 200 - 100;
	}
}


void badCase(int* mas, int l)
{
	mas[0] = 0;
	for (int i = 1; i < l; i++)
		mas[i] =l-i;
}

void bubbleSort(int* mas, int l)
{
	int min0 = minFind0(mas, l, 0), min1 = minFind1(mas, l, minFind0(mas, l, 0) + 1);
	for (int i = min0; i < min1 - 2; i+=2)
		for (int j = min0; j < min1 - i - 2; j+=2)
			if (mas[j] > mas[j + 2])
				swap(&mas[j], &mas[j + 2]);
}


void insertionSort(int* mas, int l)
{
	int temp;
	int min0 = minFind0(mas, l, 0), min1 = minFind1(mas, l, minFind0(mas, l, 0) + 1);
	for (int i = min0 + 2; i <= min1; i++)
		//for (int i = 3; i <l; i=i+2)
	{
		if (i % 2 != 0)
		{
			temp = mas[i];
			int j = i - 2;
			while (j >= min0 && mas[j] > temp)
			{
				mas[j + 2] = mas[j];
				j -= 2;
			}
			mas[j + 2] = temp;
		}
	}
}

int colSum(int** mas, int row, int j)
{
	int sum = 0;
	for (int i0 = 0; i0 < row; i0++)
	{
		sum += mas[i0][j];
	}
	return sum;
}

void colSwap(int** mas, int row,int j1 , int j2)
{
	for (int i0 = 0; i0 < row; i0++)
	{
		int temp = mas[i0][j1];
		mas[i0][j1] = mas[i0][j2];
		mas[i0][j2] = temp;
	}
}


void qsortM(int** mas, int row,int l ) 
{
	int i = 0;
	int j = l - 1;
	int mid = colSum(mas,row,l/2);
	do {
		while (colSum(mas, row,i) < mid)
		{
			i++;
		}
		while (colSum(mas, row,j) > mid)
		{
			j--;
		}
		if (i <= j) 
		{
			colSwap(mas,row,j,i);

			i++;
			j--;
		}
	} while (i <= j);
	if (j > 0) 
	{
		qsortM(mas,row, j + 1);
	}
	if (i < l)
	{
		qsortM(&mas[i],row, l - i);
	}
}


void q_sort(int* mas, int size) {
	int i = 0;
	int j = size - 1;

	int mid = mas[size / 2];

	
	do {
		while (mas[i] < mid) {
			i++;
		}
		while (mas[j] > mid) {
			j--;
		}

		if (i <= j) {
			int tmp = mas[i];
			mas[i] = mas[j];
			mas[j] = tmp;

			i++;
			j--;
		}
	} while (i <= j);
	if (j > 0) {

		q_sort(mas, j + 1);
	}
	if (i < size) {
		q_sort(&mas[i], size - i);
	}
}



void mas_copy(int* mas1,int* mas2,int l)
{
    for (int i=0;i<l;i++)
    {
        mas1[i]=mas2[i];
    }

} 