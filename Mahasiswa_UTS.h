#ifndef MAHASISWA_UTS_H
#define MAHASISWA_UTS_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
void CreateList(List *L);

// Alokasi memori untuk elemen baru
address Alokasi(dataMahasiswa M);

// Membebeaskan memori elemen dengan dealokasi
void Dealokasi(address P);

void InsertAscendingbyNama(List *L, dataMahasiswa M);

void InsertAscendingbyNilai(List *L, dataMahasiswa M);

void DescendingListbyNilai(List L);

void AscendingList(List L);

int CountList(List L);

void CopyList(List L1, List *L2, int threshold);

void RemoveDuplicate(List *L);

void DeleteList(List *L);

#endif
