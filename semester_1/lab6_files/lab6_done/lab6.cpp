#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

bool isValid(const std::string& s) {
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
    std::ifstream inputFile("input.txt");
    if (!inputFile.is_open()) {
        std::cout << "error: could not open input.txt\n";
        return 1;
    }

    std::ofstream outputFile("output.txt");
    if (!outputFile.is_open()) {
        std::cout << "error: could not open output.txt\n";
        return 1;
    }

    std::string line;
    while (std::getline(inputFile, line)) {
        std::stringstream ss(line);
        std::string number;
        std::string validLineResult = "";
        int validCount = 0;

        while (std::getline(ss, number, ';')) {
            if (isValid(number)) {
                if (validCount > 0) {
                    validLineResult += "; ";
                }
                validLineResult += number;
                validCount++;
            }
        }

        if (validCount > 0) {
            outputFile << validLineResult << "\n";
        }
        else {
            outputFile << "no valid numbers\n";
        }
    }

    inputFile.close();
    outputFile.close();

    std::cout << "processing complete. check output.txt\n";

    return 0;
}