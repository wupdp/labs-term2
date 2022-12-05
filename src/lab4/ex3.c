#include <stdio.h>
#include <stdlib.h>
int main()
{
	int massive[100][100];
    int length;
    printf("enter the length(<100)\n");
	while (scanf_s("%d", &length) != 1 || length < 1 || length >100||getchar()!='\n')		//проверка на ввод
	{
		printf("error\n");
		rewind(stdin);
	}
    printf("enter 1 to enter the array elements yourself\n");  //выбор пользователя
	printf("enter 2 to randomly enter array elements\n");
	int x;
	while (scanf_s("%d", &x) != 1 || x<1 || x>2||getchar() != '\n')
	{
		printf("incorrect enter\n");
		rewind(stdin);
	}
		switch (x)
		{
		case 1:
			for (int i = 0; i < length; i++)							//ввод пользователем
			{
                for  (int j=0; j<length; j++)
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
		case 2:														
		for (int i = 0; i < length; i++)							
			{
                for  (int j=0; j<length; j++)
            {
				massive[i][j] = rand() % 100-50;
			}
		    }
            break;
            }
    for (int i = 0; i < length; i++)							
		{
        for  (int j=0; j<length; j++)
        {
		printf("%4d",massive[i][j]);
		}
            printf("\n");
		}
int sum=0;
for (int j=length-1;j>=length/2;j--)
{
    for (int i=length-j-1;i<=length/2;i++)
    {
        sum+=massive[i][j];
         massive[i][j]=0;
    }
}
for (int i=length/2;i<length;i++)
{
    for (int j=i;j<length;j++)
    {
        sum+=massive[i][j];
        massive[i][j]=0;
    }
}
printf("\n\nsum=%d", sum);
        getchar();
        return 0;
}