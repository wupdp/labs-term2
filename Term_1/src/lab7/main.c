#include "header.h"



int main() {
  char *string = calloc(200, 1);
    int length = 2;
    printf("\tEnter the string here:\n");
    string = get_string(&string, &length);
    
    return 0;
}