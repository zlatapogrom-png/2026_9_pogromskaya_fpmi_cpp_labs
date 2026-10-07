#include <iostream>
#include <cmath>
#include <random>

int InputNumber() {
    int n;
    std::cout << "enter the number of array elements n: ";
    if (!(std::cin >> n) || n <= 0) {
        std::cout << "you must input a natural number greater than 0!\n";
        return -1;
    }
    return n;
}

void InputArray(double* arr, int n) {
    std::cout << "input " << n << " array elements: \n";
    for (int i = 0; i < n; ++i) {
        std::cout << "element [" << i << "]: ";
        std::cin >> arr[i];
    }
}

void FillRandom(double* arr, int n, double a, double b) {
    std::mt19937 gen(45218965);
    std::uniform_real_distribution<double> dist(a, b);

    for (int i = 0; i < n; ++i) {
        arr[i] = dist(gen);
    }
    std::cout << "the array has been successfully populated with random numbers from the interval [" << a << ", " << b << "]\n";
}

bool Choice(double* arr, int n) {
    std::cout << "choose the method for filling the array:\n";
    std::cout << "1 - manually from the keyboard;\n";
    std::cout << "2 - random;\n";
    std::cout << "your choice: ";
    int choice;
    std::cin >> choice;

    if (choice == 1) {
        InputArray(arr, n);
        return true;
    }
    else if (choice == 2) {
        double a, b;
        std::cout << "enter the interval boundaries a and b: ";
        std::cin >> a >> b;
        FillRandom(arr, n, a, b);
        return true;
    }
    else {
        std::cout << "you must input 1 or 2!\n";
        return false;
    }
}

int FindBestDividingIndex(const double* arr, int n) {
    if (n < 3) {
        return -1;
    }

    double total_sum = 0.0;
    for (int i = 0; i < n; ++i) {
        total_sum += arr[i];
    }

    int best_index = -1;
    double min_diff = -1.0;
    double left_sum = 0.0;
    double right_sum;
    double current_diff;

    for (int i = 0; i < n; ++i) {
        if (i > 0 && i < n - 1) {
            right_sum = total_sum - left_sum - arr[i];
            current_diff = std::abs(left_sum - right_sum);

            if (min_diff < 0.0 || current_diff < min_diff) {
                min_diff = current_diff;
                best_index = i;
            }
        }
        left_sum += arr[i];
    }

    return best_index;
}

void PrintResult(const double* arr, int n, int index) {
    if (index == -1) {
        std::cout << "the array must contain at least 3 elements!\n";
        return;
    }

    std::cout << "number of the found element: " << index + 1 << '\n';
}

int main() {
    int n = InputNumber();
    if (n == -1) return 0;

    double* arr = new double[n];

    if (!Choice(arr, n)) {
        delete[] arr;
        return 0;
    }

    int target_index = FindBestDividingIndex(arr, n);
    PrintResult(arr, n, target_index);

    delete[] arr;

    return 0;
}