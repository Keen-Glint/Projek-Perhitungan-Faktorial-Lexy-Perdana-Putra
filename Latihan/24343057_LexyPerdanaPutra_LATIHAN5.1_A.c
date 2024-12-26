#include <stdio.h>

// Fungsi untuk menghitung luas persegi panjang
int hitungLuasPersegiPanjang(int panjang, int lebar) {
    return panjang * lebar;
}

int main() {

    printf("Nama    : Lexy Perdana Putra\n");
    printf("Nim     : 243433057\n");
    printf("program : Program menghitung luas persegi panjang\n\n");

    int panjang, lebar;

    //meminta input user
    printf("Masukkan panjang: ");  
    scanf("%d", &panjang);
    printf("Masukkan lebar: ");
    scanf("%d", &lebar);

    // Memanggil fungsi dan menampilkan hasil
    int luas = hitungLuasPersegiPanjang(panjang, lebar);
    printf("Luas persegi panjang adalah: %d\n", luas);

    return 0;
}
