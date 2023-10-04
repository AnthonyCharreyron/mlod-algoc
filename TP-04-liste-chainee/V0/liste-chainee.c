#include "liste-chainee.h"
#include <stdlib.h>
#include <stdio.h>

#define TODO NULL;

// retourne vrai si l est vide et faux sinon
bool estVide(Liste l) {
	return l == NULL;
}

// créer une liste d'un seul élément contenant la valeur v
Liste creer(Element v){
	Liste l=(Liste)malloc(sizeof(Cellule));
	l->val=v;
	l->suiv=NULL;
	return l;
}

// ajoute l'élément v en tete de la liste l
Liste ajoutTete(Element v, Liste l) {
	Liste entete=creer(v);
	entete->suiv=l;
	return entete;
}


void afficheElement(Element e) {
	printf("%i ",e);
}

// affiche tous les éléments de la liste l
// Attention, cette fonction doit être indépendante du type des éléments de la liste
// utiliser une fonction annexe affiche_element
// Attention la liste peut être vide !
// version itérative
void afficheListe_i(Liste l) {
	Liste p=l;
	while (!estVide(p)){
		afficheElement(p->val);
		p=p->suiv;
	}
	printf("\n");
}

// version recursive
void afficheListe_r(Liste l) {
	if (l!=NULL){
		afficheElement(l->val);
		afficheListe_r(l->suiv);
	}
	else {
		printf("\n");
	}
}

//Fonction vide, utile lorsque qu'on va changer d'éléments. On prévoit de l'espace pour détruire
void detruireElement(Element e) {}

// Détruit tous les éléments de la liste l
// version itérative
void detruire_i(Liste l) {
	while (l!=NULL){
		Liste suivant=l->suiv;
		detruireElement(l->val);
		free(l);
		l=suivant;
	}
}

// version récursive
void detruire_r(Liste l) {
	if (l!=NULL){
		Liste suivant=l->suiv;
		detruire_r(suivant);
		detruireElement(l->val);
		free(l);
	}
}

// retourne la liste dans laquelle l'élément v a été ajouté en fin
// version itérative
Liste ajoutFin_i(Element v, Liste l) {
	Liste res=creer(v);
	Liste p=l;
	if(estVide(p)){
		return res;
	}
	while (!estVide(p->suiv)){
		p=p->suiv;
	}
	p->suiv=res;
	return p;
}

// version recursive
Liste ajoutFin_r(Element v, Liste l) {
	if(!estVide(l)){
		l->suiv=ajoutFin_r(v,l->suiv);
		return l;
	}
	Liste p=creer(v);	
	return p;
}

// compare deux elements
bool equalsElement(Element e1, Element e2){
	return e1 == e2;
}

// Retourne un pointeur sur l'élément de la liste l contenant la valeur v ou NULL
// version itérative
Liste cherche_i(Element v,Liste l) {
	Liste p=l;
	while(!estVide(p) && !equalsElement(v,p->val)){
		p=p->suiv;
	}
	return p;
}

// version récursive
Liste cherche_r(Element v,Liste l) {
	if(!estVide(l) && !equalsElement(v,l->val)){
		l=cherche_r(v,l->suiv);
	}
	return l;
}

// Retourne la liste modifiée dans la laquelle le premier élément ayant la valeur v a été supprimé
// ne fait rien si aucun élément possède cette valeur
// version itérative
Liste retirePremier_i(Element v, Liste l) {
	Liste courant=l;
	Liste suivant=courant->suiv;
	if(equalsElement(v,l->val)){
		detruireElement(courant->val);
		free(courant);
		return suivant;
	}
	while(!estVide(suivant) && !equalsElement(v,suivant->val)){
		courant=courant->suiv;
		suivant=courant->suiv;
	}
	if(!estVide(courant)){
		courant->suiv=suivant->suiv;
		detruireElement(suivant->val);
		free(suivant);
	}
	return l;
}


// version recursive
Liste retirePremier_r(Element v, Liste l) {
	if (estVide(l)){
		return l;
	}
	if (equalsElement(v, l->val)) {
        Liste temp = l->suiv;
        detruireElement(l->val);
        free(l);
        return temp;
    }
	l->suiv = retirePremier_r(v, l->suiv);
    return l;
}


void afficheEnvers_r(Liste l) {
	if(!estVide(l)){
		afficheEnvers_r(l->suiv);
		afficheElement(l->val);
	}
}



