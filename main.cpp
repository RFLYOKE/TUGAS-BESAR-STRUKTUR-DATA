#include <iostream>
#include "pembeli.cpp"
#include "admin.cpp"

using namespace std;

int main(){
    int pilihanAnda;
    do
    {
        cout << "************************************" << endl;
        cout << "    Selamat Datang di Menu Login    " << endl;
        cout << "           TOKO SEPATU ABIBAS       " << endl;
        cout << "              PURWOKERTO            " << endl;
        cout << "************************************" << endl;
        cout << endl;

        cout << "====================================" << endl;
        cout << "|       SIAPAKAH DIRI ANDA?        |" << endl;
        cout << "| 1.| Pembeli                   |" << endl;
        cout << "| 2.| Admin                    |" << endl;
        cout << "====================================" << endl;
        cout << "Silahkan Pilih Siapa Anda [1/2] = ";
        cin >> pilihanAnda;
        cout << endl
             << endl;
        cin.ignore();

        if (pilihanAnda == 1)
        {
            
        }
        else if (pilihanAnda == 2)
        {
           cout<<"kikoo"<<endl;
        }
        else
        {
            cout << "Pilihan Anda Tidak Valid  :(" << endl;
            cout << "Mohon Coba Lagi..." << endl;
            cout << endl;
        }
    } while (pilihanAnda < 1 || pilihanAnda > 2);
    return 0;
}
