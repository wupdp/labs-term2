#include <stdio.h>
#include <stdlib.h>
int main()
{
	int massive1[100],massive2[100];
	int n;
	n = 10;
	printf("enter 1 to enter the array elements of 1 massive yourself\n");  //выбор пользователя
	printf("enter 2 to randomly enter array elements\n");
	int x;
	while (scanf_s("%d", &x) != 1 || x < 1 || x>2 || getchar() != '\n')
	{
		printf("incorrect enter\n");
		rewind(stdin);
	}
	switch (x)
	{
	case 1:
		for (int i = 0; i < n; i++)							//ввод пользователем
		{
			printf("enter %d number of massive		", i + 1);
			while (scanf_s("%4d", &massive1[i]) != 1 || getchar() != '\n')		//проверка на ввод
			{
				printf("error\n");
				rewind(stdin);
			}
		}
		break;
	case 2:															//случайный ввод
		for (int i = 0; i < n; i++)
		{
			massive1[i] = rand() % 100;
			printf("%d number of massive		%d\n", i + 1, massive1[i]);
		}
		break;
	}
	printf("enter 1 to enter the array elements of 2 massive yourself\n");  //выбор пользователя
	printf("enter 2 to randomly enter array elements\n");
	int y;
	while (scanf_s("%d", &y) != 1 || y < 1 || y>2 || getchar() != '\n')
	{
		printf("incorrect enter\n");
		rewind(stdin);
	}
	switch (y)
	{
	case 1:
		for (int i = 0; i < n; i++)							//ввод пользователем
		{
			printf("enter %d number of massive		", i + 1);
			while (scanf_s("%4d", &massive2[i]) != 1 || getchar() != '\n')		//проверка на ввод
			{
				printf("error\n");
				rewind(stdin);
			}
		}
		break;
	case 2:															//случайный ввод
		for (int i = 0; i < n; i++)
		{
			massive2[i] = rand() % 100;
			printf("%d number of massive		%d\n", i + 1, massive2[i]);
		}
		break;
	}
	int flag = 0;
	int min=999;
	for (int i = 0; i < n; i++) //пробег по 1 массиву
	{    
		for (int j = 0; j < n; j++) //пробег по 2 массиву
		{
			if (massive1[i] == massive2[j]) // сравнение значений
				flag=1;
		}
		if (flag == 0 && massive1[i] < min) //присваивание минимального значения
		{
			min = massive1[i];
		}
		else
			flag = 0;
	}
	printf("the minimal element is %d", min);
}