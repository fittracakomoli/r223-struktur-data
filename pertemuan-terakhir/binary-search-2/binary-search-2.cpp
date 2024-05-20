#include <stdio.h>
#include <stdlib.h>
#define MAX 10
int Data[MAX];

// Prosedur menukar data
void Tukar (int *a, int *b) {
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
} 

// Prosedur pengurutan metode Quick Sort
void QuickSort(int L, int R) {
    int i, j, x;
    x = Data[(L+R)/2];
    i = L;
    j = R;
    while (i <= j) {
        while(Data[i] < x) {
            i++;
        }

        while(Data[j] > x) {
            j--;
        }

        if(i <= j) {
            Tukar(&Data[i], &Data[j]);
            i++;
            j--;
        }
    }

    if(L < j) {
        QuickSort(L, j);
    }

    if(i < R) {
        QuickSort(i, R);
    }
}

// Fungsi pencarian biner
int BinarySearch(int x) {
    int L = 0, R = MAX-1, m;
    bool ketemu = false;
    while((L <= R) && (!ketemu)) {
        m = (L + R) / 2;
        if(Data[m] == x) {
            ketemu = true;
        } else if(x < Data[m]) {
            R = m - 1;
        } else {
            L = m + 1;
        }
    }

    if(ketemu) {
        return m;
    } else {
        return -1;
    }
} 

int main() {
    int i;

    //pembangkit bilangan random
    srand(0);

    //membangkitkan bilangan integer random
    printf("\nDATA : ");

    for (i = 0; i < MAX; i++) {
        Data[i] = rand()/1000+1;
        printf("%d ", Data[i]);
    }

    //mengurutkan data
    QuickSort(0, MAX-1);
    int Kunci;
    printf("\nKunci : ");
    scanf("%d", &Kunci);
    int ketemu = BinarySearch(Kunci);

    if(ketemu>=0) {
        printf("Data ditemukan pada posisi %d", ketemu);
    } else {
        printf("Data tidak ditemukan");
    }
} 