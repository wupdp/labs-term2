#include <stdio.h>
int main()
{
	{
		float l, V, S;
		printf("enter the length of the cube\n");
		scanf_s("%f", &l); //ввод длины куба
		if (l < 0)
			printf("number is negative\n");
		else
		{
			V = l * l * l; //объем
			S = 4 * l * l; //площадь
			printf("the Volume of the cube is %f, the Square of the cube is %f\n", V, S);
		}
	}
	{
		float x, y;
		printf("enter x and y\n");
		scanf_s("%f %f", &x, &y);
		if (x * x + y * y == 1)
			printf("you can draw a circle through the points\n");
		else printf("you can't draw a circle through the points\n");

	
	}
	{
		float a, b, c; 
		int i;
		i = 0;
		printf("enter a b c\n");
		scanf_s("%f %f %f", &a, &b, &c);
		if (a > 0)
			i++;
		if (b > 0)
			i++;
		if (c > 0)
			i++;
		printf("positive numbers:%u\n", i);
	}
	{
		int month;
		printf("enter the number of the month\n");
		scanf_s("%u", &month);

		if (month == 1|| month == 2|| month == 12)
			printf("winter");
		else
		if (month == 3 || month == 4|| month == 5)
			printf("spring");
		else
		if (month == 8|| month == 6|| month == 7)
			printf("summer");
		else
		if (month == 9 || month == 10 || month == 11)
			printf("autumn");
		else
			printf("its not the number of the month");
	}
	return 0;
}
