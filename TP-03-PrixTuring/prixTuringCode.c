#include "prixTuring.h"

int numberOfWinners(FILE* f){
    int compteur =0;
    int c;
    while ((c = fgetc(f))!=EOF){
        if(c=='\n'){
            compteur+=1;
        }
    }
    return compteur;	
}

char* readStringFromFileUntil(FILE* f,char delim){
    int i=0;
    char* c;
    int d;
    memset(buffer, 0, maxSize);
    while ((d = fgetc(f))!=delim){
        buffer[i]= fgetc(f);
        i++;
    }
    c=(char*)calloc(i,sizeof(char));
    for (int k=0;k<i-1;k++){
        c[k]=buffer[k];
    }
    c[i]='\0';
    return c;
}

void readWinner(Turingwinner* winner, FILE* f){
    fscanf(f,"%u"  ";",&winner->annee);
    winner->nom=readStringFromFileUntil(f,';');
    winner->travaux=readStringFromFileUntil(f,'\n');
}