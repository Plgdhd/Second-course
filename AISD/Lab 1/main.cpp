#include <iostream>

void hanou(int n, int i, int k) {
	if(n == 1){
		std::cout << "���� 1  ��������� �� " << i << " � " << k << std::endl;
	}
	else {
		int temp = 6 - i - k;
		hanou(n - 1, i, temp);
		std::cout << "���� " << n << " ��������� �� " << i << " � " << k << std::endl;
		hanou(n - 1, temp, k);
	}
}
void main() {
	setlocale(LC_ALL, "rus");
	int n, k; 
	std::cout << " ������� n: ";
	std::cin >> n;
	std::cout << " ������� k: ";
	std::cin >> k;
	if (n < 1 || k < 1) {
		std::cout << "������� �� ������������� ��������";
	};
	if (k > 3) {
		std::cout << "k �� ����� ���� ������ ����";
	}
	hanou(n, 1, k);
}	
