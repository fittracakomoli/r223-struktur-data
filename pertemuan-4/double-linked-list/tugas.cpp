#include <iostream>
#include <string>
using namespace std;

// Struktur untuk node dalam Double Linked List
struct Buku {
    string judul;
    string pengarang;
    string penerbit;
    Buku* prev;
    Buku* next;
};

// Pointer untuk head dan tail dari Double Linked List
Buku* head = nullptr;
Buku* tail = nullptr;

// Fungsi untuk menambahkan buku ke akhir Double Linked List
void tambahBuku(string judul, string pengarang, string penerbit) {
    Buku* bukuBaru = new Buku;
    bukuBaru->judul = judul;
    bukuBaru->pengarang = pengarang;
    bukuBaru->penerbit = penerbit;
    bukuBaru->prev = nullptr;
    bukuBaru->next = nullptr;

    if (head == nullptr) {
        head = bukuBaru;
        tail = bukuBaru;
    } else {
        tail->next = bukuBaru;
        bukuBaru->prev = tail;
        tail = bukuBaru;
    }
}

// Fungsi untuk menghapus buku dari Double Linked List berdasarkan judul
void hapusBuku(string judul) {
    Buku* current = head;
    while (current != nullptr) {
        if (current->judul == judul) {
            if (current == head) {
                head = head->next;
                if (head != nullptr)
                    head->prev = nullptr;
                delete current;
                return;
            } else if (current == tail) {
                tail = tail->prev;
                tail->next = nullptr;
                delete current;
                return;
            } else {
                current->prev->next = current->next;
                current->next->prev = current->prev;
                delete current;
                return;
            }
        }
        current = current->next;
    }
    cout << "Buku dengan judul '" << judul << "' tidak ditemukan." << endl;
}

// Fungsi untuk mencetak seluruh buku dalam Double Linked List
void cetakBuku() {
    Buku* current = head;
    cout << "Daftar Buku dalam Perpustakaan:" << endl;
    while (current != nullptr) {
        cout << "Judul: " << current->judul << endl;
        cout << "Pengarang: " << current->pengarang << endl;
        cout << "Penerbit: " << current->penerbit << endl;
        cout << endl;
        current = current->next;
    }
}

int main() {
    // Menambahkan beberapa buku ke dalam Double Linked List
    tambahBuku("Harry Potter", "J.K. Rowling", "Gramedia");
    tambahBuku("Lord of the Rings", "J.R.R. Tolkien", "Penerbit X");
    tambahBuku("Sherlock Holmes", "Arthur Conan Doyle", "Penerbit Y");

    // Mencetak daftar buku sebelum penghapusan
    cetakBuku();
    cout << endl;

    // Menghapus buku dengan judul "Harry Potter"
    hapusBuku("Harry Potter");

    // Mencetak daftar buku setelah penghapusan
    cetakBuku();

    return 0;
}