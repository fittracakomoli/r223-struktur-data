#include <iostream>
using namespace std;

int main()
{
    int i[10], *iPtr;
    double f[10], *fPtr;
    
    iPtr = i;
    fPtr = f;

    for(int x = 0; x<10; x++) {
        cout << iPtr+x << " " << fPtr+x << endl;
    }

    return 0;
}