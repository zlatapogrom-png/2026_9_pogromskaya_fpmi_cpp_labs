#include <iostream>

int main() {
	setlocale(LC_ALL, "Russian");
	int n;
	std::cout << "¬ведите количество нечетных чисел:\n";
	std::cin >> n;
	std::cout << n * n;
	return 0;
}