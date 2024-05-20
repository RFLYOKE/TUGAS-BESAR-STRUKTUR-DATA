#include<iostream>
#include <ctime>
#include <iomanip>
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
    time_t now = time(0);
    tm *ltm = localtime(&now);
    cout << "----------------------------------------------------------------\n";
    cout << setfill('0') << setw(2) << ltm->tm_mday << "/" << setfill('0') << setw(2) << 1 + ltm->tm_mon << "/" << 1900 + ltm->tm_year << endl;
    cout << "                       DATA PEMBELIAN SEPATU\n";
    cout << "\n";
    cout << "----------------------------------------------------------------\n";
    cout << " No.    Nama Sepatu      Tanggal Rilis     Ukuran      Harga\n";
    cout << "----------------------------------------------------------------\n";
    tampilanPembelian(); 
    cout << "----------------------------------------------------------------\n";
}