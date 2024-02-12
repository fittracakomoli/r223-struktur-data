#include <iostream>
using namespace std;

typedef struct tanggal {
    int hari;
    string bulan;
    int tahun;
} TGL;

struct mahasiswa {
    string nama;
    string prodi;
    float ipk;
};

int main()
{
    TGL a;
    a.hari = 17;
    a.bulan = "Agustus";
    a.tahun = 1945;

    cout << a.hari << endl;
    cout << a.bulan << endl;
    cout << a.tahun << endl;

    mahasiswa mhs;
    mhs.nama = "Fittra";
    mhs.prodi = "TI";
    mhs.ipk = 3.89;

    cout << mhs.nama << endl;
    cout << mhs.prodi << endl;
    cout << mhs.ipk << endl;

    return 0;
}