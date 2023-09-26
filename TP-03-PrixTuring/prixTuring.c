/**
 Compilation
 gcc --std=c99 -W -Wall -o prixTuring prixTuring.c

 Exécution
 ./prixTuring

 Tests
 diff out.csv turingWinners.csv

**/

#include "prixTuring.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <assert.h>

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// MAIN
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

int main(void) //int argc-> nb d'argument, char** argv ; pour la question 7
{
	char filename[] = "turingWinners.csv";
	//char outputFilename[] = "out.csv";

	FILE* f= fopen(filename,"r");
	//FILE* o= fopen(outputFilename,"w");
	
	printf("Nb lignes %d",numberOfWinners(f));
	Turingwinner* t=NULL;
	readWinner(t, f);
	printf("%u %s %s",&t->annee,&t->nom,&t->travaux);
	
	fclose(f);
	//fclose(o);
	

    // TODO

	return EXIT_SUCCESS;
}
