#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h> // Library untuk mengukur waktu eksekusi

#define MAX_BUFFER 1000 // Ukuran buffer untuk membaca file

// Fungsi untuk menghitung jumlah kata dalam file
int hitungKata(FILE *file) {
    char buffer[MAX_BUFFER];
    int jumlahKata = 0;
    char *kata;

    // Membaca file baris per baris
    while (fgets(buffer, MAX_BUFFER, file) != NULL) {
        // Tokenisasi baris menjadi kata-kata
        kata = strtok(buffer, " \t\n");
        while (kata != NULL) {
            jumlahKata++; // Menambahkan jumlah kata
            kata = strtok(NULL, " \t\n");
        }
    }

    return jumlahKata;
}

int main() {
    FILE *file;
    char namaFile[100];
    int jumlahKata;
    clock_t start, end; // Untuk mengukur waktu
    double waktuEksekusi;

    // Meminta pengguna memasukkan nama file
    printf("Masukkan nama file: ");
    scanf("%s", namaFile);

    // Membuka file dengan mode read
    file = fopen(namaFile, "r");
    if (file == NULL) {
        printf("Gagal membuka file %s.\n", namaFile);
        return 1; // Keluar program jika file tidak ditemukan
    }

    // Mulai mengukur waktu
    start = clock();

    for (int i = 0; i < 1000; i++) {
        rewind(file); // Kembali ke awal file untuk setiap iterasi
        jumlahKata = hitungKata(file);
    }

    // Selesai mengukur waktu
    end = clock();

    // Menghitung waktu eksekusi dalam detik
    waktuEksekusi = (double)(end - start) / CLOCKS_PER_SEC;

    // Menutup file setelah selesai
    fclose(file);

    // Menampilkan hasil
    printf("Jumlah kata dalam file: %d\n", jumlahKata);
    printf("Waktu eksekusi: %.5f detik\n", waktuEksekusi);

    return 0;
}
