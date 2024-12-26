#include <stdio.h>

// Variabel global 
int langkah = 0;

// Fungsi rekursif untuk menyelesaikan Menara 
void menaraHanoi(int n, char awal, char bantu, char tujuan) {

    if (n == 1) {
        langkah++;   //untuk menambahkan langkah
        printf("Pindahkan cakram 1 dari tiang %c ke tiang %c\n", awal, tujuan);
        return;
    }

    menaraHanoi(n - 1, awal, tujuan, bantu);
    langkah++;      //menambahkan langkah
    printf("Pindahkan cakram %d dari tiang %c ke tiang %c\n", n, awal, tujuan);
    menaraHanoi(n - 1, bantu, awal, tujuan);
}

int main() {

    printf("Nama    : Lexy Perdana Putra\n");
    printf("NIM     : 24343057\n");
    printf("Program : Game menara Hanoi\n");

    int cakram;

    // Meminta input dari pengguna
    printf("Masukkan jumlah cakram: ");
    scanf("%d", &cakram);

    menaraHanoi(cakram, 'A', 'B', 'C');
    printf("\nJumlah langkah yang : %d\n\n", langkah);

    return 0;
}
