#include <iostream>
#include <stack>
#include <string>

using namespace std;

// Fungsi untuk mengkonversi bilangan desimal ke biner, oktal, atau heksadesimal
void konversi(int bilangan, int basis) {
    stack<int> s;
    int sisa;

    // Melakukan konversi bilangan ke basis yang diinginkan
    while (bilangan > 0) {
        sisa = bilangan % basis;
        s.push(sisa);
        bilangan /= basis;
    }

    // Menampilkan hasil konversi dari stack
    cout << "Konversi ke basis " << basis << ": ";
    while (!s.empty()) {
        int digit = s.top();
        s.pop();
        if (basis == 16) {
            // Konversi digit ke heksadesimal jika basis adalah 16
            if (digit < 10)
                cout << digit;
            else
                cout << (char)('A' + digit - 10);
        } else {
            cout << digit;
        }
    }
    cout << endl;
}

int main() {
    int bilangan;

    // Meminta input dari pengguna
    cout << "Masukkan bilangan desimal: ";
    cin >> bilangan;

    // Memanggil fungsi konversi untuk masing-masing basis
    konversi(bilangan, 2);  // Konversi ke biner
    konversi(bilangan, 8);  // Konversi ke oktal
    konversi(bilangan, 16); // Konversi ke heksadesimal

    return 0;
}
