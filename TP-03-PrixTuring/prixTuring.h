#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <assert.h>
#define maxSize 1000

char buffer [maxSize];

typedef struct 
    {unsigned int annee;
    char* nom;
    char* travaux;
}Turingwinner;


int numberOfWinners(FILE* f);

char* readStringFromFileUntil(FILE* f,char delim);

void readWinner(Turingwinner* winner, FILE* f);

Turingwinner* readWinners(FILE* f);

void printWinner(FILE* o, Turingwinner* winner);

void printWinners(FILE* o, Turingwinner* winners, int numWinners);

void infosAnnee(unsigned int annee, Turingwinner* winners, int numberOfWinners);

void sortTuringWinnersByYear(Turingwinner* winners, int numberOfWinners);