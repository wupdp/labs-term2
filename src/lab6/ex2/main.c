#include"header.h"
int main()
{
	 int y=1;
    do{
	int length, row;
	printf("Enter the number of columns:\n");
	length = initX(1, 1000);
	printf("Enter the number of rows:\n");
	row = initX(1, 1000);
	int** mas = massive2Init(row+1, length);
	ranInputMas(mas, row, length);
	massive2Show(mas, row+1, length);
    printf("\n\n");
	 qiSort(mas, 0, length-1,row,length);
    massive2Show(mas, row+1, length);
    freemas(mas,row);
	 printf("Do you want to repit?\n\t1 - Yes\t 0 - No\n\n");
	y=initX(0,1);
	}while(y==1);
}