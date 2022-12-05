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
    ex3(mas,length);
     matricsShow(mas,length);
     freemassive(mas,length);
     return 0;
}