#include <stdio.h>
#include <stdlib.h>
int main()
{
	int massive[10][12];
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
			for (int i = 0; i < 10; i++)							//ввод пользователем
			{
                for  (int j=0; j<12; j++)
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
		for (int i = 0; i < 10; i++)							
			{
                for  (int j=0; j<12; j++)
            {
				massive[i][j] = rand() % 100-50;
			}
		    }
            break;
            }
            for (int i = 0; i < 10; i++)						
			{
                for  (int j=0; j<12; j++)
            {
				printf("%4d",massive[i][j]);
			}
            printf("\n");
		    }
            int line, column;
            int flag=0;
for (int i=0,j=0;i<10;i++)						//столбцы	
			{
                 int num = massive[i][j];         //проверяемое число
                for  (j=0; j<12; j++)          
            {
                    if (num<massive[i][j])      //поиск наибольшего в строке
                    {
                    num=massive[i][j];
                    line =j;
                    column = i;
                    }
			}
               for (int i2 = 0; i2 < 10; i2++)	    //проверка на наименьшее в столбце
               {
                if (num>massive[i2][line])
                flag=1;
			   }
               if (flag==0)
                printf("element index: %d %d\n", column, line);
				j=0;
			}
			for (int i=0,j=0;i<10;i++)						//столбцы	
			{
                 int num = massive[i][j];         //проверяемое число
                for  (j=0; j<12; j++)          
            {
                    if (num>massive[i][j])      //поиск наименьшего в строке
                    {
                    num=massive[i][j];
                    line =j;
                    column = i;
                    }
			}
               for (int i2 = 0; i2 < 10; i2++)	    //проверка на наибольшее в столбце
               {
                if (num<massive[i2][line])
                flag=1;
			   }
               if (flag==0)
                printf("element index: %d %d\n", column, line);
				j=0;
			}
             getchar();
            return 0;
}