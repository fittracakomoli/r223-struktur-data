#include <iostream>

// Fungsi rekursif untuk menentukan apakah suatu bilangan adalah bilangan prima
bool isPrime(int n, int i = 2) {
    if (n <= 2) {
        return (n == 2) ? true : false;
    }
    if (n % i == 0) {
        return false;
    }
    if (i * i > n) {
        return true;
    }
    return isPrime(n, i + 1);
}

int main() {
    int num;
    std::cout << "Masukkan sebuah bilangan: ";
    std::cin >> num;

    if (isPrime(num)) {
        std::cout << num << " adalah bilangan prima.\n";
    } else {
        std::cout << num << " bukan bilangan prima.\n";
    }

    return 0;
}
