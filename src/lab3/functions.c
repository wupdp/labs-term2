#include "header.h"

const char *get_file_name() {
    char* name = calloc(1, 1);
    printf("Enter image name or address\n");
    gets(name);
    return (const char *) name;
}

FILE* file_open(const char* name){
    FILE* image_bi = fopen("name_of_file", "rb");
    if(image_bi == NULL){
        printf("File is not exist\n");
        exit(EXIT_SUCCESS);
    }
    return image_bi;
}

void