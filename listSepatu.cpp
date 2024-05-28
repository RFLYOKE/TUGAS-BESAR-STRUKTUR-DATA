#include<iostream>
#include <ctime>
#include <iomanip>
#include <fstream>
using namespace std;

struct Sepatu
{
    string namaSepatu;
    string tanggalRilis;
    int ukuran;
    int harga;
};

extern void tampilanPembelian();

void tampilWaktuTransaksi(){
    ifstream fileMasuk("saveWaktu.txt");
    if (!fileMasuk)
    {
        cout << "Gagal membuka file dataPembeli.txt" << endl;
        return;
    } else{
        string line;
        cout << endl;
        while (getline(fileMasuk, line))
        {
            cout << line << endl;
        }
    }
    fileMasuk.close();
}

void listSepatu(){
    ofstream file("saveWaktu.txt");
    if(!file){
        cout << "Gagal membuka file saveWaktu.txt" << endl;
        return;
    } else{
    time_t now = time(0);
    tm *ltm = localtime(&now);
    cout << "----------------------------------------------------------------\n";
    cout << setfill('0') << setw(2) << ltm->tm_mday << "/" << setfill('0') << setw(2) << 1 + ltm->tm_mon << "/" << 1900 + ltm->tm_year << endl;
    file << setfill('0') << setw(2) << ltm->tm_mday << "/" << setfill('0') << setw(2) << 1 + ltm->tm_mon << "/" << 1900 + ltm->tm_year << endl;
    }
    file.close();
    cout << "                       DATA PEMBELIAN SEPATU\n";
    cout << "\n";
    cout << "----------------------------------------------------------------\n";
    cout << " No.    Nama Sepatu      Tanggal Rilis     Ukuran      Harga\n";
    cout << "----------------------------------------------------------------\n";
    tampilanPembelian(); 
    cout << "----------------------------------------------------------------\n";
}