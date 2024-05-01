#include <fstream>
#include <iostream>
#include <math.h>
#include <locale.h>

using namespace std;

int main() {
	setlocale(LC_ALL, "Russian");
	ifstream f_input;
	ofstream f_output;
	f_input.open("startgame.txt");
	int num, personal_num, coun;
	if (f_input.fail()) {
		cout << "Не удалось открыть файл.";
		return 1;
	}
	f_input >> num;
	f_input.close();
	coun = 0;
	f_output.open("endgame.txt");
	do{
		cout << "Введите ваше число:"; 
		cin >> personal_num;
		if (personal_num > num) {
			cout << "Слишком большое. Введите число меньше."<<endl;

		}
		else if (personal_num < num) {
			cout << "Слишком маленькое. Введите число больше."<<endl;
		}
		coun++;
		f_output << "Введено число: " << personal_num<<endl;
	} while (num != personal_num);
	cout << "Поздравляем, число совпало!";
	f_output << "Количество введённых числен: " << coun;
	f_output.close();
}