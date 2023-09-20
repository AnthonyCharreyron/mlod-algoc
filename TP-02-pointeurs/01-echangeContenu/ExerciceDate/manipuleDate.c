#include <stdio.h>
#include "manipuleDate.h"
#include <stdlib.h>

void initialiseDate(Date *d){ //verifier que la date est valide avec do et if
    printf("jour : ");
    scanf("%hu",&d->jour);
    printf("mois : ");
    scanf("%d",(int *)&d->mois);
    printf("annee : ");
    scanf("%hu",&d->annee);
}

void afficheDate(Date *pd){
    printf("La date est : %hu %d %hu",pd->jour,pd->mois,pd->annee);
}

