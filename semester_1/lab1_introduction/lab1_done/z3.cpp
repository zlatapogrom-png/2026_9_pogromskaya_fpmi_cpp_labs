#include <iostream>

int main() {
	setlocale(LC_ALL, ".1251");
	int n, n1, n2, n3, n4;
	std::cout << "Введите четырехзначное натуральное число:\n";
	std::cin >> n;
	n1 = n / 1000;
	n2 = n / 100 % 10;
	n3 = n / 10 % 10;
	n4 = n % 10;
	if (n1 == n4 && n2 == n3) {
		std::cout << "Заданное число является палиндромом\n";
	}
	else {
		std::cout << "Заданное число не является палиндромом\n";
	}
	return 0;
}