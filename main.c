#include "Sabakus2WayPipe.h"
#include <stdio.h>
#include <unistd.h>
#include <wait.h>


void Son(S2WPipe Pipe, int FatherPid,int SonPid){
    int i = 76;
    S2WPipeWrite(Pipe, &i);

}



void Father(S2WPipe Pipe, int FatherPid,int SonPid){
    int i = 1000;
    wait(&i);
    wait(NULL);
    SPReadings a = S2WPipeRead(Pipe);
    int b = ((int*)a.Data)[0];
    printf("il numero è %i", b);
}




int main() { //qui presento il punto di inizio del programma dello sbocco.

    int FatherPid = getpid();
    S2WPipe Pipe = S2WPipeConstructor(FatherPid,0, 2);

    int SonPid = fork();
    short int AmSon;

    if (SonPid){
        AmSon = 0;
    } else {
        AmSon = 1;
        SonPid = getpid();
    }
    Pipe.Pid2 = SonPid;

    if (AmSon){
        Son(Pipe,FatherPid,SonPid);
    } else {
        Father(Pipe,FatherPid,SonPid);
    }

    return 0;
}
