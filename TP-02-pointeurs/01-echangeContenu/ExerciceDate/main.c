#include "manipuleDate.h"
#include <stdio.h>

int main (void){
    Date d;
    printf("Version 1 \n");
    initialiseDate(&d); // accede a l adresse memoire directement pour appliquer les changements sur d et non la copie
    afficheDate(&d);
    return 0;
}