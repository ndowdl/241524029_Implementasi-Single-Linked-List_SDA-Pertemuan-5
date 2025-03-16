#include "Mahasiswa_UTS.h"
#include <stdio.h>
#include <string.h>

int main() {
    List L1, L2;
    CreateList(&L1);
    CreateList(&L2);

    int jumlahMahasiswa;
    printf("Masukkan jumlah mahasiswa dalam kelas: ");
    scanf("%d", &jumlahMahasiswa);
    getchar();

    int i = 0;
    while(i < jumlahMahasiswa){
        dataMahasiswa M;
        printf("\nMasukkan data mahasiwa ke-%d: \n", i + 1);

        // Memasukkan input nama mahasiswa
        printf("Nama Mahasiswa: ");
        fgets(M.nama, 50, stdin);
        M.nama[strcspn(M.nama, "\n")] = '\0';

        // Memasukkan input nilai UTS mahasiswa
        printf("Nilai UTS Mahasiswa: ");
        scanf("%d", &M.nilaiUTS);
        getchar();

        InsertAscendingbyNama(&L1, M);
        i++;

    }

    printf("\nList L1 (Ascending berdasarkan nama): \n");
    AscendingList(L1);

    printf("\nList L1 (Descending berdasarkan nilai UTS): \n");
    DescendingListbyNilai(L1);
    
    CopyList(L1, &L2, 70);
    printf("\nList L2 (Mahasiswa yang memiliki nilai UTS > 70): \n");
    AscendingList(L2);

    RemoveDuplicate(&L2);
    printf("\nList L2 setelah menghapus duplikat: \n");
    AscendingList(L2);

    int count = CountList(L1);  
    printf("\nJumlah mahasiswa List L1: %d\n", count);  

    DeleteList(&L1);
    DeleteList(&L2);

    return 0;
}
