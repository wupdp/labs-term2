#include <stdio.h>
#include <stdlib.h>
#include "header.h"

int main()
{ 
    int length;
    int* mas=NULL;
    printf("Enter the length\n");
    length=init_x(length,1,999);
    mas=massive_init(length);
    row_init(length,mas);
    massive1_show(mas,length);
    delete_neg(mas,&length);
    printf("\n\n\n");
    massive1_show(mas,length);
    free(mas);
}