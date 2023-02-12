#include <stdio.h>
#include <stdlib.h>

typedef struct Temp_Struct
{
    int pol1;
    int pol2;
    float pol3;
}Temp_t;

void mas_struct_init(Temp_t** mas_struct, int num)
{
    (*mas_struct) = (Temp_t*)malloc(sizeof(Temp_t)*num);
}

void mas_struct_output(Temp_t mas_struct)
{
    printf("%d\t%d\t%f", mas_struct.pol1, mas_struct.pol2, mas_struct.pol3);
}

void mas_struct_input(Temp_t** mas_struct, int i)
{
    int buffer;
    float fbuffer;
    printf("Enter pol1:\t");
    scanf("%d", &buffer);
    //(*mas_struct)[i] = malloc(sizeof(buffer));
    (*mas_struct)[i].pol1 = buffer;
    printf("Enter pol2:\t");
    scanf("%d", &buffer);
    (*mas_struct)[i].pol2 = buffer;
    printf("Enter pol3:\t");
    scanf("%f", &fbuffer);
    (*mas_struct)[i].pol3 = fbuffer;
}

//void mas_struct_sort(Temp_t *mas_struct, int num)
