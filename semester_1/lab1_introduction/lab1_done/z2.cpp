#include <iostream>

int main() {
	setlocale(LC_ALL, ".1251");
	int n;
	std::cout << "¬ведите количество нечетных чисел:\n";
	std::cin >> n;
	std::cout << n * n;
	return 0;
}