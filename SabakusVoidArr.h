//
// Created by Nonpro98 on 09/11/2023.
//

#ifndef SABAKUSVOIDARR
#define SABAKUSVOIDARR
#include <stdlib.h>

typedef struct  { //secondo i miei calcoli questo array può ospitare 18*10^18 valori, che riempito completamente ammonterebbe a 65 milioni di terabyte
    void* Arr;
    short unsigned int TypeSize;
    long long unsigned int Len;
    long long unsigned int Tlen;
}VoidArr;

//anche se dichiaro l'array da 100 spazi non è saggio usarli senza metodi prestabiliti
VoidArr VoidArrContructor(long long unsigned int size, int Typesize = 1){
    VoidArr item;
    item.TypeSize = Typesize;
    item.Len = size;
    item.Tlen = size+100;
    item.Arr = calloc(item.Tlen,Typesize);
    return item;
}

int ExpandVoidArr(VoidArr arr){
    arr.Tlen*=2;
    arr.Arr = realloc(arr.Arr,arr.TypeSize*arr.Tlen);
    if (arr.Arr == NULL) return 0;
    return 1;
}

int VoidAppend(VoidArr arr, int i){
    arr.Arr[arr.Len] = i;
    arr.Len++;
    if (arr.Len>=arr.Tlen){

        if(!VoidArr(arr)) return 0;
    }
    return 1;
}

int VoidPop(VoidArr arr){
    if(arr.Len<1) return 0;
    arr.Len--;
    arr.Arr[arr.Len]=0;
    return 1;
}

#endif //SABAKUSVOIDARR
