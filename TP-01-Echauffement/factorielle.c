#include <stdio.h> //printf
#include <stdlib.h> // EXIT_SUCESS
#include <stdbool.h> // bool
#include <stdint.h> // uint8_t, uint64_t, ... entier non signé codé sur 8 ou 64 bits

typedef short TypeEntier;
TypeEntier factorielle(TypeEntier);

int main (void){
    for (int i=1; i<16;i++){
        printf("La factorielle de %u est : %u   \n", i, factorielle(i));
    }

}
TypeEntier factorielle(TypeEntier n){
    TypeEntier prod =1;
    for (int i=1;i<=n;i++){
        prod=prod*i;
    }
    return prod;
}