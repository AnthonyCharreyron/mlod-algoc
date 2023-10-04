// gcc -W -Wall -std=c99 liste-chainee.c liste-chainee-main.c -o liste-chaine-main
// gcc -W -Wall -Wno-unused-parameter -std=c99 liste-chainee.c liste-chainee-main.c -o liste-chaine-main

#include "linkedList.h"
#include <stdlib.h>
#include <stdio.h>

bool equalsElement(Element e1, Element e2){
	return strcmp((char*)e1,(char*)e2) == 0;
}

void detruireElement(Element e){} // Pas de malloc, sinon free((char*)e)

void afficheElement(Element e) {
	printf("%s ",(char*)e);
}

int main(void){
	Liste l,p;

	l = NULL;
	printf("estVide(l) = %s\n",estVide(l)?"TRUE":"FALSE");
	
	l = ajoutTete("Bonjour",l);
	l = ajoutTete("je",l);
	l = ajoutTete("livre",l);
	l = ajoutTete("avoir",l);
	l = ajoutTete("demain",l);
	l = ajoutTete("Bonjour",l);
	l = ajoutTete("livre",l);
	l = ajoutTete("Anna",l);
	l = ajoutTete("toi",l);
	
	afficheListe_i(l);
	printf("\n");
	afficheEnvers_r(l);
	printf("\n");
	
	ajoutFin_i("long",l);
	afficheListe_i(l);
	
	ajoutFin_r("jour",l);
	afficheListe_i(l);

	p = cherche_i("hors",l);
	printf("cherche_i(hors) : %s\n",estVide(p)?"pas trouve":"[ERREUR] trouve !!!");

	p = cherche_i("long",l);
	if(estVide(p))
		printf("cherche_i(long) : [ERREUR] pas trouve \n");
	else {
		printf("cherche_i(long) : trouve ");
		afficheElement(p->val);
		printf("\n");
	}

	p = cherche_r("hors",l);
	printf("cherche_r(hors) : %s\n",estVide(p)?"pas trouve":"[ERREUR] trouve !!!");

	p = cherche_r("long",l);
	if(estVide(p))
		printf("cherche_r(long) : [ERREUR] pas trouve \n");
	else {
		printf("cherche_r(long) : trouve ");
		afficheElement(p->val);
		printf("\n");
	}

	printf("retirePremier_i(Bonjour)   : ");
	l = retirePremier_i("Bonjour",l);
	afficheListe_r(l);

	printf("retirePremier_i(Bonjour)   : ");
	l = retirePremier_i("Bonjour",l);
	afficheListe_r(l);

	printf("retirePremier_i(jour) : ");
	l = retirePremier_i("jour",l);
	afficheListe_r(l);

	printf("retirePremier_r(livre)   : ");
	l = retirePremier_r("livre",l);
	afficheListe_r(l);

	printf("retirePremier_r(livre)   : ");
	l = retirePremier_r("livre",l);
	afficheListe_r(l);

	printf("retirePremier_r(jour)  : ");
	l = retirePremier_r("jour",l);
	afficheListe_r(l);

	
	detruire_i(l);

	return EXIT_SUCCESS;
}