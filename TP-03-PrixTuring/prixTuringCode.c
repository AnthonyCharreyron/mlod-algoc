#include "prixTuring.h"

int numberOfWinners(FILE* f){
    int compteur =0;
    int c;
    while ((c = fgetc(f))!=EOF){
        if(c=='\n'){
            compteur+=1;
        }
    }
    rewind(f);
    return compteur;	
}

char* readStringFromFileUntil(FILE* f,char delim){
    int bufferIndex=0;
    char* info;
    char c;
    memset(buffer,0,maxSize);
    while ((c=fgetc(f)) != delim ) {
        buffer[bufferIndex] = c;
        bufferIndex++;
    }
    buffer[bufferIndex+1] = '\0'; 
    info=(char*)calloc(bufferIndex+2,sizeof(char));
    for (int k=0;buffer[k]!='\0';k++){
        info[k]=buffer[k];
    }
    info[bufferIndex+2] = '\0'; 
    return info;
}

void readWinner(Turingwinner* winner, FILE* f){
    fscanf(f,"%u"  ";",&winner->annee);
    winner->nom=readStringFromFileUntil(f,';');
    winner->travaux=readStringFromFileUntil(f,'\n');
}

Turingwinner* readWinners(FILE* f) {
    int nbLignes=numberOfWinners(f);
    Turingwinner* winners=(Turingwinner*)malloc(nbLignes*sizeof(Turingwinner));
    for (int i = 0; i < nbLignes; i++) {
        readWinner(&winners[i], f);
    }
    return winners;
}

void printWinner(FILE* o, Turingwinner* winner) {
    fprintf(o, "%u;%s;%s\n", winner->annee, winner->nom, winner->travaux);
}

void printWinners(FILE* o, Turingwinner* winners, int numWinners) {
    for (int i = 0; i < numWinners; i++) {
        printWinner(o, &winners[i]);
    }
}

void infosAnnee(unsigned int annee, Turingwinner *winners, int numberOfWinners) {
    for (int i = 0; i < numberOfWinners; i++) {
        if (winners[i].annee == annee) {
            printf("L'année %u, le(s) gagnant(s) ont été : %s\n", winners[i].annee, winners[i].nom);
            printf("Nature des travaux : %s\n", winners[i].travaux);
            return;
        }
    }
    printf("Pas d'information sur cette année");
}

void sortTuringWinnersByYear(Turingwinner* winners, int numberOfWinners) {
    Turingwinner tempo;
    for (int i = 0; i < numberOfWinners; i++) {
        for (int j = i + 1; j < numberOfWinners; j++) {
            if (winners[j].annee < winners[i].annee) {
                tempo = winners[i];
                winners[i] = winners[j];
                winners[j] = tempo;
            }
        }
    }
}
