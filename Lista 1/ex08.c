#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//Objetivo:Elabore um programa que faça a leitura de vários números inteiros até que se digite
//um número negativo. O programa tem de retornar o maior e o menor número lido


int main()
{
    int n, maiorN, menorN;

    do
    {
        printf ("Numero:");
        scanf ("%d",&n);

        if (n>=maiorN){
            maiorN=n;
        }
        if (n<=menorN && n>=0){
            menorN=n;
        }
    } while (n>=0);
    
    
    printf ("Maior: %d\n", maiorN);
    printf ("Menor: %d\n", menorN);

    return 0;
}