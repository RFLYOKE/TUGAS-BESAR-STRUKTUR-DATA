#include <iostream>
#include <iomanip>
#include <ctime>
using namespace std;

const string username = "admin";
const string password = "admin123";
extern void tampilanPembelian();
extern void tampilkanDataPembeli();
extern void tampilWaktuTransaksi();
extern void loginUser();
time_t now = time(0);
tm *ltm = localtime(&now);

struct organisasi
{
    organisasi *left;
    string person;
    organisasi *right;
};



organisasi *root;

void strukturOrganisasi()
{
    root = new organisasi;
    root->person = " AKMAL RAFLY (CEO)";
    root->left = new organisasi;
    root->left->person = "NAZLY RAFFA (CTO)";
    root->right = new organisasi;
    root->right->person = "SETYO PRABOWO(CFO)";
    root->left->left = new organisasi;
    root->left->left->person = "OKTAVIAN (Lead Developer)";
    root->left->right = new organisasi;
    root->left->right->person = "ANOM SENJOYO (Lead Designer)";
    root->right->left = new organisasi;
    root->right->left->person = "NUZQU (Lead Finance)";
    root->right->right = new organisasi;
    root->right->right->person = "DZUNURAIN (Lead Marketing)";
}

void bacaorganisasi()
{
    if (root != NULL)
    {
        cout << endl;
        cout << "Struktur Organisasi:\n";
        cout << endl;
        cout <<"\t\t" << root->person << endl;
        cout << endl;
        cout << root->left->person << "\t" << root->right->person << endl;
        cout << endl;
        cout << root->left->left->person << "\t\t" << root->right->left->person << endl;
        cout << endl;
        cout << root->left->right->person << "\t\t" << root->right->right->person << endl;
        cout << endl;
    }
    else
    {
        cout << "Struktur organisasi belum diinisialisasi.\n";
    }
}

void loginAdmin()
{
    string usernameInput, passwordInput;
    bool sukses = false;
    int kesempatan = 0;
    int pilih;

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
            cout << "| 2.| Daftar Akun Login                      |" << endl;                             
            cout << "| 3.| Struktur Organisasi                    |" << endl;                             
            cout << "| 0.| Keluar                                 |" << endl;
            cout << "==============================================" << endl;
            cout << "Silahkan pilih menu: ";
            cin >> pilih;
            switch (pilih)
            {
            case 1:
                cout << "----------------------------------------------------------------\n";
                tampilWaktuTransaksi();
                cout << "                       DATA PEMBELIAN SEPATU\n";
                cout << "\n";
                cout << "----------------------------------------------------------------\n";
                cout << " No.    Nama Sepatu      Tanggal Rilis     Ukuran      Harga\n";
                cout << "----------------------------------------------------------------\n";
                tampilkanDataPembeli();
                cout << "----------------------------------------------------------------\n";
                continue;
            case 2:
                cout << "Daftar Akun Masuk: " << endl;
                loginUser();
                continue;
            case 3:
                strukturOrganisasi();
                bacaorganisasi();
                continue;
            case 0:
                cout << "Terima Kasih Admin Baik :)" << endl;
                break;
            default:
                cout << "Pilihan anda salah, silahkan coba lagi..." << endl;
                continue;
            }
            } while(pilih != 0);
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
