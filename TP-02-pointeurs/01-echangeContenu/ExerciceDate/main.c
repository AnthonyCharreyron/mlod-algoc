#include "manipuleDate.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main (void){

    
    
    Date d;
    printf("Version 1 \n");
    initialiseDate(&d); // accede a l adresse memoire directement pour appliquer les changements sur d et non la copie
    afficheDate(&d);    

    /*
    Date d;
    printf("Version 2 \n"); // Ne devrait pas etre utilisee car on cree une copie que l on stocke
    d = creerDateParCopie();
    afficheDate(&d);
    */
    /*
    Date* date;
    printf("Version 3 \n"); // on libere la memoire utilisee apres avoir affiche
    date = newDate();
    afficheDate(date);
    free(date);
    */
    
    /*// Test de nbreJours
    unsigned int a= nbreJours(fevrier, 2024);
    printf("%u \n",a);
    */
    /*// Test dateValide
    Date d = {10, 13, 2023};
    if (dateValide(d)) {
       printf("Valide.\n");
    } else {
       printf("Invalide.\n");
    }
    */
    unsigned int j;
    j= jourDansAnnee(d);
    printf("\n Jour numero : %u\n", j);

   return 0;

}