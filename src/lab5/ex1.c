#include <stdio.h>
#include <stdlib.h>
#include "header.h"

int main()
{ 
    int length;
    int* mas=NULL;
    printf("Enter the length\n");
    length=InitX(length,1,999);
    mas=MassiveInit(length);
    RowInit(length,mas);
    massive1Show(mas,length);
    DeleteNeg(mas,&length);
    printf("\n\n\n");
    massive1Show(mas,length);
    free(mas);
}