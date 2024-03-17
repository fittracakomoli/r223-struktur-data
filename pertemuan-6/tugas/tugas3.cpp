#include <iostream>
#include <stack>
#include <string>
#include <cctype>

// Fungsi untuk menghapus karakter non-alfanumerik dari sebuah string
std::string removeNonAlphanumeric(const std::string& str) {
    std::string result;
    for(char c : str) {
        if(std::isalnum(c)) {
            result += std::tolower(c); // Ubah ke huruf kecil
        }
    }
    return result;
}

// Fungsi untuk menentukan apakah sebuah string adalah palindrom atau bukan
bool isPalindrome(const std::string& str) {
    std::stack<char> charStack;
    std::string processedStr = removeNonAlphanumeric(str);

    // Memasukkan setengah karakter pertama ke dalam stack
    int halfLength = processedStr.length() / 2;
    for(int i = 0; i < halfLength; ++i) {
        charStack.push(processedStr[i]);
    }

    // Bandingkan setengah karakter kedua dengan karakter di stack
    int startIndex = halfLength + (processedStr.length() % 2); // Jika panjang string ganjil, mulai dari setelah karakter tengah
    for(int i = startIndex; i < processedStr.length(); ++i) {
        if(processedStr[i] != charStack.top()) {
            return false; // Bukan palindrom
        }
        charStack.pop();
    }

    return true; // Palindrom
}

int main() {
    std::string kalimat;
    std::cout << "Masukkan kalimat: ";
    std::getline(std::cin, kalimat);

    if(isPalindrome(kalimat)) {
        std::cout << "Kalimat tersebut adalah palindrom.\n";
    } else {
        std::cout << "Kalimat tersebut bukan palindrom.\n";
    }

    return 0;
}
