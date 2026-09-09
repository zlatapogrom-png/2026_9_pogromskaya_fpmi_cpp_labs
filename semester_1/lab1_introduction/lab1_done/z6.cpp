#include <iostream>

int main() {
	setlocale(LC_ALL, "Russian");
	int a, b, d;
	std::cout << "¬ведите границы отрезка и разность прогресии:\n";
	std::cin >> a >> b >> d;
	std::cout << "„исла на данном отрезке, кратные 3:\n";
	for (a; a <= b; a += d) {
		if (a % 3 == 0) {
			std::cout << a << " ";
		}
	}
}