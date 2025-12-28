#include <iostream>
#include <string>

using namespace std;

int main() {
    int pilihan;
    string namaMenu;
    int jumlah;
    double hargaSatuan;

    string identitasPembeli;
    string alamatPembeli;
    char statusMember;

    cout << "========================================" << endl;
    cout << "       SISTEM PEMESANAN MAKANAN         " << endl;
    cout << "========================================" << endl;
    cout << "Pilih Jenis Pesanan:" << endl;
    cout << "1. Pesanan Langsung" << endl;
    cout << "2. Pesanan Pickup" << endl;
    cout << "Masukkan pilihan (1/2): ";
    cin >> pilihan;
    cin.ignore();

    if (pilihan == 1) {
        cout << "--- Input Data Pesanan Langsung ---" << endl;
        cout << "Masukkan Nama: ";
        getline(cin, namaMenu);
    } else if (pilihan == 2) {
        cout << "--- Input Data Pesanan Pickup ---" << endl;
        cout << "Masukkan Identitas Pembeli (Nama/No.HP): ";
        getline(cin, identitasPembeli);
        cout << "Masukkan Alamat Pembeli: ";
        getline(cin, alamatPembeli);
    } else {
        cout << "Pilihan tidak valid." << endl;
        return 0;
    }

    cout << "Selamat Anda Telah Terdaftar di Tempat Kami" << endl;

    cout << "--- Cek Keanggotaan ---" << endl;
    cout << "Apakah pelanggan adalah Member? (y/n): ";
    cin >> statusMember;

    cout << "========================================" << endl;
    cout << "         HASIL PENENTUAN HARGA          " << endl;
    cout << "========================================" << endl;

    if (pilihan == 2) {
        cout << "Pemesan : " << identitasPembeli << endl;
        cout << "Alamat  : " << alamatPembeli << endl;
    }

    if (statusMember == 'y' || statusMember == 'Y') {
        cout << "Status  : MEMBER" << endl;
        cout << "Info    : Selamat Anda Mendapatkan Diskon Member Sebesar 10%" << endl;
    } else {
        cout << "Status  : NON-MEMBER" << endl;
        cout << "Info    : Anda Tidak Mendapatkan Potongan Diskon Member" << endl;
    }

    cout << "Terima kasih!" << endl;

    return 0;
}
