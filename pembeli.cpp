#include <iostream>
using namespace std;

void loginPembeli(){
    string username, password;

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
    
    string usernameLogin, passwordLogin;
    bool loginSuccess = false;
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
            loginSuccess = true;
        } else {
            cout << "Username atau Password salah, silahkan coba lagi." << endl;
        }
    } while (!loginSuccess);
}