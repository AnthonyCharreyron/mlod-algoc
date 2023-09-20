#pragma once

typedef enum {janvier=1, fevrier, mars, avril, mai, juin,
juillet, aout, septembre, octobre, novembre, decembre} Mois;

typedef struct {
    unsigned short jour;
    Mois mois;
    unsigned short annee;
} Date;

void initialiseDate(Date *d);

void afficheDate(Date *d);