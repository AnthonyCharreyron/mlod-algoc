#include <stdio.h>
#include "echangeContenu.h"

void echangeContenu(int *a, int *b);

int main(void){
	int a=4,b=14;
	printf ("a = %d\tb = %d\n", a, b);
	echangeContenu(&a,&b);
	printf ("a et b echanges \n");
	printf ("a = %d\tb = %d\n", a, b);

	return 0;
}

