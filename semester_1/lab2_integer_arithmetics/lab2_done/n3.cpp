#include <iostream>

int main() {
	long long n;
	std::cout << "enter a natural number: \n";

	if (!(std::cin >> n)) {
		std::cout << "you must input an integer number!\n";
		return 1;
	}

	if (n <= 0) {
		std::cout << "you must input a natural number!\n";
		return 1;
	}

	long long number = n;
	int min_digit = 9;
	int d;
	while (number > 0) {
		d = number % 10;
		if (d != 0 && d < min_digit) {
			min_digit = d;
		}
		number /= 10;
	}

	std::cout << "result: " << min_digit << n << min_digit;

	return 0;
}