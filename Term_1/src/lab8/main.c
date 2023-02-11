#include <stdio.h>
#include <stdlib.h>
#include "header.h"

int main(int argc, char **argv) {
    check_argc(argc);
    char **str_mas = NULL;
    str_mas_init(str_mas, argv, argc);
    copy_array(argv, str_mas, argc);
    //delete_1string(argc, str_mas);
    //qi_sort(str_mas, argc);
    print_array(str_mas, argc);
    free_mas(str_mas, argc);
}