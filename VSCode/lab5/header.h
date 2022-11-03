#include <stdio.h>
#include <stdlib.h>

int switchInit()
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