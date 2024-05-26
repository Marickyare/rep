#define _CRT_SECURE_NO_WARNINGS
#include <math.h>
#include <stdlib.h>
#include <locale.h>
#include <iostream>;

using namespace std;

int area_of_a_triangle(int a, int b, int c) {
	int p = (a + b + c) / 2;
	int s = sqrt(p * (p - a) * (p - b) * (p - c));
	return s;
}

int main() {
	setlocale(LC_ALL, "Russian");

	FILE *f_input;
	int a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12;
	int res;
	f_input = fopen("text_file.txt", "r");
	if (f_input == NULL) {
		printf("Файл открыть не удалось.");
	}
	fscanf(f_input, "%d%d%d%d%d%d%d%d%d%d%d%d", &a1, &a2, &a3, &a4, &a5, &a6, &a7, &a8, &a9, &a10, &a11, &a12);
	fclose(f_input);

	res = area_of_a_triangle(a1, a2, a3) + area_of_a_triangle(a4, a5, a3) + area_of_a_triangle(a7, a5, a6) + area_of_a_triangle(a7, a8, a9) + area_of_a_triangle(a9, a10, a11) + area_of_a_triangle(a1, a12, a11);
	cout << "Площадь многоугольника в мм = " << res;
}