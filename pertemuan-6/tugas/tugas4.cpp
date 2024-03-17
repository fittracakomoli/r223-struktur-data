#include <iostream>
#include <stack>
#include <string>
#include <cctype>

// Fungsi untuk mengecek apakah sebuah karakter adalah operator
bool isOperator(char c) {
    return c == '+' || c == '-' || c == '*' || c == '/';
}

// Fungsi untuk mendapatkan prioritas operator
int precedence(char op) {
    if(op == '+' || op == '-') {
        return 1;
    } else if(op == '*' || op == '/') {
        return 2;
    }
    return 0;
}

// Fungsi untuk mengonversi ekspresi infix menjadi ekspresi postfix
std::string infixToPostfix(const std::string& infix) {
    std::string postfix;
    std::stack<char> operatorStack;

    for(char c : infix) {
        if(std::isalnum(c)) { // Jika karakter adalah operand (angka)
            postfix += c;
        } else if(c == '(') { // Jika karakter adalah kurung buka
            operatorStack.push(c);
        } else if(c == ')') { // Jika karakter adalah kurung tutup
            while(!operatorStack.empty() && operatorStack.top() != '(') {
                postfix += operatorStack.top();
                operatorStack.pop();
            }
            operatorStack.pop(); // Hapus kurung buka dari stack
        } else if(isOperator(c)) { // Jika karakter adalah operator
            while(!operatorStack.empty() && precedence(operatorStack.top()) >= precedence(c)) {
                postfix += operatorStack.top();
                operatorStack.pop();
            }
            operatorStack.push(c);
        }
    }

    // Menambahkan sisa operator yang tersisa di stack ke postfix
    while(!operatorStack.empty()) {
        postfix += operatorStack.top();
        operatorStack.pop();
    }

    return postfix;
}

// Fungsi untuk mengevaluasi ekspresi postfix dan mengembalikan hasilnya
int evaluatePostfix(const std::string& postfix) {
    std::stack<int> operandStack;

    for(char c : postfix) {
        if(std::isdigit(c)) { // Jika karakter adalah operand (angka)
            operandStack.push(c - '0'); // Konversi karakter angka ke integer
        } else if(isOperator(c)) { // Jika karakter adalah operator
            int operand2 = operandStack.top();
            operandStack.pop();
            int operand1 = operandStack.top();
            operandStack.pop();

            // Evaluasi operasi dan tambahkan hasilnya ke dalam stack
            switch(c) {
                case '+':
                    operandStack.push(operand1 + operand2);
                    break;
                case '-':
                    operandStack.push(operand1 - operand2);
                    break;
                case '*':
                    operandStack.push(operand1 * operand2);
                    break;
                case '/':
                    operandStack.push(operand1 / operand2);
                    break;
            }
        }
    }

    return operandStack.top(); // Hasil evaluasi
}

int main() {
    std::string infix;
    std::cout << "Masukkan ekspresi infix: ";
    std::getline(std::cin, infix);

    // Konversi infix ke postfix
    std::string postfix = infixToPostfix(infix);
    std::cout << "Ekspresi postfix: " << postfix << std::endl;

    // Evaluasi ekspresi postfix dan mencetak hasilnya
    int hasil = evaluatePostfix(postfix);
    std::cout << "Hasil: " << hasil << std::endl;

    return 0;
}
