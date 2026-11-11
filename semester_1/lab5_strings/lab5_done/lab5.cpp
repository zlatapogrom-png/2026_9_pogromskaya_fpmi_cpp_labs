#include <iostream>
#include <string>

bool isValid(std::string& s) {
	if (s.length() != 19) {
		return false;
	}
	if (s[0] != '+' || s[1] != '3' || s[2] != '7' || s[3] != '5' || s[4] != ' ') {
		return false;
	}
	if (s[5] != '(' || s[8] != ')' || s[9] != ' ') {
		return false;
	}
	if (s[13] != '-' || s[16] != '-') {
		return false;
	}
	std::string code = s.substr(6, 2);
	if ((code != "25") && (code != "29") && (code != "33") && (code != "44")) {
		return false;
	}
	int digitIndices[] = { 10, 11, 12, 14, 15, 17, 18 };
	for (int idx : digitIndices) {
		if (!std::isdigit(s[idx])) {
			return false;
		}
	}

	return true;
}

int main() {
	int attempts = 5;
	std::string input;

	while (attempts > 0) {
		std::cout << "enter phone number in format +375 (XX) XXX-XX-XX: ";
		if (!std::getline(std::cin, input)) {
			break;
		}
		if (isValid(input)) {
			int sum = 0;
			for (char c : input) {
				if (std::isdigit(c)) {
					sum += (c - '0');
				}
			}
			std::cout << "sum of digits in the number: " << sum << '\n';
			return 0;
		}
		else {
			attempts--;
			std::cout << "invalid format! please, try again. attempts left: " << attempts << '\n';
		}
	}

	std::cout << "error: you have exhausted all 5 attempts! program terminated\n";

	return 0;
}