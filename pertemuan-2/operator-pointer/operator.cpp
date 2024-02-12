#include <iostream>
using namespace std;

int main()
{
    int *ptr, num = 0;
    cout << &num << endl;
    ptr = &num;
    *ptr = 100;
    cout << num << endl;

    (*ptr)++;
    cout << num << endl;

    (*ptr)*=2;
    cout << num << endl;
}