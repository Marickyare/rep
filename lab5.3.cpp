#include <locale.h>
#include <fstream>
#include <iostream>

using namespace std;

float matrix_task(int a1, int a2, int a3, int a4) {
	return (((float)a1 + (float)a2 + (float)a3 + (float)a4) / 4);
}

int main() {
	setlocale(LC_ALL, "Russian");

	ifstream inp;
	inp.open("start_file.txt");

	if (!inp) {
		cout << "Не удалось открыть файл.";
		return 1;
	}

	const int k = 5;
	int arr[k][k];
	for (int i = 0; i < k; i++) {				//считываенние строк
		for (int j = 0; j < k; j++) {			//считывание столбцов
			inp >> arr[i][j];
		}
	}
	inp.close();

	int a1 = arr[0][1];
	int a2 = arr[1][2];
	int a3 = arr[2][3];
	int a4 = arr[3][4];

	cout << matrix_task(a1, a2, a3, a4) << endl;
}