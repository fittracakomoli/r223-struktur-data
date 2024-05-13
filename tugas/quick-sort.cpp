#include <iostream>
using namespace std;

void swap(int *a, int *b) {
  int t = *a;
  *a = *b;
  *b = t;
}

int pembanding(int array[], int low, int high) {

  int pivot = array[high];
  int i = (low - 1);

  for (int j = low; j < high; j++) {
    if (array[j] <= pivot) {
      i++;
      swap(&array[i], &array[j]);
    }
  }

  swap(&array[i + 1], &array[high]);

  return (i + 1);
}

void quickSort(int array[], int low, int high) {
  if (low < high) {
      
    int pe = pembanding(array, low, high);

    quickSort(array, low, pe - 1);

    quickSort(array, pe + 1, high);
  }
}

int main() {
    int t; 
    cout << "Masukkan jumlah data : ";
    cin >> t;
    int data[t];
    cout << "Masukkan data : ";
    for(int i = 0; i < t; i++){
        cin >> data[i];
    }
  int n = sizeof(data) / sizeof(data[0]);
  
  cout << "Data belum urut : " << endl;
  for(int i = 0; i < t; i++){
    cout << data[i] << " ";
  }
  cout << endl;

  quickSort(data, 0, n - 1);
  
  cout << "Data sudah urut : " << endl;
  for(int i = 0; i < t; i++){
    cout << data[i] << " ";
  }
  cout << sizeof(data[0]) << sizeof(data);
}