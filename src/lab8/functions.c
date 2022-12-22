
#include <stdio.h>
#include <stdlib.h>

void show_string(char *str) {
    for (int i = 0; (str[i]) != '\0'; i++) {
        printf("%c", (str[i]));
    }
    printf("\n");
}


void copyArray(char **resouce, char **result, int str_num)
{
    for (int i = 0; i < str_num; i++)
        for (int j = 0; j < get_length(resouce, i); j++)
            *(*(result + i) + j) = *(*(resouce + i) + j);
}

void printArray(char **arr, int str_num)
{
    for (int i = 0; i < str_num; i++)
        printf("%s\n", arr[i]);
}

int get_length(char **s, int num)
{
    int cnt = 0, i = 0;
    while (s[num][i] != '\0')
    {
        cnt++;
        i++;
    }
    return cnt;
}

char* get_string(char *s, int* k)
{
  int c, i=0;
  while((c = getchar())!=EOF && c != '\n')
  	{s[i++] = c;
    (*k)++;} 
  s[i] = '\0';
  return s; 
}