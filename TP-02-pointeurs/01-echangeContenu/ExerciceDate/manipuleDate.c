#include "manipuleDate.h"

void initialiseDate(Date *d){ //verifier que la date est valide avec do et if
    printf("jour : ");
    scanf("%hu",&d->jour);
    printf("mois : ");
    scanf("%d",(int *)&d->mois);
    printf("annee : ");
    scanf("%hu",&d->annee);
}

void afficheDate(Date* pd){
    printf("La date est : %hu %d %hu",pd->jour,pd->mois,pd->annee);
}

char* libelleDate(Mois m){
    char* nomDesMois[]={"Janvier","Fevrier","Mars",
                        "Avril","Mai","Juin","Juillet",
                        "Aout","Septembre","Octobre",
                        "Novembre","Decembre"};
    return nomDesMois[m-1];
}

Date creerDateParCopie(void){ 
    Date d;
    printf("jour : ");
    scanf("%hu",&d.jour);
    printf("mois : ");
    scanf("%d",(int *)&d.mois);
    printf("annee : ");
    scanf("%hu",&d.annee);
    return d;
}//Autre maniere : utiliser initialiseDate(&d) a la place des printf et scanf

Date* newDate(void){
    Date* date = (Date *) malloc(sizeof(Date));
    printf("jour : ");
    scanf("%hu",&date->jour);
    printf("mois : ");
    scanf("%d",(int *)&date->mois);
    printf("annee : ");
    scanf("%hu",&date->annee);
    return date;
}

unsigned int nbreJours(Mois mois, unsigned int annee){
    switch (mois)
    {
    case janvier:
    case mars:
    case mai:
    case juillet:
    case aout:
    case octobre:
    case decembre:
        return 31;
    case avril:
    case juin:
    case septembre:
    case novembre:
        return 30;
    case fevrier:
        if(anneeBissextile(annee)){
            return 29;
        }
        return 28;
    default:
        return 0;
    }
}

bool anneeBissextile(unsigned int annee){
    if(annee%4==0){
        return true;
    }
    return false;
}

bool dateValide(Date uneDate){
    int j, m, a;
    j=uneDate.jour;
    m=uneDate.mois;
    a=uneDate.annee;
    if (m<1 || m>12){
        return false;
    }
    if (j<1 || j>nbreJours(m,a)){
        return false;
    }
    return true;    
}

unsigned int jourDansAnnee(Date uneDate){
    unsigned int nbjours=0;
    for (int i=1; i<uneDate.mois;i++){
        nbjours+= nbreJours(i,uneDate.annee);
    }
    nbjours+=uneDate.jour;
    return nbjours;
}
