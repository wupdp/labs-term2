#include <stdio.h>
int Prime(int koren)
{
	for (int i = 2; i < koren; i++)
		if (koren % i == 0)
			return 0;
	return 1;

}

int main()
{
		double sum = 10000;
		int year = 0;
		for (; sum <= 20000; year++)
		{
			printf("year %d   sum %f\n", year, sum);
			sum = sum + sum * 0.03;
		}
		printf("the amount increased by 2 times in %d years\n", year);

		
	int num, a, b, c, koren = 10;
	
	
	for (; koren <=31; koren++)
	{
		if (Prime(koren) == 1)
		{
			num = koren * koren;
			a = num % 10;
			b = (num % 100 - a) / 10;
			c = (num - a - b) / 100;
			if (a > b && b > c)
				printf("num=%d\n", num);
		}
	}
	float A, B;
	printf("enter A and B (A>B>0)\n");
	scanf_s("%f%f", &A, &B);
	if (A < B || A <= 0 || B <= 0)
	{
		printf("error: condition A>B>0 not met ");
		return 0;
	}
	while (A >= B)
	{
		A = A - B;
	}
	printf("unoccupied part of the segment is %f\n", A);
}