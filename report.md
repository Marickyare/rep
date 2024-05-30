# Лабораторная работа №4
Лыткина Виктория Алексеевна, гр. 09.07.43з.

**Цель работы –** формирование навыка написания и использования функций при разработке программ на языке программирования С/С++.

**Постановка задачаи:**
1) Ознакомиться с понятиями функции, аргумента, прототипа;
2) Изучить основные правила описания, определения и вызова функций;
3) Ознакомиться с технологией передачи аргументов функции через
указатели;
4) Научиться выделять и реализовывать функции с целью исключения
дублирования программного кода в программе.

**Блок схемы алгоритмов.**
[Задание 1](img_4_lab/blockDiagram1.pdf). [Задание 2](img_4_lab/blockDiagram2.pdf). [Задание 3](img_4_lab/blockDiagram3.pdf).  

**Тексты программ.**

*Задание 1.*  
>﻿#include <fstream>  
#include <iostream>  
#include <locale>  
#include <math.h>  
using namespace std;  
int main()  
{  
    setlocale(LC_ALL, "Russian");  
    int summ_f(int x), mult_f(int x);  
    float average_f(float x);
    int summ, mult, present_value;  
    float average;  
    ifstream inp_stream;  
    inp_stream.open("start_file.txt");    
    if (inp_stream.fail()) {         
    printf("К сожалению, файл открыть не удалось"); }  
    while (!inp_stream.eof()) {               
        inp_stream >> present_value;  
        summ = summ_f(present_value);  
        mult = mult_f(present_value);  
        average = average_f(present_value);  
        printf("В числе %d сумма цифр = %d, произведение цифр = %d, среднее арифмметическое = %f\n", present_value, summ, mult, average);  
    }  
    inp_stream.close();      
}  
int summ_f(int x) {  
    int summ = 0;  
    while (x > 0) {  
        summ += x % 10;  
        x = x / 10;  
    }  
    return summ;  
}  
int mult_f(int x) {  
    int mult = 1;  
    while (x > 0) {  
        mult *= x % 10;  
        x = x / 10;  
    }  
    return mult;  
}  
float average_f(float x) {  
    float sum = summ_f(x);  
    float average =  sum / float(3);  
    return average;  
}

*Задание 2.*  
>﻿#define _CRT_SECURE_NO_WARNINGS  
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

*Задание 3.*  
>﻿#include <iostream>  
#include <math.h>  
#include <locale>  
#include <fstream>  
int type_of_the_triangle(int* a, int* b, int* c) {  
	if (((*a) == (*b)) && ((*b) == (*c))) {		
		return 2;  
	}  
	if (pow((*c), 2) == (pow((*a), 2) * pow((*b), 2)) || pow((*a), 2) + pow((*c), 2) == pow((*b), 2) || pow((*b), 2) + pow((*c), 2) == pow((*a), 2)) {	//прямоугольный треугольник  
		return 1;  
	}  
	if ((*a = (*b) && b != c) || (*a = (*c) && c != b) || (*b = (*c) && c != a)) {		
		return 3;  
	}  
	if ((*a) != (*b) && (*b) != (*c) && (*a) != (*c)) {		
		return 4;  
	}  
	else {									
		return 5;  
	}  
}  
int main() {  
	setlocale(LC_ALL, "Russian");  
	int a, b, c;  
	int ct = 0;  
	int dimensions, result;  
	std::ifstream inp;  
	inp.open("lenght.txt");				
	if (!inp) {							
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


**Скриншоты результатов работы программ.**

[Задание 1](img_4_lab/workres1.png). [Задание 2](img_4_lab/workres2.png). [Задание 3](img_4_lab/workres3.png).  

**Описание функций, используемых в лабораторной работе.**

**К отчёту приложить файлы проектов программ.**

**Вопросы и задания для защиты работы**

1) *Функция* - имонованная последовательность операций/других функций, к которой возможно обратиться из любой части кода. Разделение на функции необходимо в том случае, если функция (её логика) используется в разных частях кода. То есть, для вызова одной и той же функции несколько раз. В некоторых случаях функции используются для разгрузки кода.
2) Функция состоит из заголовка и тела. Заголовок включает в себя название, тип возвращаемых значений и параметры (могут быть пустыми). Тело включает алгоритм (инструкции).
3) Прототип функции - структура для предварительного описания функции. Прототипы используются в следующих случаях:
   - функция определена в другом файле;
   - функция определена после обращения к ней;
   - функция определена в библиотеке функций, которая подключается к
программе на этапе ее компоновки или выполнения.
4) Передача аргемунтом по значению при вызове функции происходит следующим образом: значения аргументов переписываются в параметры функции. Так как значение аргумента копируется в тело функции, то сам аргумент изменить в теле функции невозможно. Функция, в свою очередь, возвращает результат также по значению.
5) Аргументы функции необходимо передать через указатели потому что так функция сможет изменять значения переменных, определённых программой.
6)
7)
