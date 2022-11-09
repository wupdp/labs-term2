#include <stdio.h>
#include <stdlib.h>
#include "header.h"
int main()
{
    int length;
    int** mas=NULL;
    printf("Enter the length\n");
    length=InitX(length,1,999);
    mas=MatricsInit(length);
    matricsInput(mas,length);
    matricsShow(mas,length);
    printf("________________________\n");
    for(int j = 0; j < length; j++)
    {   
        int temp=mas[0][j];
        for(int i = 0; i < length-1; i++)
        {   
            mas[i][j]=mas[i+1][j];
        }
        mas[length-1][j]=temp;
    }
     matricsShow(mas,length);
}