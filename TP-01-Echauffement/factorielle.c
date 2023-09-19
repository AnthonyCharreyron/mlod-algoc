#include <stdio.h> //printf
#include <stdlib.h> // EXIT_SUCESS
#include <stdbool.h> // bool
#include <stdint.h> // uint8_t, uint64_t, ... entier non signé codé sur 8 ou 64 bits
#include <inttypes.h>

typedef unsigned long long TypeEntier;
TypeEntier factorielle(TypeEntier);

int main (void){
    for (int i=1; i<16;i++){
        printf("La factorielle de %u est : %" PRIu64  "\n", i, factorielle(i));
    }
}
TypeEntier factorielle(TypeEntier n){
    TypeEntier prod =1;
    for (int i=1;i<=n;i++){
        prod=prod*i;
    }
    return prod;
}

// Après quelques calcul de factorielles, le nombre obtenu est trop grand et n'est plus affiché
//Le type de TypeEntier ne permet pas d'afficher des aussi grands nombres

//Après changement de type, les résultats s'affichent correctement