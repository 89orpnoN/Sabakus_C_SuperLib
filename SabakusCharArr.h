#ifndef SABAKUSCHARARR
#define SABAKUSCHARARR

//Vi presento la versione "migliorata" dei Sabaku's arrays
//questa volta più grossi, più spavaldi e più peggiori di sempre
//I SABAKU'S HEAVY DUTY ARRAYS, che includono un contatore dello spazio in formato Unsigned long long int

//array di Caratteri
struct CharArr { //secondo i miei calcoli questo array può ospitare 18*10^18 valori, che riempito completamente ammonterebbe a 16 milioni di terabyte
    char* Arr;
    long long unsigned int Len;
    long long unsigned int Tlen;
};

struct CharArr CharArrContructor(){
    struct CharArr item;
    item.Len = 0;
    item.Tlen = 100;
    item.Arr = calloc(item.Tlen,sizeof( char ) );
    return item;
};

int ExpandCharArr(struct CharArr arr){
    arr.Tlen*=2;
    arr.Arr = realloc(arr.Arr,sizeof(char)*arr.Tlen);
    if (arr.Arr == NULL) return 0;
    return 1;
};

int CharAppend(struct CharArr arr, char i){
    arr.Arr[arr.Len] = i;
    arr.Len++;
    if (arr.Len>=arr.Tlen){

        if(!ExpandCharArr(arr)) return 0;
    }
    return 1;
};

int CharPop(struct CharArr arr){
    if(arr.Len<1) return 0;
    arr.Len--;
    arr.Arr[arr.Len]=0;
    return 1;
};

#endif //SABAKUSCHARARR
