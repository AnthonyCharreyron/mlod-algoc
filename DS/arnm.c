// Charreyron Anthony
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "vaccins_covid.h"

// =========
// = Types =
// =========

const char NUCLEOTIDES[] = "ATCG";

typedef struct {
	int index;
	int distance;
}Difference;

typedef Difference* Liste;

// =============
// = Fonctions =
// =============


bool isNucleotide(char c) {
    return (c==NUCLEOTIDES[0] || c==NUCLEOTIDES[1] || c==NUCLEOTIDES[2] || c==NUCLEOTIDES[3]);
}

int indexOf(char nucleotide) {
	switch(nucleotide) {
		case 'A': return 0;
		case 'T': return 1;
		case 'C': return 2;
		case 'G': return 3;
		default:
			return -1;
	}
}

int distanceBetweenNucleotides(char n1, char n2) {
    return indexOf(n1)-indexOf(n2);
}

int* statistics (char sequenceDeNu []){
	int* tab=malloc(4*sizeof(char));
	int avancement=0;
	int compteurA=0;
	int compteurT=0;
	int compteurC=0;
	int compteurG=0;;
	char c = sequenceDeNu[0];
	if (!isNucleotide(c)){
		return NULL;
	}
	while (c!='\0'){
		if (indexOf(c)==0){
			compteurA++;
			avancement++;
			c=sequenceDeNu[avancement];
		}
		else if (indexOf(c)==1){
			compteurT++;
			avancement++;
			c=sequenceDeNu[avancement];
		}
		else if (indexOf(c)==2){
			compteurC++;
			avancement++;
			c=sequenceDeNu[avancement];
		}
		else {
			compteurG++;
			avancement++;
			c=sequenceDeNu[avancement];
		}
	}
	int total=compteurA+compteurT+compteurC+compteurG;
	tab[0]=100*compteurA/total;
	tab[1]=100*compteurT/total;
	tab[2]=100*compteurC/total;
	tab[3]=100*compteurG/total;
	return tab;
}

int nombreDeDifferences(char sequence1 [], char sequeence2 []){
	// Test même longueur
	if (strcmp(sequence1,sequeence2)==0){
		return 0;
	}
	int avancement=0;
	int nbDifferent=0;
	char c1=sequence1[0];
	char c2=sequeence2[0];
	while(c1!='\0' || c2!='\0'){
		if(c1!=c2){
			nbDifferent++;
		}
		avancement++;
		c1=sequence1[avancement];
		c2=sequeence2[avancement];
	}
	return nbDifferent;
}

Difference** computeDifferencesBetween(char sequence1 [], char sequence2 []){
	Difference* tab=malloc((nombreDeDifferences(sequence1, sequence2))*sizeof(Difference));
	int avancement=0;
	int diff=0;
	char c1=sequence1[0];
	char c2=sequence2[0];
	while(c1!='\0'){
		if(c1!=c2){
			Difference a;
			a.index=avancement;
			a.distance=distanceBetweenNucleotides(c1,c2);
			tab[diff]=a;
		}
		avancement++;
		c1=sequence1[avancement];
		c2=sequence2[avancement];
	}
	Difference** p = &tab;
	return p;
}

void printDifferences(Difference** a, int nbDifferent){
	printf("Les différences sont : ");
	for (int i=0;i<nbDifferent;i++){
		printf(" %d, %d",(*a)[i].index,(*a)[i].distance);
	}
	
}

// ========
// = Main =
// ========

int main(void){



	char sequenceDeNucleotides[]="ATGCATCCATCATGCATGTA";
	int * tab;
	tab=statistics(sequenceDeNucleotides);
	printf("Les pourcentages sont : %d, %d, %d, %d \n",tab[0],tab[1],tab[2],tab[3]);
	Difference** a;
	a=computeDifferencesBetween("ATGC","ATCG");
	int i = nombreDeDifferences("ATGC","ATCG");
	printDifferences(a, i);

    printf("%s\n",code_proteine_spike_moderna);

	return EXIT_SUCCESS;
}

