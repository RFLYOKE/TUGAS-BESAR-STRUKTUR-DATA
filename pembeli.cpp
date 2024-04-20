#include <iostream>
#include "listSepatu.cpp"
using namespace std;

void loginPembeli(){
    string username, password, usernameLogin, passwordLogin;
    int maksimal = 0; 
    bool loginSukses = false;

    // login pembeli
    cout << "=============================================" << endl;
    cout << "                HELLO FRIENDS!               " << endl;
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

            int pilih;
            cout << "====================================" << endl;
            cout << "|           MENU PEMBELI            |" << endl;
            cout << "| 1.| List Sepatu Tersedia          |" << endl;
            cout << "| 2.| Pembelian Sepatu              |" << endl;
            cout << "| 3.| Rekapan Pembelian             |" << endl;
            cout << "| 4.| Keluar                        |" << endl;
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
                cout << "| 5.| Keluar                        |" << endl;
                cout << "====================================" << endl;
                cout << "Silahkan pilih kategori anda: ";
                cin >> pilihanku;
                cout << endl;
                switch (pilihanku)
                {
                case 1:
                    listSepatu();
                    break;
                case 2:
                    listSepatu();
                    break;
                case 3:
                    listSepatu();
                    break;
                case 4:
                    listSepatu();
                    break;
                case 5:
                    cout << "-----KELUAR-----\n";
                    break;
                default:
                    cout << "Pilihan yang anda masukkan salah, coba lagi \n";
                    break;
                }
            }
            else if (pilih == 2)
            {

            }
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

