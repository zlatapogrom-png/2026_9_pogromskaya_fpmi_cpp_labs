#include <iostream>
#include <cmath>
#include <random>

double** CreateMatrix(int n, int m) {
    double** matrix = new double* [n];
    for (int i = 0; i < n; ++i) {
        matrix[i] = new double[m];
    }
    return matrix;
}

void FreeMatrix(double** matrix, int n) {
    for (int i = 0; i < n; ++i) {
        delete[] matrix[i];
    }
    delete[] matrix;
}

int InputDimension(const char* name) {
    int val;
    std::cout << "enter the number of " << name << ": ";
    if (!(std::cin >> val) || val <= 0) {
        std::cout << "you must input a natural number greater than 0!\n";
        return -1;
    }
    return val;
}

void InputMatrixFromKeyboard(double** matrix, int n, int m) {
    std::cout << "input matrix elements (" << n << "x" << m << "):\n";
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            std::cout << "element [" << i << "][" << j << "]: ";
            std::cin >> matrix[i][j];
        }
    }
}

void FillRandom(double** matrix, int n, int m, double a, double b) {
    std::mt19937 gen(45218965);
    std::uniform_real_distribution<double> dist(a, b);

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            matrix[i][j] = dist(gen);
        }
    }
    std::cout << "the matrix has been successfully populated with random numbers from the interval [" << a << ", " << b << "]\n";
}

bool Choice(double** matrix, int n, int m) {
    std::cout << "choose the method for filling the array:\n";
    std::cout << "1 - manually from the keyboard;\n";
    std::cout << "2 - random;\n";
    std::cout << "your choice: ";
    int choice;
    std::cin >> choice;

    if (choice == 1) {
        InputMatrixFromKeyboard(matrix, n, m);
        return true;
    }
    else if (choice == 2) {
        double a, b;
        std::cout << "enter the interval boundaries a and b: ";
        std::cin >> a >> b;
        FillRandom(matrix, n, m, a, b);
        return true;
    }
    else {
        std::cout << "you must input 1 or 2!\n";
        return false;
    }
}

void PrintMatrix(double** matrix, int n, int m, const char* name) {
    std::cout << "matrix " << name << " (" << n << "x" << m << "):\n";
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            std::cout << matrix[i][j] << "\t";
        }
        std::cout << '\n';
    }
}

double GetNeighborhoodSum(double** A, int n, int m, int r, int c) {
    double sum = 0.0;

    for (int i = r - 1; i <= r + 1; ++i) {
        for (int j = c - 1; j <= c + 1; ++j) {
            if (i >= 0 && i < n && j >= 0 && j < m) {
                if (!(i == r && j == c)) {
                    sum += A[i][j];
                }
            }
        }
    }
    return sum;
}

double** BuildMatrixB(double** A, int n, int m) {
    double** B = CreateMatrix(n, m);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            B[i][j] = GetNeighborhoodSum(A, n, m, i, j);
        }
    }
    return B;
}

int main() {
    int n = InputDimension("rows n");
    if (n == -1) return 0;

    int m = InputDimension("columns m");
    if (m == -1) return 0;

    double** A = CreateMatrix(n, m);

    if (!Choice(A, n, m)) {
        FreeMatrix(A, n);
        return 0;
    }

    PrintMatrix(A, n, m, "A");

    double** B = BuildMatrixB(A, n, m);
    PrintMatrix(B, n, m, "B");

    FreeMatrix(A, n);
    FreeMatrix(B, n);

    return 0;
}