#include <iostream>

int main() {
    setlocale(LC_ALL, ".1251");
    int n;
    std::cout << "Введите количество чисел Фибоначчи:\n";
    std::cin >> n;
    long long f0 = 0; 
    long long f1 = 1;
    if (n == 1) {
        std::cout << f0 << '\n';
    }
    std::cout << f0 << ' ' << f1;
    for (int i = 2; i < n; i++) {
        long long f = f0 + f1;
        std::cout << ' ' << f;
        f0 = f1;
        f1 = f;
    }

    std::cout << '\n';

    return 0;
}