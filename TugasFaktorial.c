/*  File name     : TugasFaktorial.c
    Programer     : Lexy Perdana Putra
    NIM           : 24343057
    Program       : Program menghitung faktorial dengan fungsi rekursi
*/

#include <stdio.h>

//fungsi rekursi dengan ternary operator
int faktorial(int val) {return (val == 0 ? 1 : val * faktorial(val - 1));} 

int main(int argc, const char *argv[]) {    

    int num;        //deklarasi variabel
    char pilihan;
        
        //perulangan agar program dapat diulang berkali kali
    do {
        printf("Masukkan angka yang akan dicari faktorialnya : ");
        scanf("%d", &num);

        //mengecek apakah angka yang diinput kurang dari 0 atau tidak
        if (num < 0) printf("\nAngka tidak valid karena kurang dari 0\n");
        else printf("\nFaktorialnya adalah : %d\n", faktorial(num));

        printf("\nIngin mencari faktorial lain? (y/n) : ");
        scanf(" %c", &pilihan);

        //mengecek apakah user ingin mengulang program atau tidak
    } while (pilihan == 'y' || pilihan == 'Y');  

    printf("\n\nTerimakasih telah menggunakan program ini");

    return 0;
}