#include <iostream>
#include <string>
#include <thread>
#include <chrono>
using namespace std;

// Kelompok 3
// -Arlene Sunny Xavier
// -ignatius Tirta
// -Reky Valentino
// -Angel Ajeng Gita Pratiwi
// -Laras Ayu Setyorini
// -Siti Fatimah Zahra

void Sleep_Seconds(int s){
    this_thread::sleep_for(chrono::seconds(s));
}

void loading(){
    Sleep_Seconds(0.7); cout<<".";
    Sleep_Seconds(0.7); cout<<" .";
    Sleep_Seconds(1); cout<<" ."<<endl;
}

struct mesin{
    string merk;
    string kode;
};

struct Mesin_rusak{
    string kode_rusak;
    string Kerusakan;
};


int main(){
    int pilihan, kembali;
    string Merk, Kode_Mesin, kerusakan;

        // S1
    cout<<"==Mesin sedang melakukan start up=="<<endl;
    loading();
        // S2
    cout<<"Seluruh Mesin dalam keadaan sehat"<<endl;
    cout<<"Silahkan tekan enter untuk pergi ke menu";
    cin.ignore();
    cin.get();

    do
    {
        // S3
    cout<<"== Selamat Datang Administrator == "<< endl;
    cout<<"1. Tambahkan mesin ke Inventaris"<<endl;
    cout<<"2. Lakukan Cek Mesin"<<endl;
    cout<<"3. Catat dan laporkan Kerusakan Mesin"<<endl;
    cout<<"4. Keluar Program"<<endl;
    cout<<endl;
    cout<<endl;
    cout<<"==Masukkan Pilihan (Gunakan nomor opsi)=="<<endl;
    cout<<"Pilihan Anda= ";
    cin>> pilihan;
        // SWITCH
        switch (pilihan)
        {
            // S4
            case 1:{
            mesin admin_input;
                cout<<"==Silahkan Masukkan data=="<<endl;
                cout<<"Merk Mesin= ";
                cin>> admin_input.merk;
                cout<<"Kode Mesin= ";
                cin>> admin_input.kode;
            // S5
                // Data telah dimasukkan ke struck mesin
                break;
        }
            // S6
            case 2:{
                cout<<"==Mesin sedang melakukan start up=="<<endl;
                loading();
            // S7
                cout<<"Seluruh Mesin dalam keadaan sehat"<<endl;
                break;
        }
            // S8
            case 3:{
            Mesin_rusak admin_input2;
                cout<<"==Silahkan Masukkan data=="<<endl;
                cout<<"kode Mesin= ";
                cin>> admin_input2.kode_rusak;
                cout<<"kerusakan= ";
                cin>> admin_input2.Kerusakan;
        // S9
                // data telah dimasukkan ke struck mesin_rusak
            break;
        }
            case 4:{
                cout << "Program dihentikan..." << endl;
                loading();
                return 0;
        }
    }
        // S10
        cout<<"Operasi Telah selesai"<<endl;
        loading(); 
        cout<<"==Kembali ke Menu=="<<endl;
        cout<<"1. Iya"<<endl;
        cout<<"2. Tidak"<<endl;
        cout<<"Pilihan Anda= ";
        cin>> kembali;
    } while (kembali == 1);
    
        
    }