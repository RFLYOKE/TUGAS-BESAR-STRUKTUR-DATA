#include<iostream>
using namespace std;

struct Sepatu
{
    string namaSepatu;
    string tanggalRilis;
    float ukuran;
    double harga;
};

extern void tampilanPembelian();

void listSepatu(){
    cout << "Informasi Sepatu Yang Tersedia:\n";
    cout << "-----------------------------------------------------------------------\n";
    cout << "No.    Nama Sepatu      Tanggal Rilis     Ukuran      Stock      Harga\n";
    cout << "------------------------------------------------------------------------\n";
    tampilanPembelian(); 
    cout << "------------------------------------------------------------------------\n";
}