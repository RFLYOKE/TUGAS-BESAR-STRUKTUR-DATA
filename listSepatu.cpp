#include<iostream>
using namespace std;

struct Sepatu
{
    string namaSepatu;
    string tanggalRilis;
    int ukuran;
    int harga;
};

extern void tampilanPembelian();

void listSepatu(){
    cout << "Informasi Sepatu Yang Tersedia:\n";
    cout << "----------------------------------------------------------------\n";
    cout << " No.    Nama Sepatu      Tanggal Rilis     Ukuran      Harga\n";
    cout << "----------------------------------------------------------------\n";
    tampilanPembelian(); 
    cout << "----------------------------------------------------------------\n";
}