#include <iostream>
using namespace std;

struct Mahasiswa {
    int umur;
    string nim, nama, jurusan;

    Mahasiswa *next;
};

Mahasiswa *head, *tail, *cur, *newNode, *del;

void tambahMahasiswa(string nim, string nama, string jurusan, int umur) {
    head = new Mahasiswa();
    head->nim = nim;
    head->nama = nama;
    head->jurusan = jurusan;
    head->umur = umur;
    head->next = NULL;
    tail = head;
}

void tambahMahasiswaLagi(string nim, string nama, string jurusan, int umur) {
    newNode = new Mahasiswa();
    newNode->nim = nim;
    newNode->nama = nama;
    newNode->jurusan = jurusan;
    newNode->umur = umur;
    newNode->next = NULL;
    tail->next = newNode;
    tail = newNode;
}

void hapusMahasiswa() {
    del = head;
    head = head->next;
    delete del;
}

void cetakMahasiswa() {
    cur = head;
    while(cur != NULL) {
        cout << "NIM : " << cur->nim << endl;
        cout << "NAMA : " << cur->nama << endl;
        cout << "JURUSAN : " << cur->jurusan << endl;
        cout << "UMUR : " << cur->umur << endl;

        cur = cur->next;
    }
}

int main() {
    string nim, nama, jurusan;
    int umur, pilihan;
    cout << "1. Tambah Mahasiswa" << endl;
    cout << "2. Tambah Mahasiswa Lagi" << endl;
    cout << "3. Hapus Mahasiswa" << endl;
    cout << "4. Cetak Mahasiswa" << endl;
    cout << "Masukkan Pilihan : ";
    cin >> pilihan;

    switch (pilihan) {
        case 1:
        cout << "NIM : ";
        cin>>nim;
        cout << "NAMA : ";
        cin>>nama;
        cout << "JURUSAN : ";
        cin>>jurusan;
        cout << "UMUR : ";
        cin>>umur;

        tambahMahasiswa(nim, nama, jurusan, umur);
    
        case 2:
        cetakMahasiswa();
    }
}