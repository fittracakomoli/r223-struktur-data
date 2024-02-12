#include <iostream>
using namespace std;

int main() 
{
    char a;
    char * b;
    char ** c;
    a = 'z';
    b = &a;
    c = &b;

    cout << a << endl;
    cout << *b << endl;
    cout << *c << endl;

    return 0;
}