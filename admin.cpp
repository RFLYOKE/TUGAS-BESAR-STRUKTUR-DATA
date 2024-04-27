#include <iostream>
#include "listSepatu.cpp"
using namespace std;

const string username = "admin";
const string password = "admin123";
const int maximal = 100;
string inputan;

struct Sepatuu
{
    string namaSepatu;
    string tanggalRilis;
    float ukuran;
    int harga;
};

struct stock{
    int posisi;
    Sepatuu data[maximal];
}tumpukan;

void inisialisasiAdmin(){
    tumpukan.posisi = -1;
}

bool stockKosong(){
    if(tumpukan.posisi==-1){
        return true;
    }else{
        return false;
    }
}

bool stockPenuh(){
    if(tumpukan.posisi==maximal-1){
        return true;
    }else{
        return false;
    }
}

void pushData(Sepatuu inputan){
    if(stockPenuh()==false){
        tumpukan.posisi++;
        tumpukan.data[tumpukan.posisi]=inputan;
        cout<<"Berhasil Menambahkan Sepatu [ "<<inputan.namaSepatu<<" ] ke dalam daftar stock"<<endl;
        cout<<"Tanggal Rilis: "<<inputan.tanggalRilis<< ", Ukuran: "<<inputan.ukuran<<", Harga: "<<inputan.harga<<endl;
    }else if(stockKosong()==true){
        tumpukan.posisi++;
        tumpukan.data[tumpukan.posisi]=inputan;
        cout<<"Berhasil Menambahkan Sepatu [ "<<inputan.namaSepatu<<" ] ke dalam daftar stock"<<endl;
        cout<<"Tanggal Rilis: "<<inputan.tanggalRilis<< ", Ukuran: "<<inputan.ukuran<<", Harga: "<<inputan.harga<<endl;
    }else{
        cout<<"List Sepatu Sudah Penuh"<<endl;
    }
}

void popData(){
    if(stockKosong()==false){
        tumpukan.posisi--;
        cout<<"Data stock sepatu berhasil dihapus "<<endl;
    }else{
        cout<<"Tidak ada data sepatu "<<endl;
    }
}

void tampil(){
    if(stockKosong()==true){
        cout<<"Tidak ada data sepatu "<<endl;
    }else{
        for(int c=0; c>=tumpukan.posisi; c--){
            cout<<c<<". "<<tumpukan.data[c].namaSepatu<<" "<<tumpukan.data[c].tanggalRilis<<" "<<tumpukan.data[c].ukuran<<" "<<tumpukan.data[c].harga<<endl;

        }
    }
}

void loginAdmin()
{
    string usernameInput, passwordInput;
    bool sukses = false;
    int kesempatan = 0;

    do
    {
        cout << "=============================================" << endl;
        cout << "                   LOGIN ADMIN               " << endl;
        cout << "=============================================" << endl;
        cout << "Silahkan Masukkan Username dan Password Anda" << endl;
        cout << "Username: ";
        cin >> usernameInput;
        cout << "Password: ";
        cin >> passwordInput;
        cout << endl;

        if (usernameInput == username && passwordInput == password)
        {
            cout << "Login Berhasil!" << endl;
            sukses = true;
            
        }
        else
        {
            kesempatan++;
            cout << "Username atau Password salah, silahkan coba lagi." << endl;
            if (kesempatan >= 3)
            {
                cout << "Anda telah mencoba login sebanyak 3 kali. Silahkan coba lagi nanti." << endl;
                break;
            }
        }
    } while (!sukses && kesempatan < 3);
}
