#include <stdio.h>
#include <stdlib.h>
#include "functions.c"
int main(int argc, char **argv){
check_argc(argc);
char** str_mas=NULL;
str_mas_init(str_mas,argv,argc);
copyArray(argv, str_mas, argc);
delete_1string(argc,str_mas);
qi_sort(str_mas,argc);
printArray(str_mas,argc);
void free_mas(str_mas, argc);
}