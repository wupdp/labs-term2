#include <stdio.h>
#include <stdlib.h>
#include "functions.c"
int main(int argc, char **argv){
    if (argc < 2)
    {
        printf("No arguments, restart");
        return 0;
    }
   char **str_mas = (char **) malloc(argc * (sizeof(char *)));
    for (int i = 0; i < argc; i++)
        str_mas[i] = malloc(get_length(argv, i) * sizeof(char));
        copyArray(argv, str_mas, argc);
        show_string(str_mas[argc]);
}