#include "matrice2.h"
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>

int main(void){
    Matrice *A,*B;

    A = creer(1,2,3);
    initialiserLigne(2,1,A);
    printMatrice(A);
    printf("\n");
    B = creer(2,3,3);
    initialiserLigne(1,2,B);
    printMatrice(B);
    C = multiplier(A,B);
    printMatrice(C);
    free(A); //Désallouer pour tous les mallocs. 1 malloc = 1 free. Faire une focntion detruire
    free(B);
    A=NULL;
    B=NULL;

    return 0;
}