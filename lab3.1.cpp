#include <iostream>
#include <math.h>
#include <locale.h>

using namespace std;

int main() {
	setlocale(LC_ALL, "Russian");

	FILE* f_input, * f_output;
	int res_from_file, sum, max, quan, inp;
	f_input = fopen("predel.txt", "r");			//открытие первого файла для чтения

	if (f_input == 0) {							//проверка на правильность открытия файла
		printf("Не удалось открыть файл");
		return 1;
	}
	fscanf(f_input, "%d", &res_from_file);		//закрытие первого файла

	fclose(f_input);

	quan = 0;
	sum = 0;
	max = 0;
		while (sum < res_from_file) {
			printf("Введите число :");
			scanf("%d", &inp);
			if (inp % 2 == 0) {
				sum += inp;
			}

			if (inp > max) {
					max = inp;
			}
			
			quan += 1;
	}
	f_output = fopen("kolmax.txt", "w");		//открытие второго файла для записи
	
	if (f_output == 0) {						//проверка на правильность открытия файла
	printf("Не удалось открыть файл");
	return 1;
	}

	fprintf(f_output, "Количество введённых значений: %d\nМаксимальное число: %d", quan, max);		
	fclose(f_output);
}