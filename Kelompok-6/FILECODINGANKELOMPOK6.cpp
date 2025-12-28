#include <iostream>
#include <string>
using namespace std;

// ===========================
// SUBBAB 1 : PEMESANAN
// ===========================
void pemesanan() {
    int jenisOrder;
    string namaMenu;
    int qty;

    cout << "\n=== PEMESANAN ===\n";
    cout << "Jenis Order:\n1. Dine-In\n2. Takeaway\n3. Online\n";
    cout << "Pilih (1-3): ";
    cin >> jenisOrder;

    cout << "Input nama menu: ";
    cin >> namaMenu;

    cout << "Jumlah: ";
    cin >> qty;

    // output ID/pager
    cout << "\nPesanan diterima!\n";

    if (jenisOrder == 1) {
        cout << "Output: Berikan Pager ke pelanggan.\n";
    }
    else if (jenisOrder == 2) {
        cout << "Output: Simpan nama pelanggan, panggil nama saat pesanan siap.\n";
    }
    else if (jenisOrder == 3) {
        cout << "Output: Cetak order untuk Kitchen & Bar.\n";
    }

    cout << "Pesanan akan diproses...\n";
}



// ===========================
// SUBBAB 2 : DINE-IN vs TAKEAWAY
// ===========================
void layanan() {
    int jenis;
    cout << "\n=== PERBEDAAN LAYANAN ===\n";
    cout << "1. Dine-In\n2. Takeaway\n";
    cout << "Pilih (1-2): ";
    cin >> jenis;

    if (jenis == 1) {
        cout << "Layanan Dine-In aktif.\n";
        cout << "Output: Pelanggan menunggu di meja, dipanggil dengan pager.\n";
    }
    else {
        cout << "Layanan Takeaway aktif.\n";
        cout << "Output: Pelanggan menunggu di kursi khusus, dipanggil dengan nama.\n";
    }
}



// ===========================
// SUBBAB 3 : SISTEM PEMBAYARAN
// ===========================
void pembayaran() {
    int pay;
    cout << "\n=== PEMBAYARAN ===\n";
    cout << "Metode pembayaran:\n1. Tunai\n2. QRIS\n3. Transfer\n";
    cout << "Pilih (1-3): ";
    cin >> pay;

    switch (pay) {
    case 1:
        cout << "Pembayaran tunai diterima.\n";
        break;
    case 2:
        cout << "QRIS diproses...\n";
        cout << "Jika pending/double ? lakukan refund manual.\n";
        break;
    case 3:
        cout << "Transfer diterima.\n";
        break;
    default:
        cout << "Metode tidak valid.\n";
    }

    cout << "Output: Bukti pembayaran diberikan.\n";
}



// ===========================
// MENU UTAMA
// ===========================
int main() {
    int menu;

    while (true) {
        cout << "\n===== SISTEM MIEGOGO =====\n";
        cout << "1. Pemesanan\n";
        cout << "2. Layanan Dine-In / Takeaway\n";
        cout << "3. Pembayaran\n";
        cout << "4. Keluar\n";
        cout << "Pilih menu (1-4): ";
        cin >> menu;

        if (menu == 1) pemesanan();
        else if (menu == 2) layanan();
        else if (menu == 3) pembayaran();
        else if (menu == 4) break;
        else cout << "Menu tidak valid.\n";
    }

    return 0;
}
