#include <iostream>
#include <math.h>
#include <locale.h>

int main()
{
	setlocale(LC_ALL, "Russian");
	float x, y;

	printf("Введите координату x: "); scanf_s("%f", &x);
	printf("Введите координату y: "); scanf_s("%f", &y);

	if ((sqrt(x) + sqrt(y)) <= 2 and (sqrt(x) + sqrt(y)) >= 1)
	{
		if (x > 0)
		{
			printf("Координаты подходят.");
		}
		else
		{
			printf("Координаты не подходят, введите пложительный x.");
		}
	}
	else
	{
		printf("Координаты не подходят, введите дргие.");
	}
	return 0;
}
