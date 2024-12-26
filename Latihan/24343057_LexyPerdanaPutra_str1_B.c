#include <stdio.h>
#include <string.h>

//menggabungkan kalimat 2 ke kalimat pertama
void gabungStr(char* a, char* b) {
    strcat(a, b);
}

int main(){
    char kalimat1[20], kalimat2[20];

    //memasukkan input kalimat 1 dan 2
    printf("masukkan kalimat 1 : ");
    scanf("%[^\n]", kalimat1);
    getchar(); //menghapus karakter newline kalimat 1 agar bisa masuk ke input berikutnya

    printf("masukkan kalimat 2 : ");
    scanf("%[^\n]", kalimat2);

    gabungStr(kalimat1, kalimat2);
    //hasil kalimat 1 setelah kalimat 2 digabungkan ke dalam kalimant 1
    printf("kalimat setelah digabungkan = %s", kalimat1); 

    return 0;
}