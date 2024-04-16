#include <iostream>
#include <math.h>
#include <locale.h>
using namespace std;

int main(){
	setlocale(LC_ALL, "Russian");
	float E, S, y;
	int n = 1;
	S = 0;
	printf("Введите значение E: \n"); 
	cin >> E;
	
	if (E >= (float(1)/float(3))) {
		printf("Введите меньшее значение.");
	}
	else {
		do {
			y = (n + 5) / (pow(2, n) + 2);
			S += y;
			n += 1;
		} while ((y > E) or ((y - (((n - 2) + 5) / (pow(2, (n - 2)) + 2))) >= E));
	}
	printf("%d", n-1);

	return 0;

}
