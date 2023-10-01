#include "prixTuring.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <assert.h>

int main(int argc, char** argv ) { 
	
	char* filename = argv[argc-1];
	FILE* f = fopen(filename, "r");

	int numWinners=numberOfWinners(f);
	Turingwinner* winners=readWinners(f); //Ne fonctionne pas sur ma machine pour les fichiers textes trop longs (max 8 lignes)
	
	fclose(f);
	
	if (argc == 4 && strcmp(argv[1], "-o") == 0) {
       	FILE* o = fopen(argv[2], "w");
       	printWinners(o, winners, numWinners);
       	fclose(o);
  	}
	
	if (argc == 4 && strcmp(argv[1], "--info") == 0) {
       	int anneeDemandee = atoi(argv[2]);
       	infosAnnee(anneeDemandee, winners, numWinners);
    }

	if (argc == 5 && strcmp(argv[1], "--sort") == 0 && strcmp(argv[2], "-o") == 0) {
       	sortTuringWinnersByYear(winners, numWinners);
      	FILE *o = fopen(argv[3], "w");
       	printWinners(o, winners, numWinners);
      	fclose(o);
  	}

	for (int i = 0; i < numWinners; i++) {
    	free(winners[i].nom);
    	free(winners[i].travaux);
    }
	free(winners);
	

	return EXIT_SUCCESS;
}
