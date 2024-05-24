#include <iostream>
#include <fstream>
#include "listSepatu.cpp"
using namespace std;

const int maksimal = 1000;
bool keluar = false;
char yakin;
int pilihan;
string dataMasuk;
int totalHarga = 0;

struct barang
{
    int tempat;
    Sepatu data[maksimal];
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

void pushBarang(Sepatu dataMasuk)
{
    if (barangBelanjaKosong() == true)
    {
        sepatu.tempat++;
        sepatu.data[sepatu.tempat] = dataMasuk;
        cout << "Berhasil Menambahkan sepatu [" << dataMasuk.namaSepatu << "] ke dalam keranjang" << endl;
        cout << "Tanggal Rilis: " << dataMasuk.tanggalRilis << ", Ukuran: " << dataMasuk.ukuran << ", Harga: " << dataMasuk.harga << endl;
    }
    else if (barangBelanjaPenuh() == false)
    {
        sepatu.tempat++;
        sepatu.data[sepatu.tempat] = dataMasuk;
        cout << "Berhasil Menambahkan sepatu [" << dataMasuk.namaSepatu << "] ke dalam keranjang" << endl;
        cout << "Tanggal Rilis: " << dataMasuk.tanggalRilis << ", Ukuran: " << dataMasuk.ukuran << ", Harga: " << dataMasuk.harga << endl;
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
        cout << "Barang [" << sepatu.data[sepatu.tempat].namaSepatu << "] Berhasil Di Cancel" << endl;
        sepatu.tempat--;
    }
}

void popSemuaBarang()
{
    if (barangBelanjaKosong())
    {
        cout << "Belum Ada Barang Yang Anda Beli" << endl;
    }
    else
    {
        cout << "Semua Barang Berhasil Di Cancel" << endl;
        sepatu.tempat = -1;
    }
}

void tampilkanDataPembeli()
{
    ifstream fileIn("saveData.txt");
    if (!fileIn)
    {
        cout << "Gagal membuka file dataPembeli.txt" << endl;
        return;
    }

    string line;
    cout << "Data Pembeli:" << endl;
    while (getline(fileIn, line))
    {
        cout << line << endl;
    }

    fileIn.close();
}

void tampilanPembelian()
{
    totalHarga = 0;

    ofstream fileOut("saveData.txt", ios::app);
    if (!fileOut)
    {
        cout << "Gagal membuka file saveData.txt" << endl;
        return;
    }

    else if (barangBelanjaKosong())
    {
        cout << "Tidak Ada Barang Belanja" << endl;
        fileOut << "Tidak Ada Barang Belanja" << endl;
    }
    else
    {
        for (int i = 1; i <= sepatu.tempat; i++)
        {
            cout << i << ". " << sepatu.data[i].namaSepatu << "     " << sepatu.data[i].tanggalRilis << "     " << sepatu.data[i].ukuran << "     " << sepatu.data[i].harga << endl;
            fileOut << i << ". " << sepatu.data[i].namaSepatu << "     " << sepatu.data[i].tanggalRilis << "     " << sepatu.data[i].ukuran << "     " << sepatu.data[i].harga << endl;
            totalHarga += sepatu.data[i].harga;
        }
        cout << "Total Harga                                          " << totalHarga << endl;
        fileOut << "Total Harga                                          " << totalHarga << endl;
        fileOut << endl;
    }
    fileOut.close();
}

void ukuranSepatu()
{
    cout << "=================" << endl;
    cout << "  Ukuran sepatu  " << endl;
    cout << "=================" << endl;
    cout << "| 1.| 36        |" << endl;
    cout << "| 2.| 37        |" << endl;
    cout << "| 3.| 39        |" << endl;
    cout << "| 4.| 40        |" << endl;
    cout << "| 5.| 42        |" << endl;
    cout << "=================" << endl;
}

void loginUser()
{
    ifstream fileUser("loginUser.txt", ios::app);
    if (!fileUser)
    {
        cout << "Gagal membuka file dataPembeli.txt" << endl;
        return;
    }

    string line;
    cout << "Data Pembeli:" << endl;
    while (getline(fileUser, line))
    {
        cout << line << endl;
    }

    fileUser.close();
}

void loginPembeli()
{
    string username, password, usernameLogin, passwordLogin;

    int maksimal = 0;
    bool loginSukses = false;
    int pilih;

    // login pembeli
    ofstream fileLogin("loginUser.txt", ios::app);
    if (!fileLogin)
    {
        cout << "Tidak bisa membuka file loginUser.txt" << endl;
        return;
    }
    else
    {
        cout << "=============================================" << endl;
        cout << "                HELLO FRIENDS!               " << endl;
        cout << "              REGISTRASI DI SINI!            " << endl;
        cout << "=============================================" << endl;
        cout << endl;
        cout << "Silahkan Buat Username dan Password anda" << endl;
        cout << "Username* (no spasi): ";
        cin >> username;
        fileLogin << "Username user: " << username << endl;
    }
    fileLogin.close();
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
                cout << "==============================================" << endl;
                cout << "|                MENU PEMBELI                |" << endl;
                cout << "| 1.| List Sepatu Tersedia                   |" << endl;
                cout << "| 2.| Hapus sepatu terakhir yang dimasukkan  |" << endl;
                cout << "| 3.| Pembatalan pembelian                   |" << endl;
                cout << "| 4.| Rekapan Pembelian                      |" << endl;
                cout << "| 5.| Pembayaran                             |" << endl;
                cout << "| 0.| Keluar                                 |" << endl;
                cout << "==============================================" << endl;
                cout << "Silahkan masukkan pilihan anda: ";
                cin >> pilih;
                cout << endl;

                switch (pilih)
                {
                case 1:
                    int pilihanku;
                    do
                    {
                        cout << "====================================" << endl;
                        cout << "|             KATEGORI              |" << endl;
                        cout << "| 1.| Sepatu Sepak Bola             |" << endl;
                        cout << "| 2.| Sepatu Basket                 |" << endl;
                        cout << "| 3.| Sepatu Running                |" << endl;
                        cout << "| 4.| Sepatu Original               |" << endl;
                        cout << "====================================" << endl;
                        cout << "Silahkan pilih kategori anda: ";
                        cin >> pilihanku;
                        cout << endl;

                        if (pilihanku == 0)
                        {
                            cout << "-----KELUAR-----\n";
                            break;
                        }

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
                                if (pertama < 1 || pertama > 8)
                                {
                                    cout << "Pilihan tidak valid, keluar dari menu sepatu." << endl;
                                    break;
                                }
                                Sepatu namaSepatu1;
                                switch (pertama)
                                {
                                case 1:
                                    namaSepatu1.namaSepatu = "PREDATOR 24 ELITE LEKLESS";
                                    namaSepatu1.tanggalRilis = "2023-03-15";
                                    namaSepatu1.harga = 2500000;
                                    cout << endl;
                                    int pilUkuran1, ukuran1;
                                    do
                                    {
                                        ukuranSepatu();
                                        cout << "Silahkan pilih ukuran sepatu yang tersedia (1/2/3/4/5): ";
                                        cin >> pilUkuran1;
                                        switch (pilUkuran1)
                                        {
                                        case 1:
                                            ukuran1 = 36;
                                            break;
                                        case 2:
                                            ukuran1 = 37;
                                            break;
                                        case 3:
                                            ukuran1 = 39;
                                            break;
                                        case 4:
                                            ukuran1 = 40;
                                            break;
                                        case 5:
                                            ukuran1 = 42;
                                            break;
                                        default:
                                            cout << "Ukuran sepatu yang Anda pilih tidak tersedia. Silahkan coba lagi." << endl;
                                            cout << "Atau hubungi admin (0856-1404-1223)" << endl;
                                            continue;
                                        }
                                    } while (pilUkuran1 < 1 || pilUkuran1 > 5);
                                    namaSepatu1.ukuran = ukuran1;
                                    break;
                                case 2:
                                    namaSepatu1.namaSepatu = "SAMBA INTER MIAMI CF";
                                    namaSepatu1.tanggalRilis = "2024-01-20";
                                    namaSepatu1.harga = 1800000;
                                    cout << endl;
                                    int pilih_ukuran2, ukuran_kedua;
                                    do
                                    {
                                        ukuranSepatu();
                                        cout << "Silahkan pilih ukuran sepatu yang tersedia (1/2/3/4/5): ";
                                        cin >> pilih_ukuran2;
                                        switch (pilih_ukuran2)
                                        {
                                        case 1:
                                            ukuran_kedua = 36;
                                            break;
                                        case 2:
                                            ukuran_kedua = 37;
                                            break;
                                        case 3:
                                            ukuran_kedua = 39;
                                            break;
                                        case 4:
                                            ukuran_kedua = 40;
                                            break;
                                        case 5:
                                            ukuran_kedua = 42;
                                            break;
                                        default:
                                            cout << "Ukuran sepatu yang Anda pilih tidak tersedia. Silahkan coba lagi." << endl;
                                            cout << "Atau hubungi admin (0856-1404-1223)" << endl;
                                            continue;
                                        }
                                    } while (pilih_ukuran2 < 1 || pilih_ukuran2 > 5);
                                    namaSepatu1.ukuran = ukuran_kedua;
                                    break;
                                case 3:
                                    namaSepatu1.namaSepatu = "X CRAZYFAST ELITE FIRM";
                                    namaSepatu1.tanggalRilis = "2022-01-10";
                                    namaSepatu1.harga = 2200000;
                                    cout << endl;
                                    int pilUkuran3, ukuran3;
                                    do
                                    {
                                        ukuranSepatu();
                                        cout << "Silahkan pilih ukuran sepatu yang tersedia (1/2/3/4/5): ";
                                        cin >> pilUkuran3;
                                        switch (pilUkuran3)
                                        {
                                        case 1:
                                            ukuran3 = 36;
                                            break;
                                        case 2:
                                            ukuran3 = 37;
                                            break;
                                        case 3:
                                            ukuran3 = 39;
                                            break;
                                        case 4:
                                            ukuran3 = 40;
                                            break;
                                        case 5:
                                            ukuran3 = 42;
                                            break;
                                        default:
                                            cout << "Ukuran sepatu yang Anda pilih tidak tersedia. Silahkan coba lagi." << endl;
                                            cout << "Atau hubungi admin (0856-1404-1223)" << endl;
                                            continue;
                                        }
                                    } while (pilUkuran3 < 1 || pilUkuran3 > 5);
                                    namaSepatu1.ukuran = ukuran3;
                                    break;
                                case 4:
                                    namaSepatu1.namaSepatu = "PREDATOR LEAGUE FIRM";
                                    namaSepatu1.tanggalRilis = "2023-12-23";
                                    namaSepatu1.harga = 2100000;
                                    cout << endl;
                                    int pilUkuran4, ukuran4;
                                    do
                                    {
                                        ukuranSepatu();
                                        cout << "Silahkan pilih ukuran sepatu yang tersedia (1/2/3/4/5): ";
                                        cin >> pilUkuran4;
                                        switch (pilUkuran4)
                                        {
                                        case 1:
                                            ukuran4 = 36;
                                            break;
                                        case 2:
                                            ukuran4 = 37;
                                            break;
                                        case 3:
                                            ukuran4 = 39;
                                            break;
                                        case 4:
                                            ukuran4 = 40;
                                            break;
                                        case 5:
                                            ukuran4 = 42;
                                            break;
                                        default:
                                            cout << "Ukuran sepatu yang Anda pilih tidak tersedia. Silahkan coba lagi." << endl;
                                            cout << "Atau hubungi admin (0856-1404-1223)" << endl;
                                            continue;
                                        }
                                    } while (pilUkuran4 < 1 || pilUkuran4 > 5);
                                    namaSepatu1.ukuran = ukuran4;
                                    break;
                                case 5:
                                    namaSepatu1.namaSepatu = "PREDATOR 24 GROUND BOOTS";
                                    namaSepatu1.tanggalRilis = "2024-02-11";
                                    namaSepatu1.harga = 1100000;
                                    cout << endl;
                                    int pilUkuran5, ukuran5;
                                    do
                                    {
                                        ukuranSepatu();
                                        cout << "Silahkan pilih ukuran sepatu yang tersedia (1/2/3/4/5): ";
                                        cin >> pilUkuran5;
                                        switch (pilUkuran5)
                                        {
                                        case 1:
                                            ukuran5 = 36;
                                            break;
                                        case 2:
                                            ukuran5 = 37;
                                            break;
                                        case 3:
                                            ukuran5 = 39;
                                            break;
                                        case 4:
                                            ukuran5 = 40;
                                            break;
                                        case 5:
                                            ukuran5 = 42;
                                            break;
                                        default:
                                            cout << "Ukuran sepatu yang Anda pilih tidak tersedia. Silahkan coba lagi." << endl;
                                            cout << "Atau hubungi admin (0856-1404-1223)" << endl;
                                            continue;
                                        }
                                    } while (pilUkuran5 < 1 || pilUkuran5 > 5);
                                    namaSepatu1.ukuran = ukuran5;
                                    break;
                                case 6:
                                    namaSepatu1.namaSepatu = "COPA GLORD LEAGUE FIRM";
                                    namaSepatu1.tanggalRilis = "2024-02-19";
                                    namaSepatu1.harga = 1900000;
                                    cout << endl;
                                    int pilUkuran6, ukuran6;
                                    do
                                    {
                                        ukuranSepatu();
                                        cout << "Silahkan pilih ukuran sepatu yang tersedia (1/2/3/4/5): ";
                                        cin >> pilUkuran6;
                                        switch (pilUkuran6)
                                        {
                                        case 1:
                                            ukuran6 = 36;
                                            break;
                                        case 2:
                                            ukuran6 = 37;
                                            break;
                                        case 3:
                                            ukuran6 = 39;
                                            break;
                                        case 4:
                                            ukuran6 = 40;
                                            break;
                                        case 5:
                                            ukuran6 = 42;
                                            break;
                                        default:
                                            cout << "Ukuran sepatu yang Anda pilih tidak tersedia. Silahkan coba lagi." << endl;
                                            cout << "Atau hubungi admin (0856-1404-1223)" << endl;
                                            continue;
                                        }
                                    } while (pilUkuran6 < 1 || pilUkuran6 > 5);
                                    namaSepatu1.ukuran = ukuran6;
                                    break;
                                case 7:
                                    namaSepatu1.namaSepatu = "COPA GLORD 45";
                                    namaSepatu1.tanggalRilis = "2022-05-22";
                                    namaSepatu1.harga = 2000000;
                                    cout << endl;
                                    int pilUkuran7, ukuran7;
                                    do
                                    {
                                        ukuranSepatu();
                                        cout << "Silahkan pilih ukuran sepatu yang tersedia (1/2/3/4/5): ";
                                        cin >> pilUkuran7;
                                        switch (pilUkuran7)
                                        {
                                        case 1:
                                            ukuran7 = 36;
                                            break;
                                        case 2:
                                            ukuran7 = 37;
                                            break;
                                        case 3:
                                            ukuran7 = 39;
                                            break;
                                        case 4:
                                            ukuran7 = 40;
                                            break;
                                        case 5:
                                            ukuran7 = 42;
                                            break;
                                        default:
                                            cout << "Ukuran sepatu yang Anda pilih tidak tersedia. Silahkan coba lagi." << endl;
                                            cout << "Atau hubungi admin (0856-1404-1223)" << endl;
                                            continue;
                                        }
                                    } while (pilUkuran7 < 1 || pilUkuran7 > 5);
                                    namaSepatu1.ukuran = ukuran7;
                                    break;
                                case 8:
                                    namaSepatu1.namaSepatu = "X CRAZYFAST LEAGUE LEKLESS";
                                    namaSepatu1.tanggalRilis = "2023-07-30";
                                    namaSepatu1.harga = 2400000;
                                    cout << endl;
                                    int pilUkuran8, ukuran8;
                                    do
                                    {
                                        ukuranSepatu();
                                        cout << "Silahkan pilih ukuran sepatu yang tersedia (1/2/3/4/5): ";
                                        cin >> pilUkuran8;
                                        switch (pilUkuran8)
                                        {
                                        case 1:
                                            ukuran8 = 36;
                                            break;
                                        case 2:
                                            ukuran8 = 37;
                                            break;
                                        case 3:
                                            ukuran8 = 39;
                                            break;
                                        case 4:
                                            ukuran8 = 40;
                                            break;
                                        case 5:
                                            ukuran8 = 42;
                                            break;
                                        default:
                                            cout << "Ukuran sepatu yang Anda pilih tidak tersedia. Silahkan coba lagi." << endl;
                                            cout << "Atau hubungi admin (0856-1404-1223)" << endl;
                                            continue;
                                        }
                                    } while (pilUkuran8 < 1 || pilUkuran8 > 5);
                                    namaSepatu1.ukuran = ukuran8;
                                    break;
                                default:
                                    cout << "Pilihan tidak valid" << endl;
                                    continue;
                                }
                                pushBarang(namaSepatu1);
                                cout << endl;
                                cout << "Apakah anda ingin memilih sepatu lagi? (y/t): ";
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
                                if (kedua < 1 || kedua > 5)
                                {
                                    cout << "Pilihan tidak valid, keluar dari menu sepatu." << endl;
                                    break;
                                }
                                Sepatu namaSepatu2;
                                switch (kedua)
                                {
                                case 1:
                                    namaSepatu2.namaSepatu = "FORUM LOW SHOES";
                                    namaSepatu2.tanggalRilis = "2023-11-15";
                                    namaSepatu2.harga = 1600000;
                                    cout << endl;
                                    int pilUkuran1, ukuran1;
                                    do
                                    {
                                        ukuranSepatu();
                                        cout << "Silahkan pilih ukuran sepatu yang tersedia (1/2/3/4/5): ";
                                        cin >> pilUkuran1;
                                        switch (pilUkuran1)
                                        {
                                        case 1:
                                            ukuran1 = 36;
                                            break;
                                        case 2:
                                            ukuran1 = 37;
                                            break;
                                        case 3:
                                            ukuran1 = 39;
                                            break;
                                        case 4:
                                            ukuran1 = 40;
                                            break;
                                        case 5:
                                            ukuran1 = 42;
                                            break;
                                        default:
                                            cout << "Ukuran sepatu yang Anda pilih tidak tersedia. Silahkan coba lagi." << endl;
                                            cout << "Atau hubungi admin (0856-1404-1223)" << endl;
                                            continue;
                                        }
                                    } while (pilUkuran1 < 1 || pilUkuran1 > 5);
                                    namaSepatu2.ukuran = ukuran1;
                                    break;
                                case 2:
                                    namaSepatu2.namaSepatu = "SEPATU RIVALRY 86 LOW";
                                    namaSepatu2.tanggalRilis = "2024-03-22";
                                    namaSepatu2.harga = 1700000;
                                    cout << endl;
                                    int pilUkuran2, ukuran2;
                                    do
                                    {
                                        ukuranSepatu();
                                        cout << "Silahkan pilih ukuran sepatu yang tersedia (1/2/3/4/5): ";
                                        cin >> pilUkuran2;
                                        switch (pilUkuran2)
                                        {
                                        case 1:
                                            ukuran2 = 36;
                                            break;
                                        case 2:
                                            ukuran2 = 37;
                                            break;
                                        case 3:
                                            ukuran2 = 39;
                                            break;
                                        case 4:
                                            ukuran2 = 40;
                                            break;
                                        case 5:
                                            ukuran2 = 42;
                                            break;
                                        default:
                                            cout << "Ukuran sepatu yang Anda pilih tidak tersedia. Silahkan coba lagi." << endl;
                                            cout << "Atau hubungi admin (0856-1404-1223)" << endl;
                                            continue;
                                        }
                                    } while (pilUkuran2 < 1 || pilUkuran2 > 5);
                                    namaSepatu2.ukuran = ukuran2;
                                    break;
                                case 3:
                                    namaSepatu2.namaSepatu = "D.O.N. ISSUE 5 TRAINERS";
                                    namaSepatu2.tanggalRilis = "2023-01-05";
                                    namaSepatu2.harga = 1800000;
                                    cout << endl;
                                    int pilUkuran3, ukuran3;
                                    do
                                    {
                                        ukuranSepatu();
                                        cout << "Silahkan pilih ukuran sepatu yang tersedia (1/2/3/4/5): ";
                                        cin >> pilUkuran3;
                                        switch (pilUkuran3)
                                        {
                                        case 1:
                                            ukuran3 = 36;
                                            break;
                                        case 2:
                                            ukuran3 = 37;
                                            break;
                                        case 3:
                                            ukuran3 = 39;
                                            break;
                                        case 4:
                                            ukuran3 = 40;
                                            break;
                                        case 5:
                                            ukuran3 = 42;
                                            break;
                                        default:
                                            cout << "Ukuran sepatu yang Anda pilih tidak tersedia. Silahkan coba lagi." << endl;
                                            cout << "Atau hubungi admin (0856-1404-1223)" << endl;
                                            continue;
                                        }
                                    } while (pilUkuran3 < 1 || pilUkuran3 > 5);
                                    namaSepatu2.ukuran = ukuran3;
                                    break;
                                case 4:
                                    namaSepatu2.namaSepatu = "AE 1 LOW SHOES";
                                    namaSepatu2.tanggalRilis = "2022-10-10";
                                    namaSepatu2.harga = 1500000;
                                    cout << endl;
                                    int pilUkuran4, ukuran4;
                                    do
                                    {
                                        ukuranSepatu();
                                        cout << "Silahkan pilih ukuran sepatu yang tersedia (1/2/3/4/5): ";
                                        cin >> pilUkuran4;
                                        switch (pilUkuran4)
                                        {
                                        case 1:
                                            ukuran4 = 36;
                                            break;
                                        case 2:
                                            ukuran4 = 37;
                                            break;
                                        case 3:
                                            ukuran4 = 39;
                                            break;
                                        case 4:
                                            ukuran4 = 40;
                                            break;
                                        case 5:
                                            ukuran4 = 42;
                                            break;
                                        default:
                                            cout << "Ukuran sepatu yang Anda pilih tidak tersedia. Silahkan coba lagi." << endl;
                                            cout << "Atau hubungi admin (0856-1404-1223)" << endl;
                                            continue;
                                        }
                                    } while (pilUkuran4 < 1 || pilUkuran4 > 5);
                                    namaSepatu2.ukuran = ukuran4;
                                    break;
                                case 5:
                                    namaSepatu2.namaSepatu = "ADIZERO SELECT 2.0 SHOES";
                                    namaSepatu2.tanggalRilis = "2023-02-20";
                                    namaSepatu2.harga = 1900000;
                                    cout << endl;
                                    int pilUkuran5, ukuran5;
                                    do
                                    {
                                        ukuranSepatu();
                                        cout << "Silahkan pilih ukuran sepatu yang tersedia (1/2/3/4/5): ";
                                        cin >> pilUkuran5;
                                        switch (pilUkuran5)
                                        {
                                        case 1:
                                            ukuran5 = 36;
                                            break;
                                        case 2:
                                            ukuran5 = 37;
                                            break;
                                        case 3:
                                            ukuran5 = 39;
                                            break;
                                        case 4:
                                            ukuran5 = 40;
                                            break;
                                        case 5:
                                            ukuran5 = 42;
                                            break;
                                        default:
                                            cout << "Ukuran sepatu yang Anda pilih tidak tersedia. Silahkan coba lagi." << endl;
                                            cout << "Atau hubungi admin (0856-1404-1223)" << endl;
                                            continue;
                                        }
                                    } while (pilUkuran5 < 1 || pilUkuran5 > 5);
                                    namaSepatu2.ukuran = ukuran5;
                                    break;
                                default:
                                    cout << "Pilihan tidak valid" << endl;
                                    continue;
                                }
                                pushBarang(namaSepatu2);
                                cout << endl;
                                cout << "Apakah anda ingin memilih sepatu lagi? (y/t): ";
                                cin >> yakin;
                            } while (yakin == 'y' || yakin == 'Y');
                            cout << "Silahkan Melakukan Pembayaran" << endl;
                            break;
                        case 3:
                            int ketiga;
                            cout << "================================" << endl;
                            cout << "       DAFTAR SEPATU BASKET     " << endl;
                            cout << "================================" << endl;
                            cout << "| 1.|SEPATU SAMBA OG            |" << endl;
                            cout << "| 2.|ADIDAS N BAPE              |" << endl;
                            cout << "| 3.|GAZELLE LOW TRAINERS       |" << endl;
                            cout << "| 4.|SAMBA XYZ SHOEAS           |" << endl;
                            cout << "| 5.|LONDON SHOES               |" << endl;
                            cout << "| 6.|SL 72 RS SHOES             |" << endl;
                            cout << "================================" << endl;
                            do
                            {
                                cout << "Pilih Sepatu Anda (1/2/3/4/5/6): ";
                                cin >> ketiga;
                                if (ketiga < 1 || ketiga > 6)
                                {
                                    cout << "Pilihan tidak valid, keluar dari menu sepatu." << endl;
                                    break;
                                }
                                Sepatu namaSepatu3;
                                switch (ketiga)
                                {
                                case 1:
                                    namaSepatu3.namaSepatu = "SEPATU SAMBA OG";
                                    namaSepatu3.tanggalRilis = "2023-12-15";
                                    namaSepatu3.harga = 1600000;
                                    cout << endl;
                                    int pilUkuran1, ukuran1;
                                    do
                                    {
                                        ukuranSepatu();
                                        cout << "Silahkan pilih ukuran sepatu yang tersedia (1/2/3/4/5): ";
                                        cin >> pilUkuran1;
                                        switch (pilUkuran1)
                                        {
                                        case 1:
                                            ukuran1 = 36;
                                            break;
                                        case 2:
                                            ukuran1 = 37;
                                            break;
                                        case 3:
                                            ukuran1 = 39;
                                            break;
                                        case 4:
                                            ukuran1 = 40;
                                            break;
                                        case 5:
                                            ukuran1 = 42;
                                            break;
                                        default:
                                            cout << "Ukuran sepatu yang Anda pilih tidak tersedia. Silahkan coba lagi." << endl;
                                            cout << "Atau hubungi admin (0856-1404-1223)" << endl;
                                            continue;
                                        }
                                    } while (pilUkuran1 < 1 || pilUkuran1 > 5);
                                    namaSepatu3.ukuran = ukuran1;
                                    break;
                                case 2:
                                    namaSepatu3.namaSepatu = "ADIDAS N BAPE";
                                    namaSepatu3.tanggalRilis = "2024-03-21";
                                    namaSepatu3.harga = 1700000;
                                    cout << endl;
                                    int pilUkuran2, ukuran2;
                                    do
                                    {
                                        ukuranSepatu();
                                        cout << "Silahkan pilih ukuran sepatu yang tersedia (1/2/3/4/5): ";
                                        cin >> pilUkuran2;
                                        switch (pilUkuran2)
                                        {
                                        case 1:
                                            ukuran2 = 36;
                                            break;
                                        case 2:
                                            ukuran2 = 37;
                                            break;
                                        case 3:
                                            ukuran2 = 39;
                                            break;
                                        case 4:
                                            ukuran2 = 40;
                                            break;
                                        case 5:
                                            ukuran2 = 42;
                                            break;
                                        default:
                                            cout << "Ukuran sepatu yang Anda pilih tidak tersedia. Silahkan coba lagi." << endl;
                                            cout << "Atau hubungi admin (0856-1404-1223)" << endl;
                                            continue;
                                        }
                                    } while (pilUkuran2 < 1 || pilUkuran2 > 5);
                                    namaSepatu3.ukuran = ukuran2;
                                    break;
                                case 3:
                                    namaSepatu3.namaSepatu = "GAZELLE LOW TRAINERS";
                                    namaSepatu3.tanggalRilis = "2024-01-05";
                                    namaSepatu3.harga = 1800000;
                                    cout << endl;
                                    int pilUkuran3, ukuran3; // Changed variable names to avoid redeclaration
                                    do
                                    {
                                        ukuranSepatu();
                                        cout << "Silahkan pilih ukuran sepatu yang tersedia (1/2/3/4/5): ";
                                        cin >> pilUkuran3;
                                        switch (pilUkuran3)
                                        {
                                        case 1:
                                            ukuran3 = 36;
                                            break;
                                        case 2:
                                            ukuran3 = 37;
                                            break;
                                        case 3:
                                            ukuran3 = 39;
                                            break;
                                        case 4:
                                            ukuran3 = 40;
                                            break;
                                        case 5:
                                            ukuran3 = 42;
                                            break;
                                        default:
                                            cout << "Ukuran sepatu yang Anda pilih tidak tersedia. Silahkan coba lagi." << endl;
                                            cout << "Atau hubungi admin (0856-1404-1223)" << endl;
                                            continue;
                                        }
                                    } while (pilUkuran3 < 1 || pilUkuran3 > 5);
                                    namaSepatu3.ukuran = ukuran3;
                                    break;
                                case 4:
                                    namaSepatu3.namaSepatu = "SAMBA XYZ SHOEAS";
                                    namaSepatu3.tanggalRilis = "2022-08-10";
                                    namaSepatu3.harga = 1500000;
                                    cout << endl;
                                    int pilUkuran4, ukuran4; // Changed variable names to avoid redeclaration
                                    do
                                    {
                                        ukuranSepatu();
                                        cout << "Silahkan pilih ukuran sepatu yang tersedia (1/2/3/4/5): ";
                                        cin >> pilUkuran4;
                                        switch (pilUkuran4)
                                        {
                                        case 1:
                                            ukuran4 = 36;
                                            break;
                                        case 2:
                                            ukuran4 = 37;
                                            break;
                                        case 3:
                                            ukuran4 = 39;
                                            break;
                                        case 4:
                                            ukuran4 = 40;
                                            break;
                                        case 5:
                                            ukuran4 = 42;
                                            break;
                                        default:
                                            cout << "Ukuran sepatu yang Anda pilih tidak tersedia. Silahkan coba lagi." << endl;
                                            cout << "Atau hubungi admin (0856-1404-1223)" << endl;
                                            continue;
                                        }
                                    } while (pilUkuran4 < 1 || pilUkuran4 > 5);
                                    namaSepatu3.ukuran = ukuran4;
                                    break;
                                case 5:
                                    namaSepatu3.namaSepatu = "LONDON SHOES";
                                    namaSepatu3.tanggalRilis = "2021-02-20";
                                    namaSepatu3.harga = 1900000;
                                    cout << endl;
                                    int pilUkuran5, ukuran5;
                                    do
                                    {
                                        ukuranSepatu();
                                        cout << "Silahkan pilih ukuran sepatu yang tersedia (1/2/3/4/5): ";
                                        cin >> pilUkuran5;
                                        switch (pilUkuran5)
                                        {
                                        case 1:
                                            ukuran5 = 36;
                                            break;
                                        case 2:
                                            ukuran5 = 37;
                                            break;
                                        case 3:
                                            ukuran5 = 39;
                                            break;
                                        case 4:
                                            ukuran5 = 40;
                                            break;
                                        case 5:
                                            ukuran5 = 42;
                                            break;
                                        default:
                                            cout << "Ukuran sepatu yang Anda pilih tidak tersedia. Silahkan coba lagi." << endl;
                                            cout << "Atau hubungi admin (0856-1404-1223)" << endl;
                                            continue;
                                        }
                                    } while (pilUkuran5 < 1 || pilUkuran5 > 5);
                                    namaSepatu3.ukuran = ukuran5;
                                    break;
                                case 6:
                                    namaSepatu3.namaSepatu = "SL 72 RS SHOES";
                                    namaSepatu3.tanggalRilis = "2024-02-30";
                                    namaSepatu3.harga = 1900000;
                                    cout << endl;
                                    int pilUkuran6, ukuran6; // Changed variable names to avoid redeclaration
                                    do
                                    {
                                        ukuranSepatu();
                                        cout << "Silahkan pilih ukuran sepatu yang tersedia (1/2/3/4/5): ";
                                        cin >> pilUkuran6;
                                        switch (pilUkuran6)
                                        {
                                        case 1:
                                            ukuran6 = 36;
                                            break;
                                        case 2:
                                            ukuran6 = 37;
                                            break;
                                        case 3:
                                            ukuran6 = 39;
                                            break;
                                        case 4:
                                            ukuran6 = 40;
                                            break;
                                        case 5:
                                            ukuran6 = 42;
                                            break;
                                        default:
                                            cout << "Ukuran sepatu yang Anda pilih tidak tersedia. Silahkan coba lagi." << endl;
                                            cout << "Atau hubungi admin (0856-1404-1223)" << endl;
                                            continue;
                                        }
                                    } while (pilUkuran6 < 1 || pilUkuran6 > 5);
                                    namaSepatu3.ukuran = ukuran6;
                                    break;
                                default:
                                    cout << "Pilihan tidak valid" << endl;
                                    continue;
                                }
                                pushBarang(namaSepatu3);
                                cout << endl;
                                cout << "Apakah anda ingin memilih sepatu lagi? (y/t): ";
                                cin >> yakin;
                            } while (yakin == 'y' || yakin == 'Y');
                            cout << "Silahkan Melakukan Pembayaran" << endl;
                            break;
                        case 4:
                            int keempat;
                            cout << "================================" << endl;
                            cout << "       DAFTAR SEPATU ORIGINAL   " << endl;
                            cout << "================================" << endl;
                            cout << "| 1. |SEPATU SAMBA OG          |" << endl;
                            cout << "| 2. |ABIBAS_N_BAPE            |" << endl;
                            cout << "| 3. |SAMBA XLG SHOES          |" << endl;
                            cout << "| 4. |LONDON SHOES             |" << endl;
                            cout << "| 5. |GAZELLE 85 SHOES         |" << endl;
                            cout << "================================" << endl;
                            do
                            {
                                cout << "Pilih Sepatu Anda (1/2/3/4/5): ";
                                cin >> keempat;
                                if (keempat < 1 || keempat > 5)
                                {
                                    cout << "Pilihan tidak valid, keluar dari menu sepatu." << endl;
                                    break;
                                }
                                Sepatu namaSepatu4;
                                switch (keempat)
                                {
                                case 1:
                                    namaSepatu4.namaSepatu = "SEPATU SAMBA OG";
                                    namaSepatu4.tanggalRilis = "2023-12-14";
                                    namaSepatu4.harga = 2200000;
                                    cout << endl;
                                    int pilUkuran1, ukuran1;
                                    do
                                    {
                                        ukuranSepatu();
                                        cout << "Silahkan pilih ukuran sepatu yang tersedia (1/2/3/4/5): ";
                                        cin >> pilUkuran1;
                                        switch (pilUkuran1)
                                        {
                                        case 1:
                                            ukuran1 = 36;
                                            break;
                                        case 2:
                                            ukuran1 = 37;
                                            break;
                                        case 3:
                                            ukuran1 = 39;
                                            break;
                                        case 4:
                                            ukuran1 = 40;
                                            break;
                                        case 5:
                                            ukuran1 = 42;
                                            break;
                                        default:
                                            cout << "Ukuran sepatu yang Anda pilih tidak tersedia. Silahkan coba lagi." << endl;
                                            cout << "Atau hubungi admin (0856-1404-1223)" << endl;
                                            continue;
                                        }
                                    } while (pilUkuran1 < 1 || pilUkuran1 > 5);
                                    namaSepatu4.ukuran = ukuran1;
                                    break;
                                case 2:
                                    namaSepatu4.namaSepatu = "ABIBAS_N_BAPE";
                                    namaSepatu4.tanggalRilis = "2024-02-22";
                                    namaSepatu4.harga = 2300000;
                                    cout << endl;
                                    int pilUkuran2, ukuran2;
                                    do
                                    {
                                        ukuranSepatu();
                                        cout << "Silahkan pilih ukuran sepatu yang tersedia (1/2/3/4/5): ";
                                        cin >> pilUkuran2;
                                        switch (pilUkuran2)
                                        {
                                        case 1:
                                            ukuran2 = 36;
                                            break;
                                        case 2:
                                            ukuran2 = 37;
                                            break;
                                        case 3:
                                            ukuran2 = 39;
                                            break;
                                        case 4:
                                            ukuran2 = 40;
                                            break;
                                        case 5:
                                            ukuran2 = 42;
                                            break;
                                        default:
                                            cout << "Ukuran sepatu yang Anda pilih tidak tersedia. Silahkan coba lagi." << endl;
                                            cout << "Atau hubungi admin (0856-1404-1223)" << endl;
                                            continue;
                                        }
                                    } while (pilUkuran2 < 1 || pilUkuran2 > 5);
                                    namaSepatu4.ukuran = ukuran2;
                                    break;
                                case 3:
                                    namaSepatu4.namaSepatu = "SAMBA XLG SHOES";
                                    namaSepatu4.tanggalRilis = "2024-01-05";
                                    namaSepatu4.harga = 2400000;
                                    cout << endl;
                                    int pilUkuran3, ukuran3;
                                    do
                                    {
                                        ukuranSepatu();
                                        cout << "Silahkan pilih ukuran sepatu yang tersedia (1/2/3/4/5): ";
                                        cin >> pilUkuran3;
                                        switch (pilUkuran3)
                                        {
                                        case 1:
                                            ukuran3 = 36;
                                            break;
                                        case 2:
                                            ukuran3 = 37;
                                            break;
                                        case 3:
                                            ukuran3 = 39;
                                            break;
                                        case 4:
                                            ukuran3 = 40;
                                            break;
                                        case 5:
                                            ukuran3 = 42;
                                            break;
                                        default:
                                            cout << "Ukuran sepatu yang Anda pilih tidak tersedia. Silahkan coba lagi." << endl;
                                            cout << "Atau hubungi admin (0856-1404-1223)" << endl;
                                            continue;
                                        }
                                    } while (pilUkuran3 < 1 || pilUkuran3 > 5);
                                    namaSepatu4.ukuran = ukuran3;
                                    break;
                                case 4:
                                    namaSepatu4.namaSepatu = "LONDON SHOES";
                                    namaSepatu4.tanggalRilis = "2024-01-10";
                                    namaSepatu4.harga = 2200000;
                                    cout << endl;
                                    int pilUkuran4, ukuran4;
                                    do
                                    {
                                        ukuranSepatu();
                                        cout << "Silahkan pilih ukuran sepatu yang tersedia (1/2/3/4/5): ";
                                        cin >> pilUkuran4;
                                        switch (pilUkuran4)
                                        {
                                        case 1:
                                            ukuran4 = 36;
                                            break;
                                        case 2:
                                            ukuran4 = 37;
                                            break;
                                        case 3:
                                            ukuran4 = 39;
                                            break;
                                        case 4:
                                            ukuran4 = 40;
                                            break;
                                        case 5:
                                            ukuran4 = 42;
                                            break;
                                        default:
                                            cout << "Ukuran sepatu yang Anda pilih tidak tersedia. Silahkan coba lagi." << endl;
                                            cout << "Atau hubungi admin (0856-1404-1223)" << endl;
                                            continue;
                                        }
                                    } while (pilUkuran4 < 1 || pilUkuran4 > 5);
                                    namaSepatu4.ukuran = ukuran4;
                                    break;
                                case 5:
                                    namaSepatu4.namaSepatu = "GAZELLE 85 SHOES";
                                    namaSepatu4.tanggalRilis = "2024-02-20";
                                    namaSepatu4.harga = 1200000;
                                    cout << endl;
                                    int pilUkuran5, ukuran5;
                                    do
                                    {
                                        ukuranSepatu();
                                        cout << "Silahkan pilih ukuran sepatu yang tersedia (1/2/3/4/5): ";
                                        cin >> pilUkuran5;
                                        switch (pilUkuran5)
                                        {
                                        case 1:
                                            ukuran5 = 36;
                                            break;
                                        case 2:
                                            ukuran5 = 37;
                                            break;
                                        case 3:
                                            ukuran5 = 39;
                                            break;
                                        case 4:
                                            ukuran5 = 40;
                                            break;
                                        case 5:
                                            ukuran5 = 42;
                                            break;
                                        default:
                                            cout << "Ukuran sepatu yang Anda pilih tidak tersedia. Silahkan coba lagi." << endl;
                                            cout << "Atau hubungi admin (0856-1404-1223)" << endl;
                                            continue;
                                        }
                                    } while (pilUkuran5 < 1 || pilUkuran5 > 5);
                                    namaSepatu4.ukuran = ukuran5;
                                    break;
                                default:
                                    cout << "Pilihan tidak valid" << endl;
                                    continue;
                                }
                                pushBarang(namaSepatu4);
                                cout << endl;
                                cout << "Apakah anda ingin memilih sepatu lagi? (y/t): ";
                                cin >> yakin;
                            } while (yakin == 'y' || yakin == 'Y');
                            cout << "Silahkan Melakukan Pembayaran" << endl;
                            break;
                        default:
                            cout << "Pilihan yang anda masukkan salah, coba lagi \n";
                            break;
                        }
                    } while (pilihanku == 'y' || pilihanku == 'Y');
                    break;
                case 2:
                    popBarang();
                    break;
                case 3:
                    popSemuaBarang();
                    break;
                case 4:
                    listSepatu();
                    break;
                case 5:
                    int bayar;
                    cout << "================================================================" << endl;
                    cout << "                         Menu Pembayaran                        " << endl;
                    cout << "================================================================" << endl;
                    cout << "----------------------------------------------------------------\n";
                    cout << "Informasi pembelian sepatu:\n";
                    cout << "----------------------------------------------------------------\n";
                    cout << " No.    Nama Sepatu      Tanggal Rilis     Ukuran      Harga\n";
                    cout << "----------------------------------------------------------------\n";
                    tampilanPembelian();
                    cout << "----------------------------------------------------------------\n";
                    cout << endl;
                    do
                    {
                        cout << "Silahkan masukkan nominal pembayaran sesuai total yang dibeli: ";
                        cin >> bayar;
                    } while (bayar != totalHarga && bayar == 0);
                    if (barangBelanjaKosong() == true)
                    {
                        cout << "Anda tidak membeli apa apa" << endl;
                    }
                    else
                    {
                        cout << "Pembayaran Berhasil..." << endl;
                    }

                    break;
                case 0:
                    cout << "Terima Kasih Sudah Datang" << endl;
                    break;
                default:
                    cout << "Pilihan tidak valid, silahkan coba lagi." << endl;
                    break;
                }
            } while (pilih != 0);
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
