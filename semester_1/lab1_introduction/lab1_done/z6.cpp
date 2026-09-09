#include <iostream>

int main() {
	setlocale(LC_ALL, ".1251");
	int a, b, d;
	std::cout << "Введите границы отрезка и разность прогресии:\n";
	std::cin >> a >> b >> d;
	std::cout << "Числа на данном отрезке, кратные 3:\n";
	for (a; a <= b; a += d) {
		if (a % 3 == 0) {
			std::cout << a << " ";
		}
	}
}