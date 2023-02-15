#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "functions.c"

void mas_struct_init(Temp_t** mas_struct, int num);
void mas_struct_output(Temp_t mas_struct);
void mas_struct_input(Temp_t** mas_struct, int i);


//enum 
//russian lang add
//init sort
//work menu 
//CMAKE
//SONAR
//HTML parsing

int main()
{
    int num = 0;
    num = init_x( 1, 10);
    Temp_t* mas_struct;
    mas_struct_init(&mas_struct, num);
    for(int i = 0; i < num; i++)
        mas_struct_input(&mas_struct, i);
    for(int i = 0; i < num; i++)
        mas_struct_output(mas_struct[i]);
    mas_struct_add(&mas_struct, &num);
    for(int i = 0; i < num; i++)
        mas_struct_output(mas_struct[i]);
    mas_struct_delete(&mas_struct, &num, 1);
    for(int i = 0; i < num; i++)
        mas_struct_output(mas_struct[i]);
    return 0;
}