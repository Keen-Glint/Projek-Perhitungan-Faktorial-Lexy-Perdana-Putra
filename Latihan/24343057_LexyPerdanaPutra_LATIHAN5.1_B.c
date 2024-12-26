#include <stdio.h>

//mendefinisikan nilai pi
#define PI 3.14

// Fungsi untuk menghitung keliling lingkaran
float hitungKelilingLingkaran(float jariJari){
    return 2 * PI * jariJari;
}

int main() {

    printf("Nama    : Lexy Perdana Putra\n");
    printf("Nim     : 243433057\n");
    printf("program : Program menghitung keliling lingkaran\n\n");

    float jariJari;

    printf("Masukkan jari-jari lingkaran: ");
    scanf("%f", &jariJari);

    // Memanggil fungsi dan menampilkan hasil
    float keliling = hitungKelilingLingkaran(jariJari);
    printf("Keliling lingkaran adalah: %.2f\n", keliling);

    return 0;
}
