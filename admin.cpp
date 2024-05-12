#include <iostream>
using namespace std;

const string username = "admin";
const string password = "admin123";
const int maximal = 100;
string inputan;

struct Sepatuu
{
    string namaSepatu;
    string tanggalRilis;
    float ukuran;
    int harga;
};

struct stock{
    int posisi;
    Sepatuu data[maximal];
}tumpukan;

void inisialisasiAdmin(){
    tumpukan.posisi = -1;
}

bool stockKosong(){
    if(tumpukan.posisi==-1){
        return true;
    }else{
        return false;
    }
}

bool stockPenuh(){
    if(tumpukan.posisi==maximal-1){
        return true;
    }else{
        return false;
    }
}

void pushData(Sepatuu inputan){
    if(stockPenuh()==false){
        tumpukan.posisi++;
        tumpukan.data[tumpukan.posisi]=inputan;
        cout<<"Berhasil Menambahkan Sepatu [ "<<inputan.namaSepatu<<" ] ke dalam daftar stock"<<endl;
        cout<<"Tanggal Rilis: "<<inputan.tanggalRilis<< ", Ukuran: "<<inputan.ukuran<<", Harga: "<<inputan.harga<<endl;
    }else if(stockKosong()==true){
        tumpukan.posisi++;
        tumpukan.data[tumpukan.posisi]=inputan;
        cout<<"Berhasil Menambahkan Sepatu [ "<<inputan.namaSepatu<<" ] ke dalam daftar stock"<<endl;
        cout<<"Tanggal Rilis: "<<inputan.tanggalRilis<< ", Ukuran: "<<inputan.ukuran<<", Harga: "<<inputan.harga<<endl;
    }else{
        cout<<"List Sepatu Sudah Penuh"<<endl;
    }
}

void popData(){
    if(stockKosong()==false){
        tumpukan.posisi--;
        cout<<"Data stock sepatu berhasil dihapus "<<endl;
    }else{
        cout<<"Tidak ada data sepatu "<<endl;
    }
}

void tampil(){
    if(stockKosong()==true){
        cout<<"Tidak ada data sepatu "<<endl;
    }else{
        for(int c=0; c>=tumpukan.posisi; c--){
            cout<<c<<". "<<tumpukan.data[c].namaSepatu<<" "<<tumpukan.data[c].tanggalRilis<<" "<<tumpukan.data[c].ukuran<<" "<<tumpukan.data[c].harga<<endl;

        }
    }
}

void menuAdmin(){
                cout << "====================================" << endl;
                cout << "|           MENU ADMIN              |" << endl;
                cout << "====================================" << endl;
                cout << "| 1.| List Sepatu Tersedia          |" << endl;
                cout << "| 2.| Tambah Daftar Sepatu          |" << endl;
                cout << "| 3.| Edit Daftar Sepatu            |" << endl;
                cout << "| 4.| Hapus Daftar Sepatu           |" << endl;
                cout << "| 0.| Keluar                        |" << endl;
                cout << "====================================" << endl;       
}

void SepatuBola(){
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
}

void sepatuBasket(){
    cout << "================================" << endl;
    cout << "       DAFTAR SEPATU BASKET     " << endl;
    cout << "================================" << endl;
    cout << "| 1.|FORUM LOW SHOES            |" << endl;
    cout << "| 2.|SEPATU RIVALRY 86 LOW      |" << endl;
    cout << "| 3.|D.O.N. ISSUE 5 TRAINERS    |" << endl;
    cout << "| 4.|AE 1 LOW SHOES             |" << endl;
    cout << "| 5.|ADIZERO SELECT 2.0 SHOES   |" << endl;
    cout << "================================" << endl;
}

void sepatuRunning(){
    cout << "=================================" << endl;
    cout << "       DAFTAR SEPATU RUNNING     " << endl;
    cout << "=================================" << endl;
    cout << "| 1.|SEPATU SAMBA OG            |" << endl;
    cout << "| 2.|ADIDAS N BAPE              |" << endl;
    cout << "| 3.|GAZELLE LOW TRAINERS       |" << endl;
    cout << "| 4.|SAMBA XYZ SHOEAS           |" << endl;
    cout << "| 5.|LONDON SHOES               |" << endl;
    cout << "| 6.|SL 72 RS SHOES             |" << endl;
    cout << "================================" << endl;
}

void sepatuOri(){
    cout << "================================" << endl;
    cout << "       DAFTAR SEPATU ORIGINAL   " << endl;
    cout << "================================" << endl;
    cout << "| 1. |SEPATU SAMBA OG          |" << endl;
    cout << "| 2. |ABIBAS_N_BAPE            |" << endl;
    cout << "| 3. |SAMBA XLG SHOES          |" << endl;
    cout << "| 4. |LONDON SHOES             |" << endl;
    cout << "| 5. |GAZELLE 85 SHOES         |" << endl;
    cout << "================================" << endl;
}



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
            cout<<endl;
            sukses = true;
            int pil;
            do{
                menuAdmin();
                cout << "Silahkan masukkan pilihan anda: ";
                cin>>pil;
                switch(pil){
                    case 1:
                        int pilkategori;
                        do{
                        cout << "====================================" << endl;
                        cout << "|             KATEGORI              |" << endl;
                        cout << "| 1.| Sepatu Sepak Bola             |" << endl;
                        cout << "| 2.| Sepatu Basket                 |" << endl;
                        cout << "| 3.| Sepatu Running                |" << endl;
                        cout << "| 4.| Sepatu Original               |" << endl;
                        cout << "====================================" << endl;
                        cout << "Silahkan pilih kategori anda: ";
                        cin>>pilkategori;
                            switch(pilkategori){
                                case 1:
                                SepatuBola();
                                break;
                                case 2:
                                sepatuBasket();
                                break;
                                case 3:
                                sepatuRunning();
                                break;
                                case 4:
                                sepatuOri();
                                break;
                                default:
                                cout<<"Pilihan yang anda masukkan salah, coba lagi\n";
                                break;

                            }
                        }while(pilkategori <1 || pilkategori> 5);
                    break;
                    case 2: cout<<"t"<<endl;
                    break;
                    case 3: cout<<"r"<<endl;
                    break;
                    case 4: cout<<"t"<<endl;
                    break;
                    case 0:
                    cout<<"---KELUAR----\n"<<endl;
                    break;
                    default:
                    cout<<"Pilihan yang anda masukkan salah \n";
                    cout<<"---KELUAR---\n";
                    break;
                }
            }while(pil != 0);
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
