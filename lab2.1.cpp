#include <iostream>
#include <math.h>
#include <locale.h>

using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");
    std::cout << "Hello World!\n";
    float a, b, F;


    cout << "Введите положительное значение a: "; cin >> a; //т.к. неветвл. алг., вводим усл. для польз. вручную
    cout << "Введите неотрицтельное значение b: "; cin >> b; //т.к. неветвл. алг., вводим усл. для польз. вручную
    float Tnumerator = 8.15 * pow(b, 3) * log(a);
    float Fdenominator = 24.38 * cos(b) * (exp(a) - pow(a, a));
    F = Tnumerator / Fdenominator;
    cout << "Значение выражения: " << F;
    return 0;
}