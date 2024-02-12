#include <iostream>
using namespace std;

int main()
{

    int n;
    cout << "Masukkan panjang array : ";
    cin>>n;
    int arr[n];
    
    for(int i = 0; i<n; i++) {
        cin>>arr[i];

        if(arr[i] % 2 == 1) {
            cout << arr[i] << " ";
        }
    }

    return 0;
}