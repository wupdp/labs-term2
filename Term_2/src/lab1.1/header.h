#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#ifndef LAB1_1_HEADER_H
#define LAB1_1_HEADER_H

typedef struct Temp_Struct
{
    char* name;
    char* address;
    char* number;
}Temp_t;

void mas_struct_init(Temp_t** mas_struct, int num);

void mas_struct_output(Temp_t *mas_struct, int num);

void mas_struct_input(Temp_t** mas_struct, int i);

int init_x(int min, int max);

void mas_struct_add(Temp_t** mas, int* num);

void mas_struct_delete(Temp_t** mas, int* num, int i);

void mas_struct_parsing(Temp_t **mas_struct, FILE* f, int num);

#endif //LAB1_1_HEADER_H
