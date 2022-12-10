#include <stdio.h>
#include <stdlib.h>
#include "header.h"

int main()
{   
    int rows;
    printf("Enter the number of rows\n");
    rows=init_x(rows,1,99);
    int** mas;
    mas=massive2_init(rows);
    printf("________________________\n");
    massive2_show(mas,rows);
    printf("________________________\n");
    ex2(mas,rows);
    massive2_show(mas,rows);
    free_massive(mas,rows);
    return 0;
}