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
<<<<<<< HEAD
    string data[maksimal];
}; barang sepatu;
=======
    Sepatu data[maksimal];
};
barang sepatu;
>>>>>>> 2a5ad59535493f16b61c34703177023f7f19a13a

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
            cout << i << ". " << sepatu.data[i].namaSepatu << "  " << sepatu.data[i].tanggalRilis << "  " << sepatu.data[i].ukuran << "  " << sepatu.data[i].harga << endl;
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
                        cout << "| 4.| Sepatu Sekolah                |" << endl;
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
                                    namaSepatu1.ukuran = 42;
                                    namaSepatu1.harga = 2500000;
                                    break;
                                case 2:
                                    namaSepatu1.namaSepatu = "SAMBA INTER MIAMI CF";
                                    namaSepatu1.tanggalRilis = "2024-01-20";
                                    namaSepatu1.ukuran = 43;
                                    namaSepatu1.harga = 1800000;
                                    break;
                                case 3:
                                    namaSepatu1.namaSepatu = "X CRAZYFAST ELITE FIRM";
                                    namaSepatu1.tanggalRilis = "2022-01-10";
                                    namaSepatu1.ukuran = 44;
                                    namaSepatu1.harga = 2200000;
                                    break;
                                case 4:
                                    namaSepatu1.namaSepatu = "PREDATOR LEAGUE FIRM";
                                    namaSepatu1.tanggalRilis = "2023-12-23";
                                    namaSepatu1.ukuran = 42.5;
                                    namaSepatu1.harga = 2100000;
                                    break;
                                case 5:
                                    namaSepatu1.namaSepatu = "PREDATOR 24 GROUND BOOTS";
                                    namaSepatu1.tanggalRilis = "2024-02-11";
                                    namaSepatu1.ukuran = 41;
                                    namaSepatu1.harga = 2300000;
                                    break;
                                case 6:
                                    namaSepatu1.namaSepatu = "COPA GLORD LEAGUE FIRM";
                                    namaSepatu1.tanggalRilis = "2024-02-19";
                                    namaSepatu1.ukuran = 43.5;
                                    namaSepatu1.harga = 1900000;
                                    break;
                                case 7:
                                    namaSepatu1.namaSepatu = "COLekLessPA GLORD 45";
                                    namaSepatu1.tanggalRilis = "2022-05-22";
                                    namaSepatu1.ukuran = 40;
                                    namaSepatu1.harga = 2000000;
                                    break;
                                case 8:
                                    namaSepatu1.namaSepatu = "X CRAZYFAST LEAGUE LEKLESS";
                                    namaSepatu1.tanggalRilis = "2023-07-30";
                                    namaSepatu1.ukuran = 42;
                                    namaSepatu1.harga = 2400000;
                                    break;
                                default:
                                    cout << "Pilihan tidak valid" << endl;
                                    continue;
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
                                    namaSepatu2.ukuran = 42;
                                    namaSepatu2.harga = 1600000;
                                    break;
                                case 2:
                                    namaSepatu2.namaSepatu = "SEPATU RIVALRY 86 LOW";
                                    namaSepatu2.tanggalRilis = "2024-03-22";
                                    namaSepatu2.ukuran = 43;
                                    namaSepatu2.harga = 1700000;
                                    break;
                                case 3:
                                    namaSepatu2.namaSepatu = "D.O.N. ISSUE 5 TRAINERS";
                                    namaSepatu2.tanggalRilis = "2023-01-05";
                                    namaSepatu2.ukuran = 44;
                                    namaSepatu2.harga = 1800000;
                                    break;
                                case 4:
                                    namaSepatu2.namaSepatu = "AE 1 LOW SHOES";
                                    namaSepatu2.tanggalRilis = "2022-10-10";
                                    namaSepatu2.ukuran = 42.5;
                                    namaSepatu2.harga = 1500000;
                                    break;
                                case 5:
                                    namaSepatu2.namaSepatu = "ADIZERO SELECT 2.0 SHOES";
                                    namaSepatu2.tanggalRilis = "2023-02-20";
                                    namaSepatu2.ukuran = 41;
                                    namaSepatu2.harga = 1900000;
                                    break;
                                default:
                                    cout << "Pilihan tidak valid" << endl;
                                    continue;
                                }
                                pushBarang(namaSepatu2);
                                cout << "Apakah anda ingin memilih lagi? (y/t): ";
                                cin >> yakin;
                            } while (yakin == 'y' || yakin == 'Y');
                            cout << "Silahkan Melakukan Pembayaran" << endl;
                            break;
                        case 3:
                            int ketiga;
                            cout << "================================" << endl;
                            cout << "       DAFTAR SEPATU RUNNING     " << endl;
                            cout << "================================" << endl;
                            cout << "| 1.|SUPERNOVA EARTH DAY SHOES    |" << endl;
                            cout << "| 2.|ADIZERO TAKUMI SEN 10        |" << endl;
                            cout << "| 3.|ADIZERO SL                   |" << endl;
                            cout << "| 4.|ULTRABOOST LIGHT             |" << endl;
                            cout << "| 5.|PUREBOOST 23                 |" << endl;
                            cout << "| 6.|ADIZERO ADIOS PRO 3 M        |" << endl;
                            cout << "| 7.|ADIZERO PRIME X 2.0 STRUNG   |" << endl;
                            cout << "| 8.|ADIZERO BOSTON 12            |" << endl;
                            cout << "================================" << endl;
                            do
                            {
                                cout << "Pilih Sepatu Anda (1/2/3/4/5): ";
                                cin >> ketiga;
                                if (ketiga < 1 || ketiga > 5)
                                {
                                    cout << "Pilihan tidak valid, keluar dari menu sepatu." << endl;
                                    break;
                                }
                                Sepatu namaSepatu2;
                                switch (ketiga)
                                {
                                case 1:
                                    namaSepatu2.namaSepatu = "SUPERNOVA EARTH DAY SHOES";
                                    namaSepatu2.tanggalRilis = "2023-12-14";
                                    namaSepatu2.ukuran = 42;
                                    namaSepatu2.harga = 2200000;
                                    break;
                                case 2:
                                    namaSepatu2.namaSepatu = "ADIZERO TAKUMI SEN 10";
                                    namaSepatu2.tanggalRilis = "2024-02-22";
                                    namaSepatu2.ukuran = 43;
                                    namaSepatu2.harga = 3200000;
                                    break;
                                case 3:
                                    namaSepatu2.namaSepatu = "ADIZERO SL";
                                    namaSepatu2.tanggalRilis = "2024-01-05";
                                    namaSepatu2.ukuran = 44;
                                    namaSepatu2.harga = 2000000;
                                    break;
                                case 4:
                                    namaSepatu2.namaSepatu = "ULTRABOOST LIGHT";
                                    namaSepatu2.tanggalRilis = "2024-01-10";
                                    namaSepatu2.ukuran = 42.5;
                                    namaSepatu2.harga = 3300000;
                                    break;
                                case 5:
                                    namaSepatu2.namaSepatu = "PUREBOOST 23";
                                    namaSepatu2.tanggalRilis = "2024-02-20";
                                    namaSepatu2.ukuran = 41;
                                    namaSepatu2.harga = 2100000;
                                    break;
                                case 6:
                                    namaSepatu2.namaSepatu = "ADIZERO ADIOS PRO 3 M";
                                    namaSepatu2.tanggalRilis = "2024-02-27";
                                    namaSepatu2.ukuran = 41;
                                    namaSepatu2.harga = 4000000;
                                    break;
                                case 7:
                                    namaSepatu2.namaSepatu = "ADIZERO PRIME X 2.0 STRUNG";
                                    namaSepatu2.tanggalRilis = "2024-02-20";
                                    namaSepatu2.ukuran = 41;
                                    namaSepatu2.harga = 4300000;
                                    break;
                                case 8:
                                    namaSepatu2.namaSepatu = "SEPATU ADIZERO BOSTON 12";
                                    namaSepatu2.tanggalRilis = "2024-03-22";
                                    namaSepatu2.ukuran = 41;
                                    namaSepatu2.harga = 2300000;
                                    break;    
                                default:
                                    cout << "Pilihan tidak valid" << endl;
                                    continue;
                                }
                                pushBarang(namaSepatu2);
                                cout << "Apakah anda ingin memilih lagi? (y/t): ";
                                cin >> yakin;
                            } while (yakin == 'y' || yakin == 'Y');
                            cout << "Silahkan Melakukan Pembayaran" << endl;
                            break;
                        case 4:

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
                    listSepatu();
                    break;
                case 4:
                    cout << "=========================" << endl;
                    cout << "     Menu Pembayaran     " << endl;
                    cout << "=========================" << endl;
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
