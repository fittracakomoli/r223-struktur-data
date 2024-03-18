#include <iostream>

// Fungsi rekursif untuk menghasilkan deret Fibonacci
int fibonacci(int n) {
    if (n <= 1)
        return n;
    return fibonacci(n - 1) + fibonacci(n - 2);
}

int main() {
    int n;
    std::cout << "Masukkan jumlah elemen yang ingin Anda tampilkan: ";
    std::cin >> n;

    std::cout << "Deret Fibonacci hingga " << n << " elemen:\n";
    for (int i = 0; i < n; ++i) {
        std::cout << fibonacci(i) << " ";
    }
    return 0;
}