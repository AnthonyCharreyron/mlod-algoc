#include "matrice2.h"


Matrice* creer(int valeur,uint16_t ligne,uint16_t colonne){
    Matrice* m;
    m = (Matrice*)malloc(sizeof(Matrice));
    m->nbLignes=ligne;
    m->nbColonnes=colonne;
    m->valeurs=(int**)malloc(ligne*sizeof(int*));
    for (int i=0;i<ligne;i++){
        m->valeurs[i]=(int*)malloc(colonne*sizeof(int));
        for (int j=0;j<colonne;j++){
            m->valeurs[i][j]=valeur;
        }    
    }
    return m;
}

void printMatrice(Matrice* A){
    for (int i=0;i<A->nbLignes;i++){
        for (int j=0;j<A->nbColonnes;j++){
            printf(" %d \t",A->valeurs[i][j]);
        }
        printf("\n");
        }
}

void initialiserLigne(int v, uint16_t l, Matrice* m){
    for (int j=0;j<m->nbColonnes;j++){
        m->valeurs[l][j]=v;
    }
}

