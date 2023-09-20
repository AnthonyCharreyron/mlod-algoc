#pragma once

// TODO: definir echangeContenu

void echangeContenu (int *a, int *b){
    int c=*a;
    *a=*b;
    *b= c;
}