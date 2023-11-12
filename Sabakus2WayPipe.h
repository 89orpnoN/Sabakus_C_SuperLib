#ifndef SABAKUS2WAYPIPE
#define SABAKUS2WAYPIPE

#include <unistd.h>

enum Types {
    Void, //se lo usi sei malato
    String,
    Int,
    Float,
};

int TypeLenghts[4] = {
        1,
        sizeof(char),
        sizeof(int),
        sizeof(float)
};

typedef struct {
    int UpStream[2];
    int DownStream[2];
    short int Type;
    short int ChunkSize;
    int Pid1;
    int Pid2;

}S2WPipe;

typedef struct {
void* Data;
short int Type;
}SPReadings;

S2WPipe S2WPipeConstructor(int Pid1,int Pid2,int type){
    S2WPipe Pipe;
    if (pipe(Pipe.UpStream)<0 || pipe(Pipe.DownStream)<0) return Pipe;
    Pipe.Pid1 = Pid1;
    Pipe.Pid2 = Pid2;
    Pipe.Type = type;
    Pipe.ChunkSize = TypeLenghts[type];
}



#endif //SABAKUS2WAYPIPE
