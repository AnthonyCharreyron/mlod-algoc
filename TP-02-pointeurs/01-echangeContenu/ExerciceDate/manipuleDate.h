#pragma once
#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>

typedef enum {janvier=1, fevrier, mars, avril, mai, juin,
juillet, aout, septembre, octobre, novembre, decembre} Mois;

typedef struct {
    unsigned short jour;
    Mois mois;
    unsigned short annee;
} Date;

void initialiseDate(Date *d);

void afficheDate(Date *d);

Date creerDateParCopie(void);

Date* newDate(void);

unsigned int nbreJours(Mois mois, unsigned int annee);

bool anneeBissextile(unsigned int annee);

bool dateValide(Date uneDate);

unsigned int jourDansAnnee(Date uneDate);
