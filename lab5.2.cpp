#include <iostream>
#include <math.h>#include <locale.h>

using namespace std;

int logic_arr(int *arr, int size) {

	for (int i = 0; i < size; i++) {
		for (int j = i + 1; j < size; j++) {
			for (int k = 1; k < size; k++) {
				if ((arr[i] == arr[j]) || (arr[i] == k)) {
					int c = arr[i];
					return i;
				}
			}
		}
	}
	return int ( - 1);
}

int main() {
	setlocale(LC_ALL, "Russian");

	const int N = 10;
	int arr[N];

	for (int i = 0; i < N; i++) {													//заполнение массива вручную.
		cout << "Введите " << i << " элемент массива: "; cin >> arr[i];
	}

	cout << "Значение и номер элемента: " << logic_arr(arr, N);
}