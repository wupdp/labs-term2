#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "functions.c"

void mas_struct_init(Temp_t** mas_struct, int num);
void mas_struct_output(Temp_t mas_struct);
void mas_struct_input(Temp_t** mas_struct, int i);

int main()
{
    Temp_t* mas_struct;
    mas_struct_init(&mas_struct, 1);
    mas_struct_input(&mas_struct, 0);
    mas_struct_output(mas_struct[0]);
    return 0;
}