#include <locale.h>
#include <iostream>
#include <fstream>

using namespace std;

int main() {
	setlocale(LC_ALL, "Russian");

	int n;
	cout << "Введите размер массива: "; cin >> n;
	int* X = new int[n];

	for (int i = 0; i < n; i++) {
		cout << "Введите значение под индексом " << i << ": "; cin >> X[i];
	}
	int ind_new_arr = 0;
	int fin_ind_new_arr = n - 1;
	int* Y = new int[n];
	for (int i = 0; i < n; i++) {
		if (X[i] % 2 == 0) {
			Y[ind_new_arr] = X[i];
			ind_new_arr++;
		}
		else
		{
			Y[fin_ind_new_arr] = X[i];
			fin_ind_new_arr--;
		}
	}
	ofstream outp;
	outp.open("out_file.txt");
	if (!outp) {
		cout << "Не удалось открыть файл.";
		return 1;
	}

	for (int i = 0; i < n; i++) {
		outp << Y[i] << " ";
	}
	outp.close();
}