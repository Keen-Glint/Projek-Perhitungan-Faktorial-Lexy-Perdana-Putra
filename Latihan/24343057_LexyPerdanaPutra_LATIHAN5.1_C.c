#include <stdio.h>

// menghitung faktorial
int hitungFaktorial(int n){
    if ( n == 0 || n == 1) return 1;
    else return n * hitungFaktorial( n - 1);
}

int main(){

    printf("Nama    : Lexy Perdana Putra\n");
    printf("Nim     : 243433057\n");
    printf("program : Program menghitung faktorial\n\n");

    int nilai;

    printf("Masukkan bilangan bulat positif : ");
    scanf("%i", &nilai);

    int faktorial = hitungFaktorial(nilai);
    printf("faktorial dari %i adalah : %i", nilai, faktorial);

    return 0;
}