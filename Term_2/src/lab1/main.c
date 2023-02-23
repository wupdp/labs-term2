#include "header.h"
//init sort
//work menu
//CMAKE
//SONAR

int main()
{
    setlocale(LC_ALL, "RUS");
    FILE *f;
    f = fopen("Struct.txt", "r");
    if (f == NULL)
    {
            printf("ERROR0");
            return 0;
    }
    int num;
    printf("¬ведите кол-во структур\n");
    num = init_x( 1, 15);
    Temp_t* mas_struct;
    mas_struct_init(&mas_struct, num);
    mas_struct_parsing(&mas_struct, f, num);
    insertion_sort(mas_struct, num);
    mas_struct_output(mas_struct, num);
    fclose(f);
    getchar();
    return EXIT_SUCCESS;
}