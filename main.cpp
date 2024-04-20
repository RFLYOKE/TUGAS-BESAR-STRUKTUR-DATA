#include <iostream>
#include "pembeli.cpp"
#include "admin.cpp"
#include "listSepatu.cpp"

using namespace std;

struct Sepatu{
    string namaSepatu;
    string tanggalRilis;
    float ukuran;
    double harga;
};

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
        cout << "| 1.| Pembeli                      |" << endl;
        cout << "| 2.| Admin                        |" << endl;
        cout << "====================================" << endl;
        cout << "Silahkan Pilih Siapa Anda [1/2] = ";
        cin >> pilihanAnda;
        cout << endl << endl;
        cin.ignore();

        if (pilihanAnda == 1)
        {
            loginPembeli();
        int pilih;    
        cout << "====================================" << endl;
        cout << "|           MENU PEMBELI            |" << endl;
        cout << "| 1.| List Sepatu Tersedia          |" <<endl;
        cout << "| 2.| Pembelian Sepatu              |" <<endl;
        cout << "| 3.| Rekapan Pembelian             |" <<endl;
        cout << "| 4.| Keluar                        |" <<endl;
        cout << "====================================" << endl;
        cout<<"Silahkan masukkan pilihan anda: ";    
        cin>>pilih;
        cout<<endl;    

        if(pilih==1){
            int pilihanku;
            cout << "====================================" << endl;
            cout << "|             KATEGORI              |" << endl;
            cout << "| 1.| Sepatu Sepak Bola             |" <<endl;
            cout << "| 2.| Sepatu Basket                 |" <<endl;
            cout << "| 3.| Sepatu Running                |" <<endl;
            cout << "| 4.| Sepatu Sekolah                |" <<endl;
            cout << "| 5.| Keluar                        |" <<endl;
            cout << "====================================" << endl;
            cout<<"Silahkan pilih kategori anda: ";
            cin>>pilihanku;
            cout<<endl;
            switch (pilihanku){
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
            cout<< "-----KELUAR-----\n";
                break;    
            default:
            cout<<"Pilihan yang anda masukkan salah, coba lagi \n";
                break;
            }
        }else if(pilih==2){

        }
            
        }
        else if (pilihanAnda == 2)
        {
            loginAdmin();
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
