#include <stdio.h>
#include <stdlib.h>
int main()
{
	int massive[100][100];
    int line, column;
    printf("enter the number of lines(<100)\n");
	while (scanf_s("%d", &line) != 1 || line < 1 || line >100||getchar()!='\n')		//проверка на ввод
	{
		printf("error\n");
		rewind(stdin);
	}
    printf("enter the number of columns(<100)\n");
	while (scanf_s("%d", &column) != 1 || column < 1 || column >100||getchar()!='\n')		//проверка на ввод
	{
		printf("error\n");
		rewind(stdin);
	}
    printf("enter 1 to enter the array elements yourself\n");  //выбор пользователя
	printf("enter 2 to randomly enter array elements\n");
	int x;
	while (scanf_s("%d", &x) != 1 || x<1 || x>2 || getchar() != '\n')
	{
		printf("incorrect enter\n");
		rewind(stdin);
	}
		switch (x)
		{
		case 1:
			for (int i = 0; i < line; i++)							//ввод пользователем
			{
                for  (int j=0; j<column; j++)
            {
				printf("enter %d %d number of massive		", i + 1, j+1);
				while (scanf_s("%4d", &massive[i][j]) != 1 || getchar() != '\n')		//проверка на ввод
				{
					printf("error\n");
					rewind(stdin);
				}
			}
            }
			break;
		case 2:															//случайный ввод
		for (int i = 0; i < line; i++)							//ввод пользователем
			{
                for  (int j=0; j<column; j++)
            {
				massive[i][j] = rand() % 100-50;
			}
		    }
            break;
            }
            for (int i = 0; i < line; i++)							//ввод пользователем
			{
                for  (int j=0; j<column; j++)
            {
				printf("%4d",massive[i][j]);
			}
            printf("\n");
		    }
 printf("\n__________________________________________________________________________\n\n");  
int flag=0,num;
for (int i = 0; i < line; i++)						
			{
                for  (int j=0; j<column; j++)
            {
                if (massive[i][j]>=0)
                flag=1;
            }
            if (flag==0)
            {
                num=massive[i][0];
                 for  (int j=0; j<column; j++)
                 {
                    massive[i][j]=massive[i][j]+num;
                 }
            }
             if (flag==0) break;
            flag=0;
            }
              for (int i = 0; i < line; i++)							
			{
                for  (int j=0; j<column; j++)
            {
				printf("%4d",massive[i][j]);
			}
            printf("\n");
		    }
			    getchar();
return 0;
}