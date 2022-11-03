#include <stdio.h>
#include <stdlib.h>

int InitX(int x, int min, int max)
{
    while (scanf_s("%d", &x) != 1 || x < min || x >max||getchar()!='\n')		//проверка на ввод и ввод длины массива
	{
		printf("error\n");
		rewind(stdin);
	}
	return x;
}

int* MassiveInput(int l)
{
	int* mas;
	mas=(int*	)calloc(l,	sizeof(int));
}



void massive2Init(int x, int l,int** mas)                   //ввод двумерного массива
{
    switch (x)
		{
		case 1:
			for (int i = 0; i < l; i++)							//ввод пользователем
			{
                for  (int j=0; j<l; j++)
            {
				printf("enter %d %d number of massive		", i + 1, j+1);
				while (scanf_s("%4d", &mas[i][j]) != 1 || getchar() != '\n')		//проверка на ввод
				{
					printf("error\n");
					rewind(stdin);
				}
			}
            }
			break;
		case 2:														
		for (int i = 0; i < l; i++)							
			{
                for  (int j=0; j<l; j++)
            {
				mas[i][j] = rand() % 100-50;
			}
		    }
            break;
            }
}

void massive2Show(int** mas, int l)                                 //вывод двумерного массива
{
    for (int i = 0; i < l; i++)							
		{
        for  (int j=0; j<l; j++)
        {
		printf("%4d",mas[i][j]);
		}
            printf("\n");
		}
}

void RowInit( int l,int* mas)                       //ввод одномерного массива
{
			for (int i = 0; i < l; i++)							//ввод пользователем
			{
				printf("enter %d number of massive		", i + 1);
				mas[i]=InitX(mas[i],-999,999);
            }
}

void massive1Show(int* mas, int l)                                 //вывод одномерного массива
{
    for (int i = 0; i < l; i++)							
		{
		printf("%4d", mas[i]);
		}
		printf("\n");
}


void input_row(int *mas, int n)
{
    //srand(time(NULL));
    for (int i = 0; i < n; i++)
        *(mas+i) = rand() % 51;
}


void print_row(int *m, int n)
{
    for (int i = 0; i < n; i++)
        printf("%d  ", *(m + i)); // m[i]
    printf("\n");
}

void DeleteNeg(int* mas, int length)
{
	for(int i=0;i<length;i++)
    {
        if (mas[i]<0)
        {
            for(int j=i;    j<length;   j++)
            mas[j]=mas[j+1];
            length=length-1;
            i--;
            mas=(int*)realloc(mas,length);
        }
    }
}