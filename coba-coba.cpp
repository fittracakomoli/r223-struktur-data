#include <iostream>
#define MAKS 2
using namespace std;

struct date {
    int month;
    int day;
    int year;
};

struct person {
    char name[30];
    struct date birthday;
};

struct person students[MAKS];

int main()
{
    for(int i=0; i<MAKS; i++){
        cout << "Mahasiswa " << i+1 << endl;
        cout << "Nama: ";
        cin >> students[i].name;
        cout << "Tanggal Lahir (mm/dd/yyy): ";
        cin >> students[i].birthday.month >> students[i].birthday.day >> students[i].birthday.year;
    }

    for(int i=0; i<MAKS; i++){
        cout << "Mahasiswa " << i+1 <<  " :" << endl;
        cout << students[i].name;
        cout << students[i].birthday.month << " / " << students[i].birthday.day << " / " << students[i].birthday.year << endl;
    }
}