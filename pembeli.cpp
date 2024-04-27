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
};
barang sepatu;

void inisialisasi()
{
    sepatu.tempat = -1;
}

bool barangBelanjaKosong()
{
    if (sepatu.tempat == -1)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool barangBelanjaPenuh()
{
    if (sepatu.tempat == maksimal - 1)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void pushBarang(string dataMasuk)
{
    if (barangBelanjaKosong() == true)
    {
        sepatu.tempat++;
        sepatu.data[sepatu.tempat] = dataMasuk;
        cout << "Berhasil Menambahkan sepatu [" << dataMasuk << "] ke dalam keranjang" << endl;
    }
    else if (barangBelanjaPenuh() == false)
    {
        sepatu.tempat++;
        sepatu.data[sepatu.tempat] = dataMasuk;
        cout << "Berhasil Menambahkan sepatu [" << dataMasuk << "] ke dalam keranjang" << endl;
    }
    else
    {
        cout << "Barang Anda Terlalu Banyak Silahkan Datang Kembali Besok" << endl;
    }
}

void popBarang()
{
    if (barangBelanjaKosong() == true)
    {
        cout << "Belum Ada Barang Yang Anda Beli" << endl;
    }
    else
    {
        sepatu.tempat--;
        cout << "Barang Berhasil Di Cancel" << endl;
    }
}

void tampilanPembelian()
{
    if (barangBelanjaKosong() == true)
    {
        cout << "Tidak Ada Barang Belanja" << endl;
    }
    else
    {
        for (int i = 1; i <= sepatu.tempat; i++)
        {
            cout << i << ".     " << sepatu.data[i] << endl;
        }
    }
}

void loginPembeli()
{
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

    do
    {
        cout << "=============================================" << endl;
        cout << "                LOGIN PEMBELI                " << endl;
        cout << "=============================================" << endl;
        cout << "Silahkan Masukkan Username dan Password anda" << endl;
        cout << "Username: ";
        cin >> usernameLogin;
        cout << "Password: ";
        cin >> passwordLogin;
        cout << endl;

        if (usernameLogin == username && passwordLogin == password)
        {
            cout << "Login Berhasil!" << endl;
            loginSukses = true;

            do
            {
                cout << "====================================" << endl;
                cout << "|           MENU PEMBELI            |" << endl;
                cout << "| 1.| List Sepatu Tersedia          |" << endl;
                cout << "| 2.| Pembatalan pembelian          |" << endl;
                cout << "| 3.| Rekapan Pembelian             |" << endl;
                cout << "| 4.| Pembayaran                    |" << endl;
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
                        int pertama;
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
                        do
                        {
                            cout << "Pilih Sepatu Anda (1/2/3/4/5/6/7/8): ";
                            cin >> pertama;
                            string namaSepatu1;
                            switch (pertama)
                            {
                            case 1:
                                namaSepatu1 = "PREDATOR 24 ELITE LEKLESS";
                                break;
                            case 2:
                                namaSepatu1 = "SAMBA INTER MIAMI CF";
                                break;
                            case 3:
                                namaSepatu1 = "X CRAZYFAST ELITE FIRM";
                                break;
                            case 4:
                                namaSepatu1 = "PREDATOR LEAGUE FIRM";
                                break;
                            case 5:
                                namaSepatu1 = "PREDATOR 24 GROUND BOOTS";
                                break;
                            case 6:
                                namaSepatu1 = "COPA GLORD LEAGUE FIRM";
                                break;
                            case 7:
                                namaSepatu1 = "COLekLessPA GLORD 45";
                                break;
                            case 8:
                                namaSepatu1 = "X CRAZYFAST LEAGUE LEKLESS";
                                break;
                            default:
                                namaSepatu1 = "Pilihan tidak valid";
                                break;
                            }
                            pushBarang(namaSepatu1);
                            cout << "Apakah anda ingin memilih lagi? (y/t): ";
                            cin >> yakin;
                        } while (yakin == 'y' || yakin == 'Y');
                        cout << "Silahkan Melakukan Pembayaran" << endl;
                        break;
                    case 2:
                        int kedua;
                        cout << "================================" << endl;
                        cout << "       DAFTAR SEPATU BASKET     " << endl;
                        cout << "================================" << endl;
                        cout << "| 1.|FORUM LOW SHOES            |" << endl;
                        cout << "| 2.|SEPATU RIVALRY 86 LOW      |" << endl;
                        cout << "| 3.|D.O.N. ISSUE 5 TRAINERS    |" << endl;
                        cout << "| 4.|AE 1 LOW SHOES             |" << endl;
                        cout << "| 5.|ADIZERO SELECT 2.0 SHOES   |" << endl;
                        cout << "================================" << endl;
                        do
                        {
                            cout << "Pilih Sepatu Anda (1/2/3/4/5): ";
                            cin >> kedua;
                            string namaSepatu2;
                            switch (kedua)
                            {
                            case 1:
                                namaSepatu2 = "FORUM LOW SHOES";
                                break;
                            case 2:
                                namaSepatu2 = "SEPATU RIVALRY 86 LOW";
                                break;
                            case 3:
                                namaSepatu2 = "D.O.N. ISSUE 5 TRAINERS";
                                break;
                            case 4:
                                namaSepatu2 = "AE 1 LOW SHOES";
                                break;
                            case 5:
                                namaSepatu2 = "ADIZERO SELECT 2.0 SHOES";
                                break;
                            default:
                                namaSepatu2 = "Pilihan tidak valid";
                                break;
                            }
                            pushBarang(namaSepatu2);
                            cout << "Apakah anda ingin memilih lagi? (y/t): ";
                            cin >> yakin;
                        } while (yakin == 'y' || yakin == 'Y');
                        cout << "Silahkan Melakukan Pembayaran" << endl;
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
                else if (pilih == 4)
                {
                    cout << "=========================" << endl;
                    cout << "     Menu Pembayaran     " << endl;
                    cout << "=========================" << endl;
                }
                else
                {
                    cout << " Terima Kasih Sudah Datang " << endl;
                }
            } while (keluar == false);
        }
        else
        {
            maksimal++;
            cout << "Username atau Password salah, silahkan coba lagi." << endl;
            if (maksimal >= 3)
            {
                cout << "Anda telah mencoba login sebanyak 3 kali. Silahkan coba lagi nanti." << endl;
                break;
            }
        }
    } while (!loginSukses && maksimal < 3);
}
