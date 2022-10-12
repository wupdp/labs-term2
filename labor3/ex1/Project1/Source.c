#include <stdio.h>
#include <stdlib.h>
int main()
{
	int massive[100];
	int num, proiz, sum;
	proiz = 1;
	sum = 0;
	//ввод количества элементов
	printf("enter the number of elements(<100)\n");
	while (scanf_s("%d", &num) != 1 || num < 1 || num >100||getchar()!='\n')		//проверка на ввод
	{
		printf("error\n");
		rewind(stdin);
	}
	printf("enter 1 to enter the array elements yourself\n");  //выбор пользователя
	printf("enter 2 to randomly enter array elements\n");
	int x;
	scanf_s("%d", &x);
	switch (x)
	{
	case 1:
		for (int i = 0; i < num; i++)							//ввод пользователем
		{
			printf("enter %d number of massive		", i + 1);
			while (scanf_s("%4d", &massive[i]) != 1 || getchar() != '\n')		//проверка на ввод
			{
				printf("error\n");
				rewind(stdin);
			}
		}
		break;
	case 2:															//случайный ввод
		for (int i = 0; i < num; i++)
		{
			massive[i] = rand() % 100;
			printf("%d number of massive		%d\n", i + 1, massive[i]);
		}
		break;
	default:															//неправльный ввод
		printf("incorrect enter\n");
		return 0;
	}		
	for (int i = 0; i < num;i=i+2)									//поиск произведения
	{
		proiz = proiz * massive[i];
	}
	printf("composition is %d\n", proiz);
	int istart, iend,flag;
	flag = 0;
	for (int i = 0; i < num; i++)									//проверка на кол-во нулей
	{
		if (massive[i] == 0)
			flag++;
	}
	if (flag < 2)
		return 0;
	for (int i = 0; i < num;i++)									//поиск суммы
	{
		if (massive[i] == 0)
		{
			istart = i;
			break;
		}	
	}
	for (int i = num-1; i >=0;i--)
	{ 
		if (massive[i] == 0)
		{
			iend = i;
			break;
		}
	}
	for (int i = istart; i <= iend; i++)
	{
		sum = sum + massive[i];
	}
	printf("sum=%d", sum);
	return 0;
}
