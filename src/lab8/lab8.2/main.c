#include "header.h"

int main(int argc, char **argv)
{
    char **str_mas =str_init(str_mas,argc,argv);
    copy_array(argv, str_mas, argc);
    delete_1string(str_mas, argc);
    argc--;
    str_mas = (char **) realloc(str_mas, argc * (sizeof(char *)));
    qi_sort(str_mas,argc);
    print_array(str_mas, argc);
}