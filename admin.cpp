#include <iostream>
using namespace std;

const string username = "admin";
const string password = "admin123";

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