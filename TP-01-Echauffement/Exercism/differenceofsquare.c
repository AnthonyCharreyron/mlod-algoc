#include <stdio.h>
#include <math.h>
double differenceofsquare(double n);

int main(void) {
    printf("La différence est : %f \n", differenceofsquare(10));
    return 0;
}
double differenceofsquare(double n){
    double sommecarre = 0;
    double carresomme =0;
    double difference = 0;
    for (double k=1;k<=n;k++){
        sommecarre+= pow(k,2);
        carresomme+= k;
    }
    carresomme = pow(carresomme,2);
    difference= carresomme-sommecarre;
    return difference;
}

