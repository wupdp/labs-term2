#include <stdio.h>
#include <stdlib.h>

int get_length(char **s, int k)
{
    int cnt = 0, i = 0;
    while (*(*(s + k) + i) != '\0')
    {
        cnt++;
        i++;
    }
    return cnt + 1;
}

void copy_array(char **resouce, char **result, int array)
{
    for (int i = 0; i < array; i++)
        for (int j = 0; j < get_length(resouce, i); j++)
            *(*(result + i) + j) = *(*(resouce + i) + j);
}

void print_array(char **arr, int array)
{
    for (int i = 0; i < array; i++)
        printf("%s          %d\n", *(arr + i), max_length(arr,i));
}

void delete_1string(char **arr, int array)
{
    for (int i = 0; i < array - 1; i++)
        *(arr + i) = *(arr + i + 1);
}

int if_letter(char s) {
    if ((s >= 'a' && s <= 'z') || (s >= 'A' && s <= 'Z'))
        return 1;
    return 0;
}

int max_length(char** str,int k)
{   int cnt=0;
    int i=0;
    int max_cnt=0;
    while(str[k][i]!='\0')
    {
        if(if_letter(str[k][i])==1)
        {
        for(int j = i; if_letter(str[k][j]) != 0; j++, i++)
        cnt++;
        i--;
        }
        if(max_cnt <= cnt)
        max_cnt=cnt;
        cnt=0;
        i++;
    }
    return max_cnt;
}


void qi_sort(char **mas, int size) {
    int i = 0;
    int j = size - 1;

    int mid = max_length(mas, size / 2);


    do {
        while (max_length(mas, i) > mid) {
            i++;
        }
        while (max_length(mas, j) < mid) {
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

char** str_init(char** str_mas,int argc, char** argv)
{
    str_mas = (char **) malloc(argc * (sizeof(char *)));
    for (int i = 0; i < argc; i++)
        *(str_mas + i) = (char *) malloc(get_length(argv, i) * sizeof(char));
return str_mas;
}