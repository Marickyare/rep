#include <locale.h>
#include <iostream>
#include <math.h>
using namespace std;



int main() {
	setlocale(LC_ALL, "Russian");
	int R;
	int ind1 = 0;
	int	ind2 = 0;
	const int N = 10;
	int arr[N];
	cout << "Введите число R, на которое будет ориентироваться: "; cin >> R;		//ввод числа R
	
	
	for (int i = 0; i < N; i++) {													//заполнение массива вручную.
		cout << "Введите " << i << " элемент массива: "; cin >> arr[i];
	}

	int min_c = fabs(R - (arr[0] + arr[1]));


	for (int i = 0; i < N; i++) {
		for (int j = i + 1; j < N; j++) {

				if (fabs(R - (arr[i] + arr[j])) <= min_c) {
					ind1 = i;
					ind2 = j;
					min_c = fabs(R - (arr[i] + arr[j]));
			}
		}
	}
	cout <<"Инддексы элементов массива, сумма которых более близка кведённому числу R: "<< ind1 << ", " << ind2;
}