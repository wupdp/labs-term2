#include"header.h"
int main()
{
	int length, row;
	printf("Enter the number of columns:\n");
	length = init_x(1, 1000);
	printf("Enter the number of rows:\n");
	row = init_x(1, 1000);
	int** mas = massive2_init(row+1, length);
	ran_input_mas(mas, row, length);
	massive2_show(mas, row+1, length);
    printf("\n\n");
	 qi_sort(mas, 0, length-1,row,length);
    massive2_show(mas, row+1, length);
    free_mas(mas,row);
}