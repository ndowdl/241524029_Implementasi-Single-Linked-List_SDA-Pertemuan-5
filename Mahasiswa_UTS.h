#ifndef MAHASISWA_UTS_H
#define MAHASISWA_UTS_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char nama[50];
    int nilaiUTS;
} dataMahasiswa;

typedef struct tElmtList *address;

typedef struct tElmtList {
    dataMahasiswa info;
    address next;
} ElmtList;

typedef struct {
    address First;
} List;

void CreateList(List *L);

address Alokasi(dataMahasiswa M);

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
