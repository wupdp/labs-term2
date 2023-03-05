#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <windows.h>
#ifndef LAB1_1_HEADER_H
#define LAB1_1_HEADER_H

enum Sex{
    MAN,
    WOMAN,
    ELSE
};

typedef struct Temp_Struct
{
    char* name;
    char* address;
    char* number;
    int salary;
    enum Sex sex;
}COMPANIES_STRUCT;

void delete_all_mas(COMPANIES_STRUCT **mas, int *num);

void mas_struct_output_i(COMPANIES_STRUCT *mas_struct, int i);

void insertion_sort(COMPANIES_STRUCT *mas, int n);

void mas_struct_init(COMPANIES_STRUCT** mas_struct, int num);

void mas_struct_output(COMPANIES_STRUCT *mas_struct, int num);

void mas_struct_input(COMPANIES_STRUCT** mas_struct, int i);

int init_x(int min, int max);

void mas_struct_add(COMPANIES_STRUCT** mas, int* num);

void mas_struct_delete(COMPANIES_STRUCT** mas, int* num, int i);

void mas_struct_parsing(COMPANIES_STRUCT **mas_struct, FILE* f, int num);

#endif //LAB1_1_HEADER_H
