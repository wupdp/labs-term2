#include <stdio.h>
#include <stdlib.h>
#include "header.h"
#include "array.h"

int main()
{ 
        int length;
        int* mas=NULL;
    printf("Enter the length\n");
        length=InitX(length,1,999);
    mas=MassiveInput(length);
    RowInit(length,mas);
    massive1Show(mas,length);
        for(int i=0;i<length;i++)
    {
        if (mas[i]<0)
        {
            for(int j=i;    j<length;   j++)
            mas[j]=mas[j+1];
            length--;
            i--;
            mas=realloc(mas,length);
        }
    }
    massive1Show(mas,length);
}