#include <iostream>
#include <string>
using namespace std;

// Data Menu
struct Menu {
    string kode;
    string nama;
    int harga;
    int stok;
};

// tampilan menu
Menu menu[10] = {
    {"01", "Kopi Gula Aren", 18000, 10},
    {"02", "Kopi Rawasi", 20000, 10},
    {"03", "Matcha Latte", 22000, 10},
    {"04", "Thai Tea", 15000, 10},
    {"05", "Es Teh Manis", 5000, 10},
    {"06", "Americano", 15000, 10},
    {"07", "Cappuccino", 25000, 10},
    {"08", "Kentang Goreng", 12000, 10},
    {"09", "Roti Bakar", 10000, 10},
    {"10", "Nasi Goreng", 28000, 10}
};

// Variabel laporan stock
int totalPendapatan = 0;
int totalItemTerjual = 0;

// Variabel umum
int pilih;
string kode;
int tambah;
int bayar;
int masuk;

// Variabel pemesanan
int jumlahPesanan[10] = {0};
int totalBelanja = 0;

int main() {
    while (true) {
        cout << "\n=== CAFE RAWASI EATERY ===\n";
        cout << "1. Pemesanan\n";
        cout << "2. Kelola Stok\n";
        cout << "3. Laporan Stok\n";
        cout << "4. Tukar Voucher\n";
        cout << "5. Keluar\n";
        cout << "Pilih menu: ";
        cin >> pilih;

        //------------------------------------------------------
        // 1. PEMESANAN
        //------------------------------------------------------

        if (pilih == 1) {
            // Reset setiap transaksi
            for (int i = 0; i < 10; i++) jumlahPesanan[i] = 0;
            totalBelanja = 0;
            // ===== Jenis Pemesanan =====
            int jenisPesanan;
            cout << "\n=== Pilih Jenis Pemesanan ===\n";
            cout << "1. Dine In\n";
            cout << "2. Take Away\n";
            cout << "Pilihan: ";
            cin >> jenisPesanan;
            string jenisText;
            int nomorMeja = 0;
            if (jenisPesanan == 1) {
                jenisText = "Dine In";
                cout << "Masukkan nomor meja: ";
                cin >> nomorMeja;
            }
            else if (jenisPesanan == 2) {
                jenisText = "Take Away";
            }
            else {
                jenisText = "Tidak diketahui";
            }

            // ===== Menampilkan Menu =====
            cout << "\n=== DAFTAR MENU ===\n";
            for (int i = 0; i < 10; i++) {
                cout << menu[i].kode << " - " << menu[i].nama
                     << " - Rp" << menu[i].harga
                     << " - stok: " << menu[i].stok << endl;
            }

            // ===== Looping Pemesanan =====
            string ulang = "y";
            while (ulang == "y" || ulang == "Y") {
                cout << "\nMasukkan Kode Menu: ";
                cin >> kode;
                bool ketemu = false;
                for (int i = 0; i < 10; i++) {
                    if (kode == menu[i].kode) {
                        ketemu = true;
                        if (menu[i].stok > 0) {
                            menu[i].stok--;
                            jumlahPesanan[i]++;
                            totalBelanja += menu[i].harga;
                            cout << menu[i].nama << " ditambahkan!\n";
                        } 
                        else {
                            cout << "Stok habis untuk " << menu[i].nama << endl;
                        }
                    }
                }
                if (!ketemu) {
                    cout << "Kode menu tidak ditemukan!\n";
                }
                cout << "Tambah pesanan lagi? (y/n): ";
                cin >> ulang;
            }

            // ===== STRUK =====
            cout << "\n=== STRUK PEMBELIAN ===\n";
            cout << "Jenis Pemesanan: " << jenisText << endl;
            if (jenisPesanan == 1) {
                cout << "Nomor Meja    : " << nomorMeja << endl;
            }
            cout << "\n--- Detail Pesanan ---\n";
            for (int i = 0; i < 10; i++) {
                if (jumlahPesanan[i] > 0) {
                    cout << menu[i].nama << " x" << jumlahPesanan[i]
                         << " = Rp" << menu[i].harga * jumlahPesanan[i] << endl;
                    totalItemTerjual += jumlahPesanan[i];
                }
            }
            cout << "TOTAL: Rp" << totalBelanja << endl;

            // ===== PEMBAYARAN =====
            bayar = 0;
            while (bayar < totalBelanja) {
                cout << "Bayar: Rp";
                cin >> masuk;
                bayar += masuk;
                if (bayar < totalBelanja) {
                    cout << "Kurang Rp" << totalBelanja - bayar << endl;
                }
            }
            cout << "Kembalian: Rp" << bayar - totalBelanja << endl;
            cout << "Terima kasih!\n";
            totalPendapatan += totalBelanja;
        }

        //------------------------------------------------------
        // 2. KELOLA STOK
        //------------------------------------------------------
        else if (pilih == 2) {
            cout << "\n=== UPDATE STOK ===\n";
            for (int i = 0; i < 10; i++) {
                cout << menu[i].kode << " - " << menu[i].nama
                     << " (stok: " << menu[i].stok << ")\n";
            }
            cout << "Masukkan kode menu: ";
            cin >> kode;
            for (int i = 0; i < 10; i++) {
                if (kode == menu[i].kode) {
                    cout << "Tambah stok berapa: ";
                    cin >> tambah;
                    menu[i].stok += tambah;
                    cout << "Stok baru: " << menu[i].stok << endl;
                }
            }
        }

        //------------------------------------------------------
        // 3. LAPORAN
        //------------------------------------------------------
        else if (pilih == 3) {
            cout << "\n=== LAPORAN ===\n";
            cout << "Total item terjual: " << totalItemTerjual << endl;
            cout << "Total pendapatan: Rp" << totalPendapatan << endl;
            cout << "\nSisa stok menu:\n";
            for (int i = 0; i < 10; i++) {
                cout << menu[i].kode << " - " << menu[i].nama
                     << " : " << menu[i].stok << endl;
            }
        }

        //------------------------------------------------------
        // 4. TUKAR VOUCHER
        //------------------------------------------------------
        else if (pilih == 4) {
            cout << "\n=== TUKAR VOUCHER ===\n";
            cout << "1. Voucher Futsal (min 1 jam)\n";
            cout << "2. Voucher Badminton (min 2 jam)\n";
            cout << "Pilihan: ";
            int v;
            cin >> v;
            if (v == 1) cout << "Anda mendapatkan minuman gratis: Es Teh Manis\n";
            else if (v == 2) cout << "Anda mendapatkan minuman gratis: Thai Tea\n";
            else cout << "Voucher tidak valid!\n";
        }

        //------------------------------------------------------
        // 5. KELUAR
        //------------------------------------------------------
        else if (pilih == 5) {
            cout << "Program selesai.\n";
            break;
        }
        else {
            cout << "Pilihan tidak ada!\n";
        }
    }
    return 0;
}