#include "header.h"

//char *strstr(const char *haystack, const char *needle); // Находит полное вхождение строки needle в haystack
//size_t strxfrm(char *dest, const char *src, size_t n);  // Преобразует первые n символов строки src в текущую локаль и помещает их в строку dest.
//char *strchr(const char *s, int c); - Ищет в строке s первое вхождение символа c, начиная с начала строки. В случае успеха возвращает указатель на найденный символ, иначе возвращает нуль.
//char *strrchr(const char *s, int c); - Аналогично предыдущему, только поиск осуществляется с конца строки.
//void *memcpy(void *dest, const void *src, size_t n)
//Копирует n символов из src в dest.)

int init_x (int min, int max) {
    int x;
    while (scanf_s("%d", &x) != 1 || x < min || x > max || getchar() != '\n') {
        printf("Ошибка, введите значение между %d и %d.\n", min, max);
        rewind(stdin);
    }
    fflush(stdin);
    return x;
}

void mas_struct_init (COMPANIES_STRUCT **mas_struct, int num) {
    (*mas_struct) = (COMPANIES_STRUCT *) calloc(num, sizeof(COMPANIES_STRUCT));
}

void mas_struct_output_i (COMPANIES_STRUCT *mas_struct, int i) {
    setlocale(LC_ALL, "RUS");
    printf("%d-я Структура\n", i + 1);
    printf("Название:\t");
    puts(mas_struct[i].name);
    printf("Пол HR-менеджера:\t");
    if (mas_struct[i].sex == MAN)
        printf("муж.\n");
    else if (mas_struct[i].sex == WOMAN)
        printf("жен.\n");
    else if (mas_struct[i].sex == ELSE)
        printf("Не определился/ась/ось\n");
    printf("Оклад:\t%d RUB\n", mas_struct[i].salary);
    printf("Адрес:\t");
    puts(mas_struct[i].address);
    printf("Телефонный номер:\t");
    puts(mas_struct[i].number);
    printf("\n");
}

void mas_struct_output (COMPANIES_STRUCT *mas_struct, int num) {
    setlocale(LC_ALL, "RUS");
    for (int i = 0; i < num; i++)
        mas_struct_output_i(mas_struct, i);
}

void mas_struct_parsing (COMPANIES_STRUCT **mas_struct, FILE *f, int num) {
    int i = 0, j = 0, k = 0;
    char *buffer;
    char *buffer2;
    char *end_str;
    buffer = (char *) calloc(255, 1);
    buffer2 = (char *) calloc(255, 1);
    while (!feof(f)) {
        if (fgets(buffer, 255, f) != NULL) {
            if (strstr(buffer, "company-info-name-org") != NULL) {
                buffer2 = strrchr(buffer, '\"') + 2;
                end_str = strrchr(buffer, '<');
                *end_str = '\0';
                (*mas_struct)[i].name = (char *) calloc(strlen(buffer2), 1);
                strcpy((*mas_struct)[i].name, buffer2);
                i++;
            }
            if (strstr(buffer, "address class=") != NULL) {
                fgets(buffer2, 255, f);
                for (unsigned i_len = strlen(buffer2); i_len > 0; i_len--) {
                    if (buffer2[i_len - 1] != ' ' && buffer2[i_len - 1] != '\n' && buffer2[i_len - 1] != '\t') {
                        buffer2[i_len] = '\0';
                        break;
                    }
                }
                (*mas_struct)[j].address = (char *) calloc(strlen(buffer2), 1);
                strcpy((*mas_struct)[j].address, buffer2 + 16);
                j++;
            }
            if (strstr(buffer, "company-info-phone-number") != NULL) {
                fgets(buffer2, 255, f);
                for (unsigned i_len = strlen(buffer2); i_len > 0; i_len--) {
                    if (buffer2[i_len - 1] != ' ' && buffer2[i_len - 1] != '\n' && buffer2[i_len - 1] != '\t') {
                        buffer2[i_len] = '\0';
                        break;
                    }
                }
                (*mas_struct)[k].number = (char *) calloc(strlen(buffer2), 1);
                strcpy((*mas_struct)[k].number, buffer2 + 2);
                k++;
                printf("%d struct: Success\n", k);
                if (k == num)
                    break;
            }
        } else {
            perror("ERROR_GETS");
        }
    }
    for (int n = 0; n < num; n++) {
        (*mas_struct)[n].salary = rand() % 100 * 1000;
        (*mas_struct)[n].sex = rand() % 3;
    }
}

void mas_struct_input (COMPANIES_STRUCT **mas_struct, int i) {
    setlocale(LC_ALL, "RUS");
    char *buffer = (char *) calloc(255, 1);
    printf("Введите название:\t");
    if (gets(buffer) == NULL) {
        printf("Error");
        rewind(stdin);
    }
    (*mas_struct)[i].name = (char *) calloc(strlen(buffer), 1);
    strcpy((*mas_struct)[i].name, buffer);
    printf("Введите адрес:\t");
    if (gets(buffer) == NULL)
        printf("Error");
    (*mas_struct)[i].address = (char *) calloc(strlen(buffer), 1);
    strcpy((*mas_struct)[i].address, buffer);
    printf("Введите номер телефона:\t");
    if (gets(buffer) == NULL)
        printf("Error");
    (*mas_struct)[i].number = (char *) calloc(strlen(buffer), 1);
    strcpy((*mas_struct)[i].number, buffer);
    printf("Введите оклад:\t");
    (*mas_struct)[i].salary = init_x(16242, 1000000);
    printf("Введите пол HR-менеджера:\t");
    (*mas_struct)[i].sex = init_x(0, 2);
}

void mas_struct_add (COMPANIES_STRUCT **mas, int *num) {
    (*num)++;
    (*mas) = (COMPANIES_STRUCT *) realloc(*mas, sizeof(COMPANIES_STRUCT) * (*num));
    mas_struct_input(mas, (*num) - 1);
}

void mas_struct_delete (COMPANIES_STRUCT **mas, int *num, int i) {
    (*num)--;
    free((*mas)[i].name);
    free((*mas)[i].address);
    free((*mas)[i].number);
    for (; i < (*num); i++)
        (*mas)[i] = (*mas)[i + 1];
    (*mas) = (COMPANIES_STRUCT *) realloc((*mas), (*num) * sizeof(COMPANIES_STRUCT));
}

void swap (COMPANIES_STRUCT *a, COMPANIES_STRUCT *b) {
    COMPANIES_STRUCT temp = *a;
    *a = *b;
    *b = temp;
}

void insertion_sort (COMPANIES_STRUCT *mas, int n) {
    for (int k = 1; k < n; k++)
        for (int i = k; i > 0 && mas[i - 1].salary >= mas[i].salary; i--) {
            if (mas[i - 1].salary > mas[i].salary)
                swap(&mas[i], &mas[i - 1]);
            else {
                if (mas[i - 1].sex > mas[i].sex)
                    swap(&mas[i], &mas[i - 1]);
            }
        }
}

void delete_all_mas (COMPANIES_STRUCT **mas, int *num) {
    for (int i = 0; i < *num; i++)
        mas_struct_delete(mas, num, i);
    free(*mas);
}