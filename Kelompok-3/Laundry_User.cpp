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

int main(){
    int berat_pakaian, Biaya, uang, kembalian;
    string pilihan, username;

        // S1
    cout<<"==SELAMAT DATANG=="<<endl;
    cout<<"Masukkan berat pakaian di Mesin Cuci (KG)= ";
    cin>> berat_pakaian;
    loading();
    cout<<"Berat pakaian terkonfirmasi..."<<endl;
        // S2
    Biaya = berat_pakaian * 5000;
        // S3
    cout<<"==Perhitungan Biaya=="<< endl;
    cout<<"Berat pakaian= "<<berat_pakaian<< endl;
    cout<<"Biaya per KG= 5000"<<endl;
    cout<<"Total biaya= "<<Biaya<<endl;
        // Do-while
    do
    {
         // S4
    cout<<"==Silahkan masukkan nama pelanggan dan uang pembayaran=="<<endl;
    cout<<"Nama Pelanggan = ";
    cin>> username;
    cout<<"Uang Dimasukkan= ";
    cin>> uang;
        // IF
    if (uang >= Biaya)
    {
        // S5
    kembalian = uang - Biaya;
        // S6
    cout<<"Berikut kembalian Anda= "<<kembalian<<endl;
        // S7
    cout<<"==Silahkan berikan Deterjen=="<<endl;
    cout<<"(tekan enter)"<<endl;
    cin.ignore();
    cin.get();
        // S8
    cout<<"Mesin sedang mencuci pakaian....";
    loading();
        // S9
    cout<<"Mesin sedang membilas....";
    loading();
        // S10
    cout<<"==Mesin Telah Selesai=="<<endl;
    cout<<"(tekan enter)";
    cin.ignore();
    cin.get();
        // S11
    cout<<"==Bon Anda=="<< endl;
    cout<<"Pelanggan= "<<username<<endl;
    cout<<"Uang dimasukkan= "<<uang<<endl;
    cout<<"Total Biaya pelayanan= "<<Biaya<<endl;
    cout<<"Kembalian anda= "<<kembalian<<endl;
    } else {
        // S12
    cout<<"Uang anda tidak cukup!"<< endl;
    }
    } while (uang < Biaya);
    
       
    
}