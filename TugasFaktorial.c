/*  File name     : TugasFaktorial.c
    Programer     : Lexy Perdana Putra
    NIM           : 24343057
    Program       : Program menghitung faktorial dengan fungsi rekursi
*/

#include <stdio.h>

//fungsi rekursi dengan ternary operator
long long int faktorial(int val) {return (val == 0 ? 1 : val * faktorial(val - 1));} 

//fungsi untuk menampilkan langkah langkah faktorialnya
long long int show(long long int num) {
    if ( num == 0) printf("1");
    else {
        for (long long int i = num; i > 0; i--) {
            if ( num == i) printf("%lld", i);
            else printf(" * %lld", i);
        }
    }  
}


int main(int argc, const char *argv[]) {    
    long long int num;        //deklarasi variabel
    char pilihan;
        
        //perulangan agar program dapat diulang berkali kali
    do {
        printf("Masukkan angka yang akan dicari faktorialnya ( 0 - 20 ): ");

        //mengecek apakah nilai nya bisa dihitung (tidak lebih dari 20!)
        do {
            scanf("%lld", &num);
            //mengecek apakah angka yang diinput valid atau tidak
            if (num > 22 ) printf("Angka yang dimasukkan tidak valid, masukkan ulang angka yang baru ( 0 - 20 ) : ");
            else {
                //menampilkan langkah langkah dan hasil dari faktorialnya
                printf("\nHasil dari "); 
                printf("%lld! = ", num);
                show(num);
                printf(" = %lld \n", faktorial(num));
            }
        } while (num > 22);
        
        printf("\nIngin mencari faktorial lain? (y/n) : ");
        scanf(" %c", &pilihan);

        //mengecek apakah user ingin mengulang program atau tidak
    } while (pilihan == 'y' || pilihan == 'Y');  

    printf("\nTerimakasih telah menggunakan program ini");

    return 0;
}