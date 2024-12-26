#include <stdio.h>
#include <string.h>

int hitungPanjangString(char* lengh){
    return strlen(lengh);
}

int main(){
    char kalimat[100];

    printf("masukkan kalimat : ");
    scanf("%[^\n]", kalimat);

    int lengh = hitungPanjangString(kalimat);
    printf("kalimat yang dimasukkan user : %s\n", kalimat);
    printf("jumlah huruf dari kalimat kalimat adalah : %i\n", lengh);
    
    return 0;
}