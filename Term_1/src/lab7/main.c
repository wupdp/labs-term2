#include "header.h"


void swap_words(char* string)
{
    int k, flag=0;
    for(int i=0;string[i]!='\0';i++)
    {
        if(string[i-1]==' ' && string[i]!=' ')
        k++;
        if (k==4)
        {
            int left=0;
            int rigth=i;
            if (minword(k)>minword(0))
            flag=1;
            for(int j=0;j < minlenword;j++)
            swap(1,2);
            
            for(int j = minlenword; j< maxlenword; j++)
            {
                if (flag==1)
                
            }
        }
    }
}







int main() {
  char *string = calloc(200, 1);
    int length = 2;
    printf("\tEnter the string here:\n");
    string = get_string(&string, &length);
    
    return 0;
}