#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

const double TARIF_PAKAIAN_KG = 7000.0;
const double TARIF_NON_PAKAIAN = 10000.0;
const double DISKON_MEMBER_RATE = 0.10;

int main() {
    int jenisBarang;
    double jumlahSatuan;
    double biayaDasar;
    double biayaAkhir;
    char isMemberInput;
    string waktuPengerjaan;
    string jenisPengerjaan;

    cout << "============================================" << endl;
    cout << "  SISTEM PERHITUNGAN LAUNDRY (Flowchart)    " << endl;
    cout << "============================================" << endl;

    cout << "Pilih Jenis Barang:" << endl;
    cout << "1. Pakaian (Tarif Rp 7.000 per satuan)" << endl;
    cout << "2. Non-Pakaian (Tarif Rp 10.000 per satuan)" << endl;
    cout << "Masukkan pilihan (1/2): ";

    if (!(cin >> jenisBarang)) {
        cerr << "Error: Input harus berupa angka." << endl;
        return 1;
    }

    cout << "Masukkan Jumlah Satuan Barang: ";
    if (!(cin >> jumlahSatuan)) {
        cerr << "Error: Input harus berupa angka." << endl;
        return 1;
    }

    if (jenisBarang == 1) {
        biayaDasar = jumlahSatuan * TARIF_PAKAIAN_KG;
        jenisPengerjaan = "Pakaian";
    } else if (jenisBarang == 2) {
        biayaDasar = jumlahSatuan * TARIF_NON_PAKAIAN;
        jenisPengerjaan = "Non-Pakaian";
    } else {
        cerr << "Pilihan jenis barang tidak valid (hanya 1 atau 2). Program berhenti." << endl;
        return 1;
    }

    if (jenisBarang == 1) {
        waktuPengerjaan = "2 Hari Kerja (Standar Pakaian)";
    } else {
        waktuPengerjaan = "3 Hari Kerja (Pengerjaan Khusus Non-Pakaian)";
    }

    cout << "Apakah pelanggan adalah Member? (y/n): ";
    cin >> isMemberInput;

    biayaAkhir = biayaDasar;
    double diskon = 0.0;

    if (isMemberInput == 'y' || isMemberInput == 'Y') {
        diskon = biayaDasar * DISKON_MEMBER_RATE;
        biayaAkhir = biayaDasar - diskon;
    }

    cout << "============================================" << endl;
    cout << "             STRUK PEMBAYARAN               " << endl;
    cout << "============================================" << endl;
    cout << "Jenis Barang        : " << jenisPengerjaan << endl;
    cout << "Jumlah Satuan       : " << jumlahSatuan << endl;
    cout << "Waktu Pengerjaan    : " << waktuPengerjaan << endl;
    cout << "--------------------------------------------" << endl;

    cout << "Biaya Dasar         : Rp " << fixed << setprecision(0) << biayaDasar << endl;

    if (isMemberInput == 'y' || isMemberInput == 'Y') {
        cout << "Status Member       : YA" << endl;
        cout << "Diskon (" << (DISKON_MEMBER_RATE * 100) << "%)      : Rp " << fixed << setprecision(0) << diskon << endl;
    } else {
        cout << "Status Member       : TIDAK" << endl;
        cout << "Diskon              : Rp 0" << endl;
    }

    cout << "--------------------------------------------" << endl;
    cout << "TOTAL BAYAR         : Rp " << fixed << setprecision(0) << biayaAkhir << endl;
    cout << "============================================" << endl;

    return 0;
}
