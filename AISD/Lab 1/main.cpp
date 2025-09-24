#include <iostream>

void hanou(int n, int i, int k) {
	if(n == 1){
		std::cout << "ƒиск 1  перемещен из " << i << " в " << k << std::endl;
	}
	else {
		int temp = 6 - i - k;
		hanou(n - 1, i, temp);
		std::cout << "ƒиск " << n << " перемещен из " << i << " в " << k << std::endl;
		hanou(n - 1, temp, k);
	}
}
void main() {
	setlocale(LC_ALL, "rus");
	int n, k; 
	std::cout << " ¬ведите n: ";
	std::cin >> n;
	std::cout << " ¬ведите k: ";
	std::cin >> k;
	if (n < 1 || k < 1) {
		std::cout << "¬ведите не отрицательные значени€";
	};
	if (k > 3) {
		std::cout << "k не может быть больше трех";
	}
	hanou(n, 1, k);
}	
