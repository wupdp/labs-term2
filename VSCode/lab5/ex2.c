#include <stdio.h>
#include <stdlib.h>
#include "header.h"

int main()
{   
    int rows;
    printf("Enter the number of rows\n");
    rows=InitX(rows,1,99);
    int** mas;
    mas=massive2Init(rows);
    printf("________________________\n");
    massive2Show(mas,rows);
    printf("________________________\n");
    for(int i =1;i<rows;i+=2)
    {
       int min=mincheck(mas[i]);
       for(int j=0;mas[i][j]!=0;j++)
       {
        if (mas[i][j]==min)
            {
            int length=j;
            for(int j1=j;   mas[i][j1]!=0;  j1++)
            {
                length++;
            mas[i][j1]=mas[i][j1+1];
            }
            mas=realloc(mas,length);
            j=-1;
            }
       }
    }
    massive2Show(mas,rows);
    return 0;
}