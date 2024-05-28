#include <iostream>
#include <math.h>
#include <locale>
#include <fstream>

int type_of_the_triangle(int* a, int* b, int* c) {
	if (((*a) == (*b)) && ((*b) == (*c))) {				//равносторонний треуг.
		return 2;
	}

	if (pow((*c), 2) == (pow((*a), 2) * pow((*b), 2)) || pow((*a), 2) + pow((*c), 2) == pow((*b), 2) || pow((*b), 2) + pow((*c), 2) == pow((*a), 2)) {	//прямоугольный треугольник
		return 1;
	}

	if ((*a = (*b) && b != c) || (*a = (*c) && c != b) || (*b = (*c) && c != a)) {		//р/б треуг.
		return 3;
	}

	if ((*a) != (*b) && (*b) != (*c) && (*a) != (*c)) {					//раззносторонний треуг.
		return 4;
	}

	else {										//треугольника не существует
		return 5;
	}
}



int main() {
	setlocale(LC_ALL, "Russian");
	int a, b, c;
	int ct = 0;
	int dimensions, result;
	std::ifstream inp;

	inp.open("lenght.txt");				//открытие файла

	if (!inp) {							//проверка на ошибку открытия
		printf("Не удалось открыть файл.");
	}
	while (!inp.eof()) {
		inp >> dimensions;
		a = dimensions % 10;
		b = (dimensions / 10) % 10;
		c = (dimensions / 100) % 10;

		result = type_of_the_triangle(&a, &b, &c);
		ct++;

		if (result == 1) {
			printf("%i треугольник со стороными (%i, %i, %i) является прямоугольным.\n", ct, a, b, c);
		}
		if (result == 2) {
			printf("%i треугольник со стороными (%i, %i, %i) является равносторонним.\n", ct, a, b, c);
		}
		if (result == 3) {
			printf("%i треугольник со стороными (%i, %i, %i) является равнобедренным.\n", ct, a, b, c);
		}
		if (result == 4) {
			printf("%i треугольник со стороными (%i, %i, %i) является разносторонним.\n", ct, a, b, c);
		}
		if (result == 5) {
			printf("%i треугольник со стороными (%i, %i, %i) не существует.\n", ct, a, b, c);
		}
	}
	inp.close();
}
