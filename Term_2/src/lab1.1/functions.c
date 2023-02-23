#include "header.h"


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

void mas_struct_output(Temp_t *mas_struct, int num)
{
    setlocale(LC_ALL, "RUS");
    for (int i = 0; i < num; i++) {
        printf("%d-я Структура\n", i+1);
        printf("Название:\t");
        puts(mas_struct[i].name);
        printf("Адрес:\t");
        puts(mas_struct[i].address);
        printf("Телефонный номер:\t");
        puts(mas_struct[i].number);
    }
}


void mas_struct_parsing(Temp_t **mas_struct, FILE *f, int num) {
    int i = 0, j = 0, k = 0;
    char* buffer;
    buffer = (char*)calloc(255, 1);
    while (!feof(f)) {
        if (fgets(buffer, 255, f) != NULL) {
            if (strstr(buffer, "company-info-name-org") != NULL) {
                printf("SUCCESS\n");
                (*mas_struct)[i].name = (char *) calloc(strlen(buffer), 1);
                strcpy((*mas_struct)[i].name, buffer);
                i++;
            }
            if (strstr(buffer, "address class=") != NULL) {
                (*mas_struct)[j].address = (char *) calloc(strlen(buffer), 1);
                strcpy((*mas_struct)[j].address, buffer);
                j++;
            }
            if (strstr(buffer, "company-info-phone-number") != NULL) {
                (*mas_struct)[k].number = (char *) calloc(strlen(buffer), 1);
                strcpy((*mas_struct)[k].number, buffer);
                k++;
                printf("SUCCESS3\n");
                if(k == num)
                    break;
            }
        }
        else {
            perror("ERROR_GETS");
        }
        }

}


void mas_struct_input(Temp_t** mas_struct, int i)
{
    char* buffer = (char*)calloc(255, 1);
    printf("Enter name:\t");
    if (gets(buffer) == NULL)
    {
        printf("Error");
        rewind(stdin);
    }
    (*mas_struct)[i].name = (char*)calloc(strlen(buffer), 1);
    strcpy((*mas_struct)[i].name, buffer);
    printf("Enter adress:\t");
    if (gets(buffer) == NULL)
        printf("Error");
    (*mas_struct)[i].address = (char*)calloc(strlen(buffer), 1);
    strcpy((*mas_struct)[i].address, buffer);
    printf("Enter index:\t");
    if (gets(buffer) == NULL)
        printf("Error");
    (*mas_struct)[i].number = (char*)calloc(strlen(buffer), 1);
    strcpy((*mas_struct)[i].number, buffer);
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