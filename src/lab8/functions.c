
#include <stdio.h>
#include <stdlib.h>

void free_mas(int **mas, int r) {
    for (int i = 0; i < r; i++)
        free(mas[i]);
}



void str_mas_init(char**str_mas,char**argv,int argc)
{
    char **str_mas = (char **) malloc(argc * (sizeof(char *)));
    for (int i = 0; i < argc; i++)
    str_mas[i] = (char*)malloc(get_length(argv, i) * sizeof(char));
}

void delete_1string(int argc,char** str_mas)
{
     for (int i = 0; i < argc - 1; i++)
        *(str_mas + i) = *(str_mas + i + 1);
        argc--;
}


check_argc(int argc)
{
      if (argc < 2)
    {
        printf("No arguments, restart");
        return 0;
    }
}




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
    return cnt+1;
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


void qi_sort(int** mas, int size) {
	int i = 0;
	int j = size - 1;

	int mid = get_length(mas,size / 2);

	
	do {
		while (get_length(mas,i) > mid) {
			i++;
		}
		while (get_length(mas,j) < mid) {
			j--;
		}

		if (i <= j) {
			int *tmp = mas[i];
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