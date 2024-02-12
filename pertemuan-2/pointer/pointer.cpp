#include <iostream>
using namespace std;

int main()
{
    int var1 = 3;
    int var2 = 24;
    int var3 = 17;
    int* ptr= &var1;

    cout << &var1 << endl;
    cout << &var2 << endl;
    cout << &var3 << endl;
    cout << ptr << endl;

    return 0;
}