#pragma once
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>

typedef struct {
    uint16_t nbLignes;
    uint16_t nbColonnes;
    int** valeurs; 
} Matrice;

Matrice* creer(int v,uint16_t l,uint16_t c);

void initialiserLigne(int v, uint16_t l, Matrice* m);

void multiplier(Matrice* a,Matrice* b);

void printMatrice(Matrice* a);

