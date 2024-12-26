#include <stdio.h>
#include <string.h>

typedef struct {
    int hari, bulan, tahun;
}tanggal;

typedef struct {
    char nama[30];
    int nim;
    tanggal tanggal_lahir;
}mahasiswa;

mahasiswa data_mahasiswa;

int main() {
    
    //memasukkan data
    strcpy(data_mahasiswa.nama, "Lexy Perdana Putra");
    data_mahasiswa.nim = 24343057;
    data_mahasiswa.tanggal_lahir.hari = 11;
    data_mahasiswa.tanggal_lahir.bulan = 05;
    data_mahasiswa.tanggal_lahir.tahun = 2005;

    //menampilkan data
    printf("Nama mahasiswa          : %s\n", data_mahasiswa.nama);
    printf("Nomor Induk Mahasiswa   : %d\n", data_mahasiswa.nim);
    printf("Tanggal Lahir           : %d-%d-%d\n", data_mahasiswa.tanggal_lahir.hari, 
    data_mahasiswa.tanggal_lahir.bulan, 
    data_mahasiswa.tanggal_lahir.tahun);

    return 0;
}