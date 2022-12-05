#include"header.h"
int main()
{
	int length, row;
	printf("Enter the number of columns:\n");
	length = initX(1, 1000);
	printf("Enter the number of rows:\n");
	row = initX(1, 1000);
	int** mas = massive2Init(row+1, length);
	ranInputMas(mas, row, length);
	massive2Show(mas, row+1, length);
    printf("\n\n");
    q_sort(mas,mas[row],row,length);
    massive2Show(mas, row+1, length);
    free_mas(mas,row);
}

