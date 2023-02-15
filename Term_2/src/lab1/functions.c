#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "header.h"

typedef struct Temp_Struct
{
    char* str1;
    char* str2;
    char* str3;
    unsigned int id;
}Temp_t;


//char *strstr(const char *haystack, const char *needle); // Находит полное вхождение строки needle в haystack

//size_t strxfrm(char *dest, const char *src, size_t n);  // Преобразует первые n символов строки src в текущую локаль и помещает их в строку dest.

int init_x(int min, int max) {
    int x;
    while (scanf_s("%d", &x) != 1 || x < min || x > max || getchar() != '\n') {
        printf("Error\n");
        rewind(stdin);
    }
    fflush(stdin);
    return x;
}

void mas_struct_init(Temp_t** mas_struct, int num)
{
    (*mas_struct) = (Temp_t*)calloc(num, sizeof(Temp_t));
}

void mas_struct_output(Temp_t mas_struct)
{
    puts(mas_struct.str1);
    puts(mas_struct.str2);
    puts(mas_struct.str3);
    printf("%d\n", mas_struct.id);
}

void mas_struct_input(Temp_t** mas_struct, int i)
{
    char* buffer = (char*)calloc(255, 1);
    printf("Enter str1:\t");
    if (gets(buffer) == NULL){
        printf("Error");
        rewind(stdin);
    }
    (*mas_struct)[i].str1 = (char*)calloc(strlen(buffer), 1);
    strcpy((*mas_struct)[i].str1, buffer);
    printf("Enter str2:\t");
    if (gets(buffer) == NULL)
        printf("Error");
    (*mas_struct)[i].str2 = (char*)calloc(strlen(buffer), 1);
    strcpy((*mas_struct)[i].str2, buffer);
    printf("Enter str3:\t");
    if (gets(buffer) == NULL)
        printf("Error");
    (*mas_struct)[i].str3 = (char*)calloc(strlen(buffer), 1);
    strcpy((*mas_struct)[i].str3, buffer);
}

void mas_struct_add(Temp_t** mas, int* num)
{
    (*num)++;
    (*mas) = (Temp_t*)realloc(*mas, sizeof(Temp_t) * (*num));
    mas_struct_input(mas, (*num) - 1);
}



void mas_struct_delete(Temp_t** mas, int* num, int i)
{
    (*num)--;
    for(;i < (*num); i++)
        (*mas)[i]=(*mas)[i + 1];
    (*mas) = (Temp_t*)realloc((*mas), (*num) * sizeof(Temp_t));
}
//void mas_struct_sort(Temp_t *mas_struct, int num)
