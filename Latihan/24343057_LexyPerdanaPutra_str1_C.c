#include <stdio.h>
#include <string.h>

// Deklarasi fungsi bandingkanString
int bandingkanString(char* str1, char* str2) {
    return strcmp(str1, str2);
}

int main() {
    char string1[20], string2[20]; 
    
    // Meminta input dari user
    printf("Masukkan string ke 1    : ");
    scanf("%[^\n]", string1);
    getchar(); // Membersihkan buffer setelah input pertama
    
    printf("Masukkan string ke 2    : ");
    scanf("%[^\n]", string2);
    
    // Membandingkan dua string menggunakan fungsi bandingkanString
    int hasil = bandingkanString(string1, string2);
    
    // Menampilkan hasil perbandingan
    if (hasil == 0) {
        printf("String sama\n");
    } else {
        printf("String berbeda\n");
    }

    return 0;
}
