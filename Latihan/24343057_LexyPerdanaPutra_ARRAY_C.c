#include <stdio.h>

#define N 5

//fungsi menampilkan array
void tampil(int* arr){
    for (int i = 0; i < N; i++) {
        printf("elemen ke %i array adalah %i\n", i + 1, arr[i]);
    }
}

//fungsi untuk mengubah nilai array yang ditentukan
void ubah(int pilih, int* arr){
    printf("anda ingin mengubah nilai elemen ke %i menjadi : ", pilih);
    scanf("%i", &arr[pilih - 1]);
}

int main(){
    //deklarasi array
    int bilangan[N] = {5, 4, 3, 2, 1};
    int pilihan;

    //menampilkan nilai awal array
    printf("Nilai awal array \n");
    tampil(bilangan);

    //mengubah elemen tertentu sesuai keinginan user
    printf("tentukan elemen ke berapa yang ingin anda ubah : ");
    scanf("%i", &pilihan);
    ubah(pilihan, bilangan);

    //menampilkan array yang sudah di ubah
    printf("Nilai akhir array \n");
    tampil(bilangan);
    
    return 0;
}