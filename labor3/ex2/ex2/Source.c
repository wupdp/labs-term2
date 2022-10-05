#include <stdio.h>
#include <stdlib.h>
int main()
{
	int massive[100];
	int n;
	do
	{
		printf("enter the number of elements(<100)\n");
		scanf_s("%d", &n);
		if (n < 1 || n>100)
		{
			printf("error\n");
			n = 0;
		}
	} while (n == 0);
	printf("enter 1 to enter the array elements yourself\n");  //выбор пользователя
	printf("enter 2 to randomly enter array elements\n");
	int x;
	scanf_s("%d", &x);
	switch (x)
	{
	case 1:
		for (int i = 0; i < n; i++)							//ввод пользователем
		{
			printf("enter %d number of massive		", i + 1);
			scanf_s("%4d", &massive[i]);
		}
		break;
	case 2:															//случайный ввод
		for (int i = 0; i < n; i++)
		{
			massive[i] = rand() % 100;
			printf("%d number of massive		%d\n", i + 1, massive[i]);
		}
		break;
	default:															//неправльный ввод
		printf("incorrect enter\n");
		return 0;
	}
	for (int i = n-1; i >= 0; i--)
	{
		if (massive[i] % 2 == 0&&massive[i]!=0)
		{
			n++;
			for (int j = n-1; j>i;j--)
			{
				massive[j] = massive[j - 1];
			}
			massive[i + 1] = 0;
		}
	}
	for (int i = 0; i < n; i++)
	{
		printf("%4d", massive[i]);
	}
	return 0;
}