#include <stdio.h>
#include <string.h>

#define MAX_BUKU 100    //jumlah buku maksimal
#define MAX_STRING 100  //jumlah maksimal karakter/huruf

typedef struct {
    size_t ID;
    char judul[MAX_STRING];
    char pengarang[MAX_STRING];
    size_t tahun;
}Book;

//fungsi menambahkan buku
void tambahkanBuku(Book *perpustakaan, int *jumlahBuku){
    if (*jumlahBuku < MAX_BUKU ) {

        printf("Masukkan ID buku     : ");
        getchar();
        scanf("%d", &perpustakaan[*jumlahBuku].ID);

        printf("Masukkan judul buku     : ");
        getchar();
        fgets(perpustakaan[*jumlahBuku].judul, MAX_STRING, stdin);
        perpustakaan[*jumlahBuku].judul[strcspn(perpustakaan[*jumlahBuku].judul, "\n")] = 0;

        printf("Masukkan pengarang buku : ");
        fgets(perpustakaan[*jumlahBuku].pengarang, MAX_STRING, stdin);
        perpustakaan[*jumlahBuku].pengarang[strcspn(perpustakaan[*jumlahBuku].pengarang, "\n")] = 0;

        printf("Masukkan tahun terbit   : ");
        scanf("%i", &perpustakaan[*jumlahBuku].tahun);

        (*jumlahBuku)++;
    } else printf("Buku sudah penuh");    
}

//fungsi menampilkan semua buku
void tampilkanBuku(Book *perpustakaan, int jumlahBuku){
    for (int i = 0; i < jumlahBuku; i++) {
        printf("\nBuku Ke %i\n", i+1);
        printf("ID              : %d\n", perpustakaan[i].ID);
        printf("Judul           : %s\n", perpustakaan[i].judul);
        printf("Pengarang       : %s\n", perpustakaan[i].pengarang);
        printf("Tahun terbit    : %i\n", perpustakaan[i].tahun);
    }
}

// fungsi mencari buku
int findBook(Book *perpustakaan, int jumlahBuku){
    int id_to_search;

    printf("Masukkan ID buku        : ");
    getchar();
    scanf("%d", &id_to_search);

    for (int i = 0; i < jumlahBuku; i++) {
        if (perpustakaan[i].ID == id_to_search) return i;
    }
    return -1;
}

//fungsi mencari buku dengan judul dan langsug menampilkan
void findBookAndDisplay(Book *perpustakaan, int jumlahBuku){
    int find_at_index = findBook(perpustakaan, jumlahBuku);


    if (find_at_index == -1){
        printf("\nBuku tidak ditemukan\n");
        return;
    }
    printf("ID              : %d\n", perpustakaan[find_at_index].ID);
    printf("Judul           : %s\n", perpustakaan[find_at_index].judul);
    printf("Pengarang       : %s\n", perpustakaan[find_at_index].pengarang);
    printf("Tahun terbit    : %i\n", perpustakaan[find_at_index].tahun);
}

// fungsi menghapus buku
void hapusBuku(Book *perpustakaan, int *jumlahBuku) {
    int find_at_index = findBook(perpustakaan, *jumlahBuku);

    if (find_at_index == -1) printf("\nBuku tidak ditemukan\n");
    else {
        // Geser buku-buku setelahnya ke depan
        for (int i = find_at_index; i < *jumlahBuku - 1; i++) {
            perpustakaan[i] = perpustakaan[i + 1];
        }
        (*jumlahBuku)--;
        printf("\nBuku berhasil dihapus\n");
    }
}

//fungsi mengedit buku
void editBuku(Book *perpustakaan, int jumlahBuku){
    int find_at_index = findBook(perpustakaan, jumlahBuku);
    Book temp;
    
    printf("Masukkan judul buku     (string kosong/spasi jika tidak ingin mengubah) : ");
    getchar();
    fgets(temp.judul, MAX_STRING, stdin);
    temp.judul[strcspn(temp.judul, "\n")] = 0;

    printf("Masukkan pengarang buku (string kosong/spasi jika tidak ingin mengubah) : ");
    fgets(temp.pengarang, MAX_STRING, stdin);
    temp.pengarang[strcspn(temp.pengarang, "\n")] = 0;

    printf("Masukkan tahun terbit (0 jika tidak ingin mengubah)  : ");
    scanf("%i", &temp.tahun);

    if(strcmp(temp.judul, " ") != 0){
       strcpy(perpustakaan[find_at_index].judul, temp.judul);
    }
    if(strcmp(temp.pengarang, " ") != 0){
       strcpy(perpustakaan[find_at_index].pengarang, temp.pengarang);
    }
    if(temp.tahun != 0){
       perpustakaan[find_at_index].tahun = temp.tahun;
    }
}

int main(){
    Book perpustakaan[MAX_BUKU];
    int pilihan, jumlahBuku = 0;
    char ulang;

    //perulangan agar user dapat menjalankan program berkali kali
    do {
        printf("Menu\n");
        printf("1. Tambahkan buku\n");
        printf("2. Semua buku\n");
        printf("3. Cari buku\n");
        printf("4. Hapus buku\n");
        printf("5. Edit buku\n");
        printf("Masukkan pilihan anda : ");
        scanf("%i", &pilihan);


        switch (pilihan) {
            case 1:
                tambahkanBuku(perpustakaan, &jumlahBuku);
                break;
            case 2:
                tampilkanBuku(perpustakaan, jumlahBuku);
                break;
            case 3:
                findBookAndDisplay(perpustakaan, jumlahBuku);
                break;
            case 4:
                hapusBuku(perpustakaan, &jumlahBuku);
                break;
            case 5:
                editBuku(perpustakaan, jumlahBuku);
                break;
            
            default:
                break;
        }

        printf("Kembali ke menu? (Y / N) : ");
        scanf(" %c", &ulang);
    } while (ulang == 'y' || ulang == 'Y');   

    return 0;
}