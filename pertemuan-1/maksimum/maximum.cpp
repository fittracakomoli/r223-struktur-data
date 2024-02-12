#include <iostream>
using namespace std;

int main()
{

    int n;
    cout << "Masukkan panjang array : ";
    cin>>n;
    int arr[n];
    int max = 0;

    for(int i = 0; i<n; i++) {
        cin>>arr[i];

        if(arr[i] > max) {
            max = arr[i];
        }
    }

    cout<< "nilai maksimum : " <<max;

    return 0;
}