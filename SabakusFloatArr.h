#ifndef SABAKUSFLOATARR
#define SABAKUSFLOATARR
#include <stdlib.h>
//Vi presento la versione "migliorata" dei Sabaku's arrays
//questa volta più grossi, più spavaldi e più peggiori di sempre
//I SABAKU'S HEAVY DUTY ARRAYS, che includono un contatore dello spazio in formato Unsigned long long int

//array di Float
struct FloatArr { //secondo i miei calcoli questo array può ospitare 18*10^18 valori, che riempito completamente ammonterebbe a 163 milioni di terabyte
    float* Arr;
    long long unsigned int Len;
    long long unsigned int Tlen;
};

struct FloatArr FloatArrContructor(){
    struct FloatArr item;
    item.Len = 0;
    item.Tlen = 100;
    item.Arr = calloc(item.Tlen,sizeof( float ) );
    return item;
}

int ExpandFloatArr(struct FloatArr arr){
    arr.Tlen*=2;
    arr.Arr = realloc(arr.Arr,sizeof(float)*arr.Tlen);
    if (arr.Arr == NULL) return 0;
    return 1;
}

int FloatAppend(struct FloatArr arr, int i){
    arr.Arr[arr.Len] = i;
    arr.Len++;
    if (arr.Len>=arr.Tlen){

        if(!ExpandFloatArr(arr)) return 0;
    }
    return 1;
}

int FloatPop(struct FloatArr arr){
    if(arr.Len<1) return 0;
    arr.Len--;
    arr.Arr[arr.Len]=0;
    return 1;
}

#endif //SABAKUSFLOATARR
