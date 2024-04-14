#include <iostream>
using namespace std;

int hitung(int x){
    if(x<=2){
        return 1;
    } else {
        return hitung(x-1)+hitung(x-2);
    }
}

int main()
{
    cout << hitung(3) << endl;
    cout << hitung(5) << endl;
    cout << hitung(8) << endl;
}