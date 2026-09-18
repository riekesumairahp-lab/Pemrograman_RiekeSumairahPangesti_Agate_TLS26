#include <iostream>
#include <string>

using namespace std;

int main() {
    string pesan_asli;
    string pesan_sandi = "";

    // 1. Input pesan dari user
    cout << "Masukkan pesan asli (huruf kapital): ";
    cin >> pesan_asli;

    // 2. Huruf pertama tidak berubah
    pesan_sandi = pesan_sandi + pesan_asli[0];

    // 3. Loop dari huruf kedua (indeks 1) sampai huruf terakhir
    for (int i = 1; i < pesan_asli.length(); i++) {

        // Hitung nilai geser berdasarkan huruf sebelumnya (A=1, B=2, dst.)
        int nilai_geser = pesan_asli[i - 1] - 'A' + 1;

        // Geser huruf sekarang
        char huruf_baru = pesan_asli[i] + nilai_geser;

        // Jika hasil pergeseran melewati huruf 'Z', putar balik ke 'A'
        if (huruf_baru > 'Z') {
            huruf_baru = huruf_baru - 26;
        }

        // Simpan huruf baru ke pesan sandi
        pesan_sandi = pesan_sandi + huruf_baru;
    }

    // 4. Cetak hasil sandi
    cout << "Hasil pesan sandi: " << pesan_sandi << endl;

    return 0;
}