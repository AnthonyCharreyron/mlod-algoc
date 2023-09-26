#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <assert.h>
#define maxSize 300

char buffer [maxSize];

typedef struct 
    {unsigned int annee;
    char* nom;
    char* travaux;
}Turingwinner;


int numberOfWinners(FILE* f);

char* readStringFromFileUntil(FILE* f,char delim);

void readWinner(Turingwinner* winner, FILE* f);

//void printWinners(FILE f);
