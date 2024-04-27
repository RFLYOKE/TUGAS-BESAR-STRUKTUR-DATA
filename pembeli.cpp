#include <iostream>
#include "listSepatu.cpp"
using namespace std;

const int maksimal = 100;
bool keluar = false;
char yakin;
int pilihan;
string dataMasuk;

struct barang
{
    int tempat;
    string data[maksimal];
}; barang sepatu;


void inisialisasi(){
    sepatu.tempat = -1;
}

bool barangBelanjaKosong(){
    if(sepatu.tempat == -1){
        return true;
    } else{
        return false;
    }
}

bool barangBelanjaPenuh(){
    if(sepatu.tempat == maksimal -1){
        return true;
    } else{
        return false;
    }
}

void pushBarang(int dataMasuk){
    if(barangBelanjaKosong() == true){
        sepatu.tempat++;
        sepatu.data[sepatu.tempat] = dataMasuk;
        cout << "Berhasil Menambahkan sepatu nomer " << dataMasuk << " ke dalam keranjang" << endl;
    } else if(barangBelanjaPenuh() == false){
        sepatu.tempat++;
        sepatu.data[sepatu.tempat] = dataMasuk;
        cout << "Berhasil Menambahkan sepatu nomer " << dataMasuk << " ke dalam keranjang" << endl;
    } else {
        cout << "Barang Anda Terlalu Banyak Silahkan Datang Kembali Besok" << endl;
    }
}

void popBarang(){
    if(barangBelanjaKosong() == true){
        cout << "Belum Ada Barang Yang Anda Beli" << endl;
    } else{
        sepatu.tempat--;
        cout << "Barang Berhasil Di Cancel" << endl;
    }
}

void tampilanPembelian(){
    if(barangBelanjaKosong() == true){
        cout << "Tidak Ada Barang Belanja" << endl;
    } else{
        for(int i=0; i < sepatu.tempat; i++){
            cout << sepatu.data[i] << endl;
        }
    }
}


void loginPembeli(){
    string username, password, usernameLogin, passwordLogin;
    
    int maksimal = 0; 
    bool loginSukses = false;
    int pilih;

    // login pembeli
    cout << "=============================================" << endl;
    cout << "                HELLO FRIENDS!               " << endl;
    cout << "              REGISTRASI DI SINI!            " << endl;
    cout << "=============================================" << endl;
    cout << endl;
    cout << "Silahkan Buat Username dan Password anda" << endl;
    cout << "Username* (no spasi): ";
    cin >> username;
    cout << "Password* (no spasi): ";
    cin >> password;
    cout << endl;
    cout << "Akun Anda Berhasil Dibuat..." << endl;
    cout << endl;
    
    do {
        cout << "=============================================" << endl;
        cout << "                LOGIN PEMBELI                " << endl;
        cout << "=============================================" << endl;
        cout << "Silahkan Masukkan Username dan Password anda" << endl;
        cout << "Username: ";
        cin >> usernameLogin;
        cout << "Password: ";
        cin >> passwordLogin;
        cout << endl;

        if(usernameLogin == username && passwordLogin == password) {
            cout << "Login Berhasil!" << endl;
            loginSukses = true;

            do{
            cout << "====================================" << endl;
            cout << "|           MENU PEMBELI            |" << endl;
            cout << "| 1.| List Sepatu Tersedia          |" << endl;
            cout << "| 2.| Pembatalan pembelian          |" << endl;
            cout << "| 3.| Rekapan Pembelian             |" << endl;
            cout << "| 0.| Keluar                        |" << endl;
            cout << "====================================" << endl;
            cout << "Silahkan masukkan pilihan anda: ";
            cin >> pilih;
            cout << endl;

            if (pilih == 1)
            {
                int pilihanku;
                cout << "====================================" << endl;
                cout << "|             KATEGORI              |" << endl;
                cout << "| 1.| Sepatu Sepak Bola             |" << endl;
                cout << "| 2.| Sepatu Basket                 |" << endl;
                cout << "| 3.| Sepatu Running                |" << endl;
                cout << "| 4.| Sepatu Sekolah                |" << endl;
                cout << "| 0.| Keluar                        |" << endl;
                cout << "====================================" << endl;
                cout << "Silahkan pilih kategori anda: ";
                cin >> pilihanku;
                cout << endl;
                switch (pilihanku)
                {
                case 1:
                    int pilih;
                    cout << "================================" << endl;
                    cout << "     DAFTAR SEPATU SEPAK BOLA   " << endl;
                    cout << "================================" << endl;
                    cout << "| 1.| PREDATOR 24 ELITE LEKLESS |" << endl;
                    cout << "| 2.| SAMBA INTER MIAMI CF      |" << endl;
                    cout << "| 3.| X CRAZYFAST ELITE FIRM    |" << endl;
                    cout << "| 4.| PREDATOR LEAGUE FIRM      |" << endl;
                    cout << "| 5.| PREDATOR 24 GROUND BOOTS  |" << endl;
                    cout << "| 6.| COPA GLORD LEAGUE FIRM    |" << endl;
                    cout << "| 7.| COLekLessPA GLORD 45      |" << endl;
                    cout << "| 8.| X CRAZYFAST LEAGUE LEKLESS|" << endl;
                    cout << "================================" << endl;
                    do{
                    cout << "Pilih Sepatu Anda (1/2/3/4/5/6/7/8): ";
                    cin >> pilih;
                    pushBarang(dataMasuk);
                    cout << "Apakah anda ingin memilih lagi? (y/t)";
                    cin >> yakin;
                    } while (yakin == 'y' || yakin == 'Y');
                    cout << "Silahkan Melakukan Pembayaran" << endl;
                    break;
                case 2:
                    
                    break;
                case 3:
                    
                    break;
                case 4:
                   
                    break;
                case 0:
                    cout << "-----KELUAR-----\n";
                    break;
                default:
                    cout << "Pilihan yang anda masukkan salah, coba lagi \n";
                    break;
                }
            }
            else if (pilih == 2)
            {
                popBarang();
            }
            else if (pilih == 3)
            {
                listSepatu();
            }
            else
            {
                cout << " Terima Kasih Sudah Datang " << endl;
            }
        } while(keluar == false);
        } else {
            maksimal++;
            cout << "Username atau Password salah, silahkan coba lagi." << endl;
            if(maksimal >= 3) {
                cout << "Anda telah mencoba login sebanyak 3 kali. Silahkan coba lagi nanti." << endl;
                break;
            }
        }
    } while (!loginSukses && maksimal < 3);
}

