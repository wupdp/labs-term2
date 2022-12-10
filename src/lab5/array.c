#include <stdio.h>
#include <stdlib.h>


int init_x(int x, int min, int max)
{
    while (scanf_s("%d", &x) != 1 || x < min || x >max||getchar()!='\n')		//проверка на ввод и ввод длины массива
	{
		printf("Error\n");
		rewind(stdin);
	}
	return x;
}

int* massive_init(int l)
{
	int* mas;
	mas=(int*	)calloc(l,	sizeof(int));
	return mas;
}

int** matrics_init(int l)
{
	int** mas;
	mas=(int**	)calloc(l,	sizeof(int*));
	for(int i=0; i<l; i++)
    {
        mas[i] = (int *)calloc(l, sizeof(int)); 
    }
    return mas;
}



int** massive2_init(int l)                   //ввод двумерного массива
{
   int** mas=calloc(l,sizeof(int*));
   int length;
   for(int i=0; i<l; i++)
   {
	printf("Input the length of %d row\n", i+1);
	length=init_x(l,1,99);
	mas[i]=massive_init(length);
	printf("Input values\n");
	for(int j=0;j<length-1;j++)
	{
		mas[i][j]=init_x(mas[i][j],1,99);
	}
	mas[i][length-1]=0;
   }
   return mas;
}


void massive2_show(int** mas, int l)                                 //вывод двумерного массива
{
    for (int i = 0; i < l; i++)							
		{
			for (int j = 0; mas[i][j-1]!=0; j++)							
		{
		printf("%4d", mas[i][j]);
		}
		printf("\n");
		}
}

void row_init( int l,int* mas)                       //ввод одномерного массива
{
	for (int i = 0; i < l; i++)							//ввод пользователем
	{
		printf("enter %d number of row		", i + 1);
		mas[i]=init_x(mas[i],-999,999);
    }
}

void matrics_input(int** mas,int l)
{
	for(int i = 0; i < l; i++)
	{
		printf("Enter the %d row\n", i+1);
		row_init(l,mas[i]);
	}
}



void massive1_show(int* mas, int l)                                 //вывод одномерного массива
{
    for (int i = 0; i < l; i++)							
		{
		printf("%4d", mas[i]);
		}
		printf("\n");
}

void matrics_show(int** mas,int l)
{
	for(int i = 0; i < l; i++)
	massive1_show(mas[i],l);
}




void delete_neg(int* mas, int* length)
{
	for(int i=0;i<*length;i++)
    {
        if (mas[i]<0)
        {
            for(int j=i;    j<*length;   j++)
            mas[j]=mas[j+1];
            (*length)--;
            i--;
            mas=realloc(mas,*length);
        }
    }
}



int min_check(int *mas)
{
	int min=999;
	for(int i1=0;mas[i1]!=0;i1++)
	{
		if (mas[i1]<min)
		min=mas[i1];
	}
	return min;
}


void ex2(int** mas,int rows)
{
	for(int i =1;i<rows;i+=2)
    {
       int min=min_check(mas[i]);
       for(int j=0;mas[i][j]!=0;j++)
       {
        if (mas[i][j]==min)
            {
            int length=j;
            for(int j1=j;   mas[i][j1]!=0;  j1++)
            {
                length++;
            mas[i][j1]=mas[i][j1+1];
            }
            mas=realloc(mas,length);
            j=-1;
            }
       }
    }
	for(int i=0;i<rows;i++)
	{
		if (mas[i][0]==0)
		{
			for(int j=i;j<rows;j++)
			{
				mas[j]=mas[j+1];
			}
			rows--;
			mas=realloc(mas,rows);
			i--;
		}

	}
}


void ex3(int** mas,int length)
{
	for(int j = 0; j < length; j++)
    {   
        int temp=mas[0][j];
        for(int i = 0; i < length-1; i++)
        {   
            mas[i][j]=mas[i+1][j];
        }
        mas[length-1][j]=temp;
    }
}

void free_massive(int** mas, int length)
{
	for(int i=0;i<length;i++)
	free(mas[i]);
	free(mas);
}

int switch_init()
{
printf("enter 1 to enter the array elements yourself\n");  //выбор пользователя
	printf("enter 2 to randomly enter array elements\n");
	int x;
	while (scanf_s("%d", &x) != 1 || x<1 || x>2||getchar() != '\n')
	{
		printf("incorrect enter\n");
		rewind(stdin);
	}
    return x;
}