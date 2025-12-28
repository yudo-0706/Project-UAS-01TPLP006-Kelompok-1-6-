#include <iostream>
#include <string>
using namespace std;

/* =====================================================
   1. FLOWCHART PENGELOLAAN KANTIN
   ===================================================== */
void pengelolaanKantin() {
    cout << "\n==== PENGELOLAAN KANTIN ====\n";

    // S1
    cout << "S1: Tugas Harian: Kebersihan, Stok Bahan, Peralatan\n";

    // S2
    cout << "S2: Cek Kebersihan Kantin\n";
    cout << "- Membersihkan meja, kursi, lantai\n";

    // S3
    cout << "S3: Cek Ketersediaan Bahan Makanan\n";
    cout << "- Memeriksa: sayur, daging, bumbu, minuman\n";

    int kondisi;
    cout << "Apakah bahan masih layak? (1 = Tidak layak / 2 = Layak): ";
    cin >> kondisi;

    // IF kondisi bahan
    if (kondisi == 1) {
        cout << "S4: Bahan rusak ? Buang dan ganti bahan baru.\n";
    } else if (kondisi == 2) {
        cout << "S5: Bahan masih aman ? Lanjut proses.\n";
    }

    // S6
    cout << "S6: Siapkan menu harian dan peralatan.\n";
    cout << "==== PROSES SELESAI ====\n\n";
}

/* =====================================================
   2. FLOWCHART PEMESANAN MAKANAN (DENGAN HARGA)
   ===================================================== */
void pemesananKantin() {
    cout << "\n==== PEMESANAN MAKANAN KANTIN ====\n";

    char loop = 'y';
    int totalBelanja = 0;   // <-- total harga semua pesanan

    // S1: Menampilkan Menu
    cout << "S1: Menampilkan Menu Kantin\n";
    cout << "1. Makanan Berat (Rp 12.000 per porsi)\n";
    cout << "2. Makanan Ringan (Rp 5.000 per item)\n";
    cout << "3. Aneka Minuman (Rp 4.000 per gelas)\n";

    do {
        int pilihan;
        cout << "\nS2: Masukkan Pilihan (1/2/3): ";
        cin >> pilihan;

        if (pilihan == 1) {
            // S3
            int porsi;
            cout << "S3: Makanan Berat\n";
            cout << "Input jumlah porsi: ";
            cin >> porsi;

            int harga = porsi * 12000;   // harga makanan berat
            cout << "Harga: Rp " << harga << endl;

            totalBelanja += harga;
        }
        else if (pilihan == 2) {
            // S4
            string snack;
            int jumlah;
            cout << "S4: Makanan Ringan\n";
            cin >> snack;
            cout << "Input jumlah: ";
            cin >> jumlah;

            int harga = jumlah * 5000;   // harga snack
            cout << "Harga: Rp " << harga << endl;

            totalBelanja += harga;
        }
        else if (pilihan == 3) {
            // S5
            string minum;
            int jumlah;
            cout << "S5: Aneka Minuman\n";
            cin >> minum;
            cout << "Input jumlah: ";
            cin >> jumlah;

            int harga = jumlah * 4000;   // harga minuman
            cout << "Harga: Rp " << harga << endl;

            totalBelanja += harga;
        }
        else {
            cout << "Pilihan tidak valid.\n";
        }

        // S6
        cout << "S6: Ingin pesan lagi? (y/t): ";
        cin >> loop;

    } while (loop == 'y' || loop == 'Y');

    cout << "\n==== TOTAL BELANJA ANDA: Rp " << totalBelanja << " ====\n\n";
}

/* =====================================================
   3. FLOWCHART PEMBAYARAN KANTIN
   ===================================================== */
void pembayaranKantin() {
    cout << "\n==== PEMBAYARAN KANTIN ====\n";

    // S1
    int totalHarga;
    cout << "S1: Masukkan total harga pesanan: ";
    cin >> totalHarga;

    // S2
    int metode;
    cout << "S2: Pilih metode pembayaran:\n";
    cout << "1. Tunai\n";
    cout << "2. QRIS\n";
    cout << "3. E-wallet\n";
    cout << "Pilihan: ";
    cin >> metode;

    // S3
    float jumlahUang;
    cout << "S3: Masukkan jumlah uang / konfirmasi pembayaran: ";
    cin >> jumlahUang;

    // IF STATUS
    if (jumlahUang >= totalHarga) {
        cout << "S4: Pembayaran berhasil.\n";
    } else {
        cout << "S5: Pembayaran gagal. Ulangi pembayaran.\n";
        return pembayaranKantin(); // rekursif ulang pembayaran
    }

    // S6
    cout << "S6: Cetak/Tampilkan Struk.\n";
    cout << "==== TRANSAKSI SELESAI ====\n\n";
}

/* =====================================================
   MAIN PROGRAM
   ===================================================== */
int main() {
    int menu;

    do {
        cout << "=============================\n";
            cout << " SISTEM KANTIN SDN PANCORAN 10\n";
        cout << "=============================\n";
        cout << "1. Pengelolaan Kantin\n";
        cout << "2. Pemesanan Makanan\n";
        cout << "3. Pembayaran\n";
        cout << "4. Keluar\n";
        cout << "Pilih menu: ";
        cin >> menu;

        switch (menu) {
            case 1:
                pengelolaanKantin();
                break;
            case 2:
                pemesananKantin();
                break;
            case 3:
                pembayaranKantin();
                break;
            case 4:
                cout << "Program selesai.\n";
                break;
            default:
                cout << "Menu tidak valid.\n";
        }

    } while (menu != 4);

    return 0;
}
