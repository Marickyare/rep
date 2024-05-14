#include <fstream>
#include <iostream>
#include <locale>
#include <math.h>


using namespace std;



int main()
{

    setlocale(LC_ALL, "Russian");

    int summ_f(int x), mult_f(int x);
    float average_f(float x);
    int summ, mult, present_value;                              //объявление рабочих переменных
    float average;
    ifstream inp_stream;
    inp_stream.open("start_file.txt");                          //открытие файла

    if (inp_stream.fail()) {                                    //проверка открытия файла
    printf("К сожалению, файл открыть не удалось"); }

    while (!inp_stream.eof()) {                                 //вызов функций и работа с числами из файла
        inp_stream >> present_value;
        summ = summ_f(present_value);
        mult = mult_f(present_value);
        average = average_f(present_value);
        printf("В числе %d сумма цифр = %d, произведение цифр = %d, среднее арифмметическое = %f\n", present_value, summ, mult, average);
    }

    inp_stream.close();                                         //закрытие файла
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