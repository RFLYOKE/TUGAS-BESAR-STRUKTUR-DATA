#include <iostream>
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
    cout << "Silahkan Masukkan Username dan Password anda" << endl;
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