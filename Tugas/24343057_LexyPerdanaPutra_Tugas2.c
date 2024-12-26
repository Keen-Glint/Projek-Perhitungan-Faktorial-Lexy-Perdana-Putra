#include <stdio.h>
#include <stdlib.h>
#include <time.h>


// fungsi pilihan difficulty
int difficult(){
    int a;
    printf("1.Mudah (1-50, kesempatan = 5x)\n");
    printf("2.Sedang (1-100, kesempatan = 5x)\n");
    printf("3.Sulit (1-200, kesempatan = 5x)\n");
    printf("Tingkat kesulitan yang anda pilih adalah : ");
    scanf("%i", &a);
    return a;
}

// fungsi memproses permainan
void mainGame(int batas, int skorBenar, int *skor) {
    int angkaTebakan = rand() % batas + 1;
    int kesempatan = 5, tebakan;

    printf("Saya telah memilih angka dari 1-%d.\n", batas);
    printf("Anda punya kesempatan 5x menebaknya.\n");

    while (kesempatan > 0) {
        printf("Masukkan Tebakan anda: ");
        scanf("%i", &tebakan);

        if (tebakan > angkaTebakan)
            printf("Angka yang anda masukkan terlalu besar.\n");
        else if (tebakan < angkaTebakan)
            printf("Angka yang anda masukkan terlalu kecil.\n");
        else {
            printf("Selamat, angka yang anda masukkan benar!!!\n");
            *skor += skorBenar * kesempatan / 5;
            return;                                                  // Jika benar, keluar dari fungsi
        }

        kesempatan--;
        printf("Sisa kesempatan anda adalah %i.\n", kesempatan);
    }

    // Jika kesempatan habis
    printf("Maaf, anda gagal menebak angka yang benar.\n");
    printf("Angka yang benar adalah: %i\n", angkaTebakan);
    *skor -= 5;                                                     // Kurangi skor jika gagal
}

int main(){
    int kesulitan, skor = 0;
    char pilihan;

    srand(time(0));

    printf("Selamat datang di permainan tebak angka!!\n");
    printf("Anda akan menebak angka random yang telah kami tentukan\n");
    printf("Jika anda benar maka anda akan mendapat penambahan skor tergantung seberapa cepat anda menebak\n");
    printf("Skor maksimal berbeda tergantung tingkat kesulitannya (mudah = 10, sedang = 20, sulit =30)\n");
    printf("Jika anda salah maka anda akan mendapat pengurangan skor sebesar 5\n");
    printf("ENJOY THE GAME!!\n\n");

    // perulangan
    do {

        kesulitan = difficult();

        // alur kontrol
        switch (kesulitan) {
        case 1 : mainGame(50, 10, &skor); break;
        case 2 : mainGame(100, 20, &skor); break;
        case 3 : mainGame(200, 30, &skor); break;
        default:
            printf("Pilihan anda tidak valid");
        }

        printf("\nSkor anda saat ini adalah %i\n\n", skor);
        printf("Apakah anda ingin bermain lagi untuk menambah skor anda? (Y / T) : ");
        scanf(" %c", &pilihan);                             // memasukkan input mengulang game atau tidak

    } while (pilihan == 'y' || pilihan == 'Y');
    
    
    printf("\nSkor akhir yang anda dapatkan adalah %i\n\n", skor);
    printf("Terima kasih telah bermain dengan program saya.....\n\n");
    printf("Program ini dibuat oleh Lexy Perdana Putra dg NIM 24343057\n");


    return 0;
}