#include <stdio.h>
#include <stdlib.h>
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


int initX(int min, int max)
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
	int** mas = (int**)calloc(r, sizeof(int*));
	for (int i = 0; i < r; i++)
		mas[i] = massiveInit(l);
	return mas;
}


void rowInput(int* mas, int l)
{
	for (int i = 0; i < l; i++)
	{
		mas[i] = initX(-999, 999);
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
		mas[i] = rand() % 200 - 100;
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

void ranInputMas(int** mas, int r, int l)
{
	for (int i = 0; i < r; i++)
	{
		ranInputRow(mas[i],l);
	}
	for(int j=0;j<l;j++)
	 mas[r][j]=colSum(mas,r,j);
}

void colSwap(int** mas, int row, int j1, int j2)
{
	for (int i0 = 0; i0 < row; i0++)
	{
		int temp = mas[i0][j1];
		mas[i0][j1] = mas[i0][j2];
		mas[i0][j2] = temp;
	}
}

void q_sort(int** MAS,int* mas, int row, int size) {
	int i = 0;
	int j = size - 1;

	int mid = mas[size / 2];

	
	do {
		while (mas[i] > mid) {
			i++;
		}
		while (mas[j] < mid) {
			j--;
		}

		if (i <= j) {
			int tmp = mas[i];
			mas[i] = mas[j];
			mas[j] = tmp;
			colSwap(MAS,row,i,j);
			i++;
			j--;
		}
	} while (i <= j);
	if (j > 0) {

		q_sort(MAS,mas,row, j + 1);
	}
	if (i < size) {
		q_sort(MAS, &mas[i],row, size - i);
	}
}

void free_mas(int **mas,int r)
{
	for(int i = 0;i<r;i++)
	free(mas[i]);
}