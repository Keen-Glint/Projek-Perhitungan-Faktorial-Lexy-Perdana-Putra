#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_BUFFER 10
#define MAX 500 // ukuran maksimal array yang menyimpan digit hasil perkalian

// Fungsi rekursif tunggal untuk menghitung faktorial
void recursiveFactorial(int num, int result[], int *size) {
    if (num == 1 || num == 0) {
        return; // Basis rekursi, berhenti di sini
    }

    // Panggil rekursi untuk angka lebih kecil
    recursiveFactorial(num - 1, result, size);

    // Sekarang kita simpan hasil perkalian num ke dalam result
    int carry = 0;
    for (int i = 0; i < *size; i++) {
        int temp = result[i] * num + carry;
        result[i] = temp % 10;  // Simpan digit terakhir
        carry = temp / 10;      // Simpan carry
    }

    // Jika ada carry yang tersisa, simpan ke array
    while (carry) {
        result[*size] = carry % 10;
        carry /= 10;
        (*size)++;
    }
}

void printFactorial(FILE *outputFile, int num, int result[], int size) {
    fprintf(outputFile, "Faktorial dari %d: ", num);
    for (int i = size - 1; i >= 0; i--) {
        fprintf(outputFile, "%d", result[i]);
    }
    fprintf(outputFile, "\n");
}


// Fungsi untuk menghitung kata dalam file
int wordCount (FILE *file) {
    char buffer[MAX_BUFFER];
    int jumlahKata = 0;
    char *kata;

    // Baca file baris per baris dan hitung jumlah kata
    while (fgets(buffer, MAX_BUFFER, file) != NULL) {
        kata = strtok(buffer, " \n"); // Tokenisasi string dengan delimiter spasi, tab, atau newline
        while (kata != NULL) {
            jumlahKata++; // Tambahkan jumlah kata
            kata = strtok(NULL, " \n"); // Ambil kata berikutnya
        }
    }

    return jumlahKata;
}


int main() {
    FILE *inputFile = fopen("input.txt", "r");
    FILE *outputFile = fopen("output.txt", "w");
    int num, word;
    int result[MAX] = {1};
    int size = 1;
    clock_t start, end;
    double executionTime;

    if (inputFile == NULL) {
        printf("tidak bisa membuka file/file tidak ditemukan\n");
        return 1;
    }

    start = clock();

    word = wordCount(inputFile);

    fseek(inputFile, 0, SEEK_SET); // kembali ke awal inputFile

    while (fscanf(inputFile, "%d", &num) != EOF) {

        for (int i = 0; i < MAX; i++) {
            result[i] = 0;
        }
        result[0] = 1;  // Set hasil awal untuk faktorial
        size = 1;  // Mulai dengan 1 digit (karena faktorial 0 atau 1 adalah 1)

        if (num < 0) fprintf(outputFile, "Perhitungan error, karena angka negatif (kurang dari 0)\n");
        else if (num > 30) fprintf(outputFile, "Perhitungan error, karena angka terlalu besar (lebih dari 30)\n");

        else {
            recursiveFactorial(num, result, &size);
            printFactorial(outputFile, num, result, size);
        }
    }
    end = clock();
    

    executionTime = (double) (end - start) / CLOCKS_PER_SEC;

    printf("\nTerdapat %d bilanngan yang dihitunng\n", word);
    printf("\nWaktu eksekusi %.5f detik", executionTime);
    
    
    fclose(inputFile);
    fclose(outputFile);
    return 0;
}
