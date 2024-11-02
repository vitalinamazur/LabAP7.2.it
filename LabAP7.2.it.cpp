#include <iostream>
#include <iomanip>
#include <ctime>
using namespace std;

void Create(int** a, const int n, const int Low, const int High);
void Print(int** a, const int n);
void PlaceMaxOnDiagonal(int** a, const int n);
bool SearchMinEvenOnAntiDiagonal(int** a, const int n, int& minEven);

int main() {
    srand((unsigned)time(NULL));
    int n;
    int Low = -10;
    int High = 50;

    cout << "Enter the size of the matrix (n x n): ";
    cin >> n;

    int** a = new int* [n];
    for (int i = 0; i < n; i++)
        a[i] = new int[n];

    Create(a, n, Low, High);
    cout << "Original matrix:" << endl;
    Print(a, n);

    PlaceMaxOnDiagonal(a, n);
    cout << "Modified matrix with max elements on the main diagonal:" << endl;
    Print(a, n);

    int minEven;
    if (SearchMinEvenOnAntiDiagonal(a, n, minEven))
        cout << "The smallest even element on the anti-diagonal is: " << minEven << endl;
    else
        cout << "There are no even elements on the anti-diagonal." << endl;

    for (int i = 0; i < n; i++)
        delete[] a[i];
    delete[] a;

    return 0;
}

// Функція для створення матриці з випадковими значеннями
void Create(int** a, const int n, const int Low, const int High) {
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            a[i][j] = Low + rand() % (High - Low + 1);
}

// Функція для виведення матриці на екран
void Print(int** a, const int n) {
    cout << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            cout << setw(4) << a[i][j];
        cout << endl;
    }
    cout << endl;
}

// Функція для розміщення максимальних елементів кожного рядка на головній діагоналі
void PlaceMaxOnDiagonal(int** a, const int n) {
    for (int i = 0; i < n; i++) {
        int maxIndex = i;
        for (int j = 0; j < n; j++) {
            if (a[i][j] > a[i][maxIndex])
                maxIndex = j;
        }
        // Обмін місцями максимального елемента рядка з елементом на діагоналі
        swap(a[i][i], a[i][maxIndex]);
    }
}

// Функція для пошуку найменшого парного елемента на побічній діагоналі
bool SearchMinEvenOnAntiDiagonal(int** a, const int n, int& minEven) {
    bool found = false;
    for (int i = 0; i < n; i++) {
        int j = n - 1 - i; // Індекс побічної діагоналі
        if (a[i][j] % 2 == 0) {
            if (!found || a[i][j] < minEven) {
                minEven = a[i][j];
                found = true;
            }
        }
    }
    return found;
}
