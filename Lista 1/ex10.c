#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//Objetivo:Faça um programa que leia 10 inteiros e imprima sua média.

int main()
{
    int n, i;
    float nTotal=0;

    for (i = 0; i < 10; i++){
        printf ("Numero %d:", i+1);
        scanf ("%d",&n);
        nTotal=nTotal+n;
    }
    printf ("Media: %f", nTotal/10);

    return 0;
}