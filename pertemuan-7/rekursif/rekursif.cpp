#include <iostream>
using namespace std;

int facto(int x){
    if (x==1){
        return 1;
    } else {
        return x*facto(x-1);
    }
}

int main()
{
    int angka;
    cout << "Masukkan angka: ";
    cin >> angka;

    cout << "Faktorial dari " << angka << " adalah: " << facto(angka) << endl;
}