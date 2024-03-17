#include <iostream>
#include <stack>
#include <string>

using namespace std;

// Fungsi untuk membalikkan kalimat menggunakan stack
string balikKalimat(string kalimat) {
    stack<char> karakterStack;
    string kalimatTerbalik = "";

    // Memasukkan setiap karakter dari kalimat ke dalam stack
    for (char karakter : kalimat) {
        karakterStack.push(karakter);
    }

    // Mengeluarkan karakter dari stack dan menyusunnya kembali menjadi kalimat terbalik
    while (!karakterStack.empty()) {
        kalimatTerbalik += karakterStack.top();
        karakterStack.pop();
    }

    return kalimatTerbalik;
}

int main() {
    string kalimat;
    cout << "Masukkan kalimat: ";
    getline(cin, kalimat);

    string kalimatTerbalik = balikKalimat(kalimat);

    cout << "Hasil setelah dibalik: " << kalimatTerbalik << endl;

    return 0;
}
