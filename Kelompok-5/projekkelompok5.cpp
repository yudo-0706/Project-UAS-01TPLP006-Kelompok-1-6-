#include <iostream>
#include <ctime>
#include <cstdlib>
#include <string>
using namespace std;

// ================================================================
//                 PROGRAM RESTORAN – ALL IN ONE
// ================================================================

// ================================================================
//                  BAGIAN A – PEMESANAN MENU
// ================================================================
void programPemesanan(int &stokAyam, int &stokUdang, int &stokKerang,
                      int &stokEsTeh, int &stokEsJeruk) {
    int pilih, jumlah;

    do {
        cout << "\n=== MENU RESTORAN ===\n";
        cout << "1. Ayam Goreng (stok: " << stokAyam << ")\n";
        cout << "2. Udang (stok: " << stokUdang << ")\n";
        cout << "3. Kerang (stok: " << stokKerang << ")\n";
        cout << "4. Es Teh (stok: " << stokEsTeh << ")\n";
        cout << "5. Es Jeruk (stok: " << stokEsJeruk << ")\n";
        cout << "6. Kembali ke Menu Utama\n";
        cout << "Pilih menu: ";
        cin >> pilih;

        if (pilih >= 1 && pilih <= 5) {
            cout << "Masukkan jumlah: ";
            cin >> jumlah;

            int *stokMenu = nullptr;

            if (pilih == 1) stokMenu = &stokAyam;
            if (pilih == 2) stokMenu = &stokUdang;
            if (pilih == 3) stokMenu = &stokKerang;
            if (pilih == 4) stokMenu = &stokEsTeh;
            if (pilih == 5) stokMenu = &stokEsJeruk;

            if (*stokMenu >= jumlah) {
                *stokMenu -= jumlah;
                cout << "Pesanan berhasil! Stok tersisa: " << *stokMenu << endl;
            } else {
                cout << "Stok tidak cukup!\n";
            }

            // Restock otomatis jika stok < 3
            if (*stokMenu < 3) {
                cout << "Stok rendah! Melakukan restock...\n";
                *stokMenu += 10;
                cout << "Stok baru: " << *stokMenu << endl;
            }
        }
    } while (pilih != 6);
}

// ================================================================
//                BAGIAN B – MENGELOLA / CEK BAHAN BAKU
// ================================================================
void programCekBahanBaku(int stokAyam, int stokUdang, int stokKerang,
                         int stokEsTeh, int stokEsJeruk) {
    int pilih;

    cout << "\n=== CEK BAHAN BAKU ===\n";
    cout << "1. Ayam Goreng (stok: " << stokAyam << ")\n";
    cout << "2. Udang (stok: " << stokUdang << ")\n";
    cout << "3. Kerang (stok: " << stokKerang << ")\n";
    cout << "4. Es Teh (stok: " << stokEsTeh << ")\n";
    cout << "5. Es Jeruk (stok: " << stokEsJeruk << ")\n";
    cout << "Pilih bahan yang ingin dicek: ";
    cin >> pilih;

    int stokDipilih = 0;
    string nama;

    switch(pilih) {
        case 1: stokDipilih = stokAyam; nama = "Ayam"; break;
        case 2: stokDipilih = stokUdang; nama = "Udang"; break;
        case 3: stokDipilih = stokKerang; nama = "Kerang"; break;
        case 4: stokDipilih = stokEsTeh; nama = "Es Teh"; break;
        case 5: stokDipilih = stokEsJeruk; nama = "Es Jeruk"; break;
        default: cout << "Pilihan tidak valid!\n"; return;
    }

    cout << "\nStok " << nama << ": " << stokDipilih << endl;

    if (stokDipilih > 0)
        cout << "Status: Stok Mencukupi\n";
    else
        cout << "Status: Stok Habis!\n";
}

// ================================================================
//                    BAGIAN C – PEMBAYARAN
// ================================================================
void programPembayaran() {
    int ayam, udang, kerang, esTeh, esJeruk;

    cout << "\n=== INPUT JUMLAH PESANAN UNTUK PEMBAYARAN ===\n";
    cout << "Ayam Goreng: "; cin >> ayam;
    cout << "Udang      : "; cin >> udang;
    cout << "Kerang     : "; cin >> kerang;
    cout << "Es Teh     : "; cin >> esTeh;
    cout << "Es Jeruk   : "; cin >> esJeruk;

    int total =
        ayam * 15000 +
        udang * 18000 +
        kerang * 12000 +
        esTeh * 5000 +
        esJeruk * 6000;

    cout << "\nTOTAL: Rp " << total << endl;

    int bayar;
    cout << "Masukkan pembayaran: Rp ";
    cin >> bayar;

    while (bayar < total) {
        cout << "Uang kurang! Masukkan lagi: Rp ";
        cin >> bayar;
    }

    int kembali = bayar - total;

    cout << "\n=== STRUK PEMBAYARAN ===\n";
    cout << "Total     : Rp " << total << endl;
    cout << "Bayar     : Rp " << bayar << endl;
    cout << "Kembalian : Rp " << kembali << endl;
}

// ================================================================
//                     PROGRAM UTAMA (MAIN MENU)
// ================================================================
int main() {
    srand(time(0));

    int stokAyam   = 5 + rand() % 10;
    int stokUdang  = 5 + rand() % 10;
    int stokKerang = 5 + rand() % 10;
    int stokEsTeh  = 5 + rand() % 10;
    int stokEsJeruk = 5 + rand() % 10;

    int pilih;

    do {
        cout << "\n==============================\n";
        cout << "       PROGRAM RESTO\n";
        cout << "==============================\n";
        cout << "1. Pemesanan Menu\n";
        cout << "2. Cek Bahan Baku\n";
        cout << "3. Pembayaran\n";
        cout << "4. Keluar\n";
        cout << "Pilih menu: ";
        cin >> pilih;

        if (pilih == 1)
            programPemesanan(stokAyam, stokUdang, stokKerang, stokEsTeh, stokEsJeruk);
        else if (pilih == 2)
            programCekBahanBaku(stokAyam, stokUdang, stokKerang, stokEsTeh, stokEsJeruk);
        else if (pilih == 3)
            programPembayaran();

    } while (pilih != 4);

    cout << "Program selesai.\n";
    return 0;
}
