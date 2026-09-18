#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N, K;

    // 1. Input nilai N dan K
    cout << "Masukkan jumlah astronot (N): ";
    cin >> N;
    cout << "Masukkan nilai awal K: ";
    cin >> K;

    // 2. Buat daftar astronot nomor 1 sampai N pakai vector
    vector<int> astronot;
    for (int i = 1; i <= N; i++) {
        astronot.push_back(i);
    }

    int posisi = 0; // Indeks mulai dari 0

    cout << "\n--- Proses Eliminasi ---" << endl;

    // 3. Perulangan selama sisa astronot lebih dari 1
    while (astronot.size() > 1) {

        // Hitung posisi astronot yang kena eliminasi
        posisi = (posisi + K - 1) % astronot.size();

        // Ambil nomor astronot yang dieliminasi
        int dieliminasi = astronot[posisi];
        cout << "Astronot dieliminasi: " << dieliminasi << endl;

        // Hapus astronot dari daftar
        astronot.erase(astronot.begin() + posisi);

        // Aturan ubah nilai K berdasarkan nomor yang dieliminasi
        if (dieliminasi % 2 == 0) {
            K = K + 2; // Jika nomor GENAP
        } else {
            K = K - 1; // Jika nomor GANJIL
        }

        // Aturan batas minimal K
        if (K < 2) {
            K = 2;
        }
    }

    // 4. Tampilkan astronot terakhir yang tersisa
    cout << "\n=================================" << endl;
    cout << "Astronot terakhir yang bertahan: " << astronot[0] << endl;
    cout << "=================================" << endl;

    return 0;
}