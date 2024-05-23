#include <iostream>
#include <iomanip>
#include <ctime>
using namespace std;

const string username = "admin";
const string password = "admin123";
extern void tampilanPembelian();
extern void tampilkanDataPembeli();
time_t now = time(0);
tm *ltm = localtime(&now);

void loginAdmin()
{
    string usernameInput, passwordInput;
    bool sukses = false;
    int kesempatan = 0;
    int pilih;
    int totalHarga = 0; 

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
            cout<<endl;
            sukses = true;

            do{
            cout << "==============================================" << endl;
            cout << "|                MENU ADMIN                  |" << endl;
            cout << "==============================================" << endl;
            cout << "| 1.| Daftar Pemasukan Harian                |" << endl;
            cout << "| 2.| Keuntungan Harian                      |" << endl;                             
            cout << "| 0.| Keluar                                 |" << endl;
            cout << "==============================================" << endl;
            cout << "Silahkan pilih menu: ";
            cin >> pilih;
            switch (pilih)
            {
            case 1:
                cout << "----------------------------------------------------------------\n";
                cout << setfill('0') << setw(2) << ltm->tm_mday << "/" << setfill('0') << setw(2) << 1 + ltm->tm_mon << "/" << 1900 + ltm->tm_year << endl;
                cout << "                       DATA PEMBELIAN SEPATU\n";
                cout << "\n";
                cout << "----------------------------------------------------------------\n";
                cout << " No.    Nama Sepatu      Tanggal Rilis     Ukuran      Harga\n";
                cout << "----------------------------------------------------------------\n";
                tampilkanDataPembeli();
                cout << "----------------------------------------------------------------\n";
                continue;
            case 2:
                cout << "Total Harga                                          " << totalHarga << endl;
                continue;
            
            default:
                cout << "Pilihan anda salah, silahkan coba lagi..." << endl;
                continue;
            }
            } while(pilih < 0 || pilih > 2);
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
