#ifndef MAHASISWA_UTS_H 
#define MAHASISWA_UTS_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Mahasiswa_UTS.h"

// Mendefinisikan struktur data mahasiswa dan nilai UTS
typedef struct {
    char nama[50];
    int nilaiUTS;
} dataMahasiswa;

// Mendefinisikan pointer ke elemen list
typedef struct tElmtList *address;

// Mendefinisikan struktur elemen dalam list
typedef struct tElmtList {
    dataMahasiswa info;
    address next;
} ElmtList;

// Mendefiniskan struktur list
typedef struct {
    address First;
} List;

// Membuat list kosong terlebih dahulu
void CreateList(List *L) {
    L->First = NULL;
}

// Mengalokasikan memori untuk elemen baru
address Alokasi(dataMahasiswa M) {
    address P = (address)malloc(sizeof(ElmtList));

    if (P != NULL) {
        P->info = M;
        P->next = NULL;
    }
    return P;
}

// Delaokasi memori agar membebaskan memori elemen
void Dealokasi(address P) {
    free(P);
}

// Insert dan mengurutkan nama berdasarkan abjad
void InsertAscendingbyNama(List *L, dataMahasiswa M) {
    address P = Alokasi(M);
    if (P == NULL) {
        printf("Alokasi memori gagal!");
        return;
    }

    // Membandingkan elemen baru dengan elemen pertama yang ditunjuk
    if (L->First == NULL || strcmp(L->First->info.nama, M.nama) > 0) {
        P->next = L->First;
        L->First = P;
    } else {
        address Q = L->First;
        while (Q->next != NULL && strcmp(Q->next->info.nama, M.nama) < 0) {
            Q = Q->next;
        }
        P->next = Q->next;
        Q->next = P;
    }
}

// Insert dan mengurutkan list berdasarkan nilai
void InsertAscendingbyNilai(List *L, dataMahasiswa M) {
    address P = Alokasi(M);
    if (P == NULL) {
        printf("Alokasi memori gagal!");
        return;
    }

    // Membandingkan nilai elemen baru dengan nilai elemen pertama yang ditunjuk
    if (L->First == NULL || L->First->info.nilaiUTS < M.nilaiUTS) {
        P->next = L->First;
        L->First = P;
    } else {
        address Q = L->First;
        while(L->First != NULL && Q->next->info.nilaiUTS > M.nilaiUTS) {
            Q = Q->next;
        }
        P->next = Q->next;
        Q->next = P;
    }
}

void DeleteList(List *L) {
    address P = L->First;
    while(P != NULL) {
        address Q = P;
        P = P->next;
        Dealokasi(Q);
    }
    L->First = NULL;
}

void DescendingListbyNilai(List L) {
    List sortedList;
    CreateList(&sortedList);

    address P = L.First;
    while (P != NULL) {
        address newNode = Alokasi(P->info);
        if (newNode == NULL) {
            printf("Alokasi memori gagal!\n");
            return;
        }

        if (sortedList.First == NULL || sortedList.First->info.nilaiUTS < newNode->info.nilaiUTS) {
            newNode->next = sortedList.First;
            sortedList.First = newNode;
        } else {
            address Q = sortedList.First;
            while (Q->next != NULL && Q->next->info.nilaiUTS > newNode->info.nilaiUTS) {
                Q = Q->next;
            }
            newNode->next = Q->next;
            Q->next = newNode;
        }

        P = P->next;
    }

    printf("+======== Nama ========= | === Nilai UTS ===+\n");
    P = sortedList.First;
    while (P != NULL) {
        printf("| %-22s | %-16d |\n", P->info.nama, P->info.nilaiUTS);
        P = P->next;
    }
    printf("+========================|==================+\n");

    DeleteList(&sortedList);
}

void AscendingList(List L) {
    address P = L.First;
    printf("+======== Nama ========= | === Nilai UTS ===+\n");
    while (P != NULL) {
        printf("| %-22s | %-16d |\n", P->info.nama, P->info.nilaiUTS);
        P = P->next;
    }
    printf("+========================|==================+\n");
}

int CountList(List L) {
    address P = L.First;
    int count = 0;
    while(P != NULL) {
        count++;
        P = P->next;
    }
    return count;
}

void CopyList(List L1, List *L2, int threshold) {
    DeleteList(L2);
    
    address P = L1.First;
    while (P != NULL) {
        if (P->info.nilaiUTS > threshold) {
            InsertAscendingbyNama(L2, P->info);
        }
        P = P->next;
    }
}

void RemoveDuplicate(List *L) {
    address P = L->First;
    while (P != NULL && P->next != NULL) {
        if(strcmp(P->info.nama, P->next->info.nama) == 0) {
            address Q = P->next;
            P->next = Q->next;
            Dealokasi(Q);
        } else {
            P = P->next;
        }
    }
}

#endif /* ifndef MACRO */
