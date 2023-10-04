#include "arbre-bin-recherche.h"
#include <stdlib.h>
#include <stdbool.h>

// retourne TRUE si a est l'arbre vide et FALSE sinon
bool estVide(ArbreBinaire a) {
	return true;
}

// initialise l'arbre a à l'arbre vide
void initialiser(ArbreBinaire* a) {
	*a = NULL;
}

// créer un arbre contenant un seul noeud ayant la valeur e
ArbreBinaire creer(Element e) {
	ArbreBinaire new=malloc(sizeof(Noeud));
	new->val=e;
	new->filsGauche=NULL; // equivalent à initialiser(&new->filsGauche)
	new->filsDroit=NULL;
	return new;
}

// insere e dans a sachant que a est un arbre binaire de recherche
// si a contient déjà un element e, ce dernier n'est pas insérer afin d'éviter les doublons
// version itérative
ArbreBinaire insere_i(ArbreBinaire a, Element e) {
	ArbreBinaire parcours=a;
	while(!estVide(a)){
		ArbreBinaire gauche=parcours->filsGauche;
		ArbreBinaire droite=parcours->filsDroit;
		if (e == parcours->val){
			return a;
		}
		else if ( e < gauche->val){
			parcours=gauche;
		}
		else {
			parcours=droite;
		}
	}
	parcours=creer(e);
	return a;
}	

// insere e dans a sachant que a est un arbre binaire de recherche
// si a contient déjà un element e, ce dernier n'est pas insérer afin d'éviter les doublons
// version récursive
ArbreBinaire insere_r(ArbreBinaire a, Element e) {
	if(!estVide(a)){
		ArbreBinaire gauche=a->filsGauche;
		ArbreBinaire droite=a->filsDroit;
		if (e == a->val){
			return a;
		}
		else if ( e < gauche->val){
			a->filsGauche=insere_r(gauche,e);
		}
		else {
			a->filsDroit=insere_r(droite,e);
		}
	}
	a=creer(e);
	return a;
	}


// retourne le nombre de noeud contenus dans l'arbre a
int nombreDeNoeud(ArbreBinaire a){
	if (estVide(a)){
		return 0;
	}
	return 1 + nombreDeNoeud(a->filsGauche) + nombreDeNoeud(a->filsDroit);
}

// retourne la profondeur du noeud ayant la valeur e dans a
// retourne -1 si a est vide ou si e n'est pas dans a
int profondeur(ArbreBinaire a, Element e){
	if (estVide(a)){
		return -1;
	}
	int profondeur = 1;
	ArbreBinaire parcours=a;
	while(!estVide(a)){
		ArbreBinaire gauche=parcours->filsGauche;
		ArbreBinaire droite=parcours->filsDroit;
		if (e == parcours->val){
			return profondeur;
		}
		else if ( e < gauche->val){
			parcours=gauche;
		}
		else {
			parcours=droite;
		}
		profondeur++;
	}
	return -1;
}

// retourne la hauteur de l'arbre a
int hauteur(ArbreBinaire a){
	if (estVide(a)){
		return -1;
	}
	int max=a->val;
	ArbreBinaire parcours=a;
	// while(!estVide(a)){
	// 	ArbreBinaire gauche=parcours->filsGauche;
	// 	ArbreBinaire droite=parcours->filsDroit;
	// 	if() {
	// 		parcours=droite;
	// 	}
	// }
	return 0;
}

// retourne le pere de elem dans l'arbre a ou NULL s'il n'existe pas
ArbreBinaire pere(ArbreBinaire a, Element elem){

	return NULL;
}


void afficheRGD_r(ArbreBinaire a){ //Afficher Racine Gauche Droite
	
}

void afficheGRD_r(ArbreBinaire a){ //Afficher Gauche Racine Droite
}

void afficheGDR_r(ArbreBinaire a){ //Afficher Gauche Droite Racine
}

// retourne le noeud dont la valeur est minimum dans l'arbre
// Suppose que a est un arbre binaire de recherche sans doublons
ArbreBinaire min(ArbreBinaire a){
	return NULL;
}

// retourne le noeud dont la valeur est maximum dans l'arbre
// Suppose que a est un arbre binaire de recherche sans doublons
ArbreBinaire max(ArbreBinaire a){
	return NULL;
}


// retourne l'arbre dont la valeur de la racine est elem et NULL si elem n'existe dans a 
// version récursive
ArbreBinaire recherche_r(ArbreBinaire a, Element elem){

	return NULL;
}


// suppime x de a
ArbreBinaire supprimer_r(ArbreBinaire a,Element x)
{

	return NULL;
}

void detruire_r(ArbreBinaire a){

}

