# Лабораторная работа №3
Лыткина Виктория Алексеевна, гр. 09.07.43з.

**Цель работы –** освоить принципы обмена данными с файлами средствами языков C и C++.

**Постановка задачаи:**
1) Извучить режимы работы функций открытия и закрытия файлов стандартной библиотеки языка C.
2) Научиться использовать функции форматного ввода и вывода данных fscanf() и fprintf().
3) Научиться реализовывать потоковое чтение и запись данных из файла средствами языка C++.

**Блок схемы алгоритмов.**
[Задание 1](img_3_lab/blockDiagram1.drawio.pdf). [Задание 2](img_3_lab/blockDiagram2.drawio.pdf).  
**Тексты программ.**  
*Задание 1.*  
>#include <iostream>  
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

*Задание 2.*  
>#include <iostream>  
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

**Скриншоты результатов работы программ.**

**Описание функций, используемых в лабораторной работе.**

**Файлы проктов программ.**

**Вопросы и задания для защиты работы:**
1) Открытие файла, чтение и запись данных, закрытие файла.  
2) Без закрытия файла он будет недоступен для других операций. Данные сохраняются только в момент закрытия.
3)
4) 
5) 
6)
7) 
