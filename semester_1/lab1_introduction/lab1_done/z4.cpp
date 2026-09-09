#include <iostream>

int main() {
	setlocale(LC_ALL, "Russian");
	int n, n1, n2, n3, n4, n5, n6;
	std::cout << "Введите шестизначное натуральное число:\n";
	std::cin >> n;
	n1 = n / 100000;
	n2 = n / 10000 % 10;
	n3 = n / 1000 % 10;
	n4 = n / 100 % 10;
	n5 = n / 10 % 10;
	n6 = n % 10;
	if (n1 + n2 + n3 == n4 + n5 + n6) {
		std::cout << "Число является счастливым\n";
	}
	else {
		std::cout << "Число не является счастливым\n";
	}
	return 0;
}