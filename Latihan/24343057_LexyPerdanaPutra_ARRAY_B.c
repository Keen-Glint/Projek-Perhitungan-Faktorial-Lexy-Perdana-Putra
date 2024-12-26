#include <stdio.h>

#define N 5

//fungsi menjumlahkan semua elemen array
int jumlahkan(int* a){
    int hasil = 0;
    for (int i = 0; i < N; i++) {
        hasil += a[i];
    }
    return hasil;
}

int main(){
    //deklarasi array
    int bilangan[N] = {5, 4, 3, 2, 1};
    //memasukkan fungsi ke variable agar bisa dipanggil
    int tambahkan = jumlahkan(bilangan);
    //menampilkan hasilnya
    printf("jumlah semua bilangan dalam array adalah : %i", tambahkan);
    return 0;
}