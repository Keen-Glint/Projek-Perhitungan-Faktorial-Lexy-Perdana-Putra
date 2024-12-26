#include <stdio.h>

#define N 5

//fungsi menampilkan Array
void tampil(int* a){
    for (int i = 0; i < N; i++) printf("array ke %i adalah %i\n", i+1, a[i]);
}

int main(){
    //deklarasi array
    int bilangan[N] = {5, 4, 3, 2, 1};
    //memanggil fungsi
    tampil(bilangan);

    return 0;
}