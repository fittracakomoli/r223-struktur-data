#include <iostream>
#include <stack>

using namespace std;

// Fungsi konversi ke biner
string decimalToBinary(int decimal) {
    stack<int> binaryStack;

    while (decimal > 0) {
        binaryStack.push(decimal % 2);
        decimal /= 2;
    }

    string binaryResult = "";
    while (!binaryStack.empty()) {
        binaryResult += to_string(binaryStack.top());
        binaryStack.pop();
    }

    return binaryResult;
}

// Fungsi konversi ke octal
string decimalToOctal(int decimal) {
    stack<int> octalStack;

    while (decimal > 0) {
        octalStack.push(decimal % 8);
        decimal /= 8;
    }

    string octalResult = "";
    while (!octalStack.empty()) {
        octalResult += to_string(octalStack.top());
        octalStack.pop();
    }

    return octalResult;
}

// Fungsi konversi ke heksadesimal
string decimalToHexadecimal(int decimal) {
    stack<char> hexStack;
    const char hexChars[] = "0123456789ABCDEF";

    while (decimal > 0) {
        hexStack.push(hexChars[decimal % 16]);
        decimal /= 16;
    }

    string hexResult = "";
    while (!hexStack.empty()) {
        hexResult += hexStack.top();
        hexStack.pop();
    }

    return hexResult;
}

int main() {
    // Input bilangan desimal
    int decimalNumber;
    cout << "Masukkan bilangan desimal: ";
    cin >> decimalNumber;

    // Konversi ke biner, octal, dan heksadesimal
    string binaryResult = decimalToBinary(decimalNumber);
    string octalResult = decimalToOctal(decimalNumber);
    string hexResult = decimalToHexadecimal(decimalNumber);

    // Menampilkan hasil konversi
    cout << "Biner: " << binaryResult << endl;
    cout << "Octal: " << octalResult << endl;
    cout << "Heksadesimal: " << hexResult << endl;

    return 0;
}