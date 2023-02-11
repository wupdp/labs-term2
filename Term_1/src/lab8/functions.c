
#include <stdio.h>
#include <stdlib.h>

void free_mas(char **mas, int r) {
    for (int i = 0; i < r; i++)
        free(mas[i]);
}


int get_length(char **s, int num) {
    int cnt = 0, i = 0;
    while (s[num][i] != '\0') {
        cnt++;
        i++;
    }
    return cnt + 1;
}


void str_mas_init(char**str_mas,char**argv,int argc)
{
   str_mas = (char **) malloc(argc * (sizeof(char *)));
    for (int i = 0; i < argc; i++)
    str_mas[i] = (char*)malloc(get_length(argv, i) * sizeof(char));
}

void delete_1string(int argc,char** str_mas)
{
     for (int i = 0; i < argc - 1; i++)
        *(str_mas + i) = *(str_mas + i + 1);
     argc--;
}


int check_argc(int argc)
{
      if (argc < 2)
    {
        printf("No arguments, restart");
        return 0;
    }
    return 1;
}

void copy_array(char **str1, char **str2, int str_num)
{
    for (int i = 0; i < str_num; i++)
        for (int j = 0; j < get_length(str1, i); j++)
            *(*(str2 + i) + j) = *(*(str1 + i) + j);
}

void print_array(char **arr, int str_num)
{
    for (int i = 0; i < str_num; i++)
        printf("%s\n", arr[i]);
}

void qi_sort(char **mas, int size) {
    int i = 0;
    int j = size - 1;

    int mid = get_length(mas, size / 2);


    do {
        while (get_length(mas, i) > mid) {
            i++;
        }
        while (get_length(mas, j) < mid) {
            j--;
        }

        if (i <= j) {
            char *tmp = mas[i];
            mas[i] = mas[j];
            mas[j] = tmp;
            i++;
            j--;
        }
    } while (i <= j);
    if (j > 0) {

        qi_sort(mas, j + 1);
    }
    if (i < size) {
        qi_sort(&mas[i], size - i);
    }
}