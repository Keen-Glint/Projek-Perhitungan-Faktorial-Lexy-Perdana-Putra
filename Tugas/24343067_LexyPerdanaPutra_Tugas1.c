/* Nama : Lexy Perdana Putra
   NIM  : 24343057 
   date : 4 october 2024*/

#include <stdio.h>
#include <stdlib.h>


int main(){

    printf("Nama : Lexy Perdana Putra\n");
    printf("NIM  : 24343057\n");
    printf("date : 4 october 2024\n\n");

    double nilaiTugas, nilaiUts, nilaiUas, nilaiAkhir;  // Deklarasi variabel

    printf("Nilai Tugas Tugas: ");  
    scanf("%lf", &nilaiTugas);   // input nilai tugas 
    printf("Nilai Tugas UTS: ");
    scanf("%lf", &nilaiUts);     // input nilai UTS
    printf("Nilai Tugas UAS: ");
    scanf("%lf", &nilaiUas);     // input nilai UAS 

    nilaiAkhir = (0.3 * nilaiTugas) + (0.3 * nilaiUts) +(0.3 * nilaiUas); // menentukan nilai akhir

    printf("Nilai : %.2lf\n", nilaiAkhir); //  menampilkan nilai akhir


    if(nilaiAkhir >= 60  && nilaiUas >= 50){   // menampilkan  lulus dan tidak lulus
        printf("\nStatus : LULUS");
    } else { 
        printf("\nStatus : TIDAK LULUS");
    } 
    return 0;
}