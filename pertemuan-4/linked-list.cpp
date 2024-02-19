#include <iostream>
using namespace std;

struct buku {
    string judul;
    int tahun;
    string penerbit;
    struct buku *next;
};

int main()
{
    // Inisialisasi
    buku *node1, *node2, *node3;
    node1 = new buku();
    node2 = new buku();
    node3 = new buku();

    // Mengisi
    node1->judul = "Matematika";
    node1->tahun = 2020;
    node1->penerbit = "Erlangga";
    node1->next = node2;

    node2->judul = "Fisika";
    node2->tahun = 2021;
    node2->penerbit = "Eka Jaya";
    node2->next = node3;

    node3->judul = "Biologi";
    node3->tahun = 2022;
    node3->penerbit = "Intan Pariwara";
    node3->next = NULL;

    // Cetak
    buku *cur;
    cur = node1;
    while(cur != NULL) {
        cout << "Judul Buku : " << cur->judul << endl;
        cout << "Tahun Terbit : " << cur->tahun << endl;
        cout << "Penerbit : " << cur->penerbit << endl;
        cur = cur->next;
    }

}