#include <stdio.h>
#include <stdlib.h>
#include "header.h"
int main()
{
    int length;
    int** mas=NULL;
    printf("Enter the length\n");
    length=init_x(length,1,999);
    mas=matrics_init(length);
    matrics_input(mas,length);
    matrics_show(mas,length);
    printf("________________________\n");
    ex3(mas,length);
     matrics_show(mas,length);
     free_massive(mas,length);
     return 0;
}