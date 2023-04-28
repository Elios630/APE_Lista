#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//Objetivo:Faça um algoritmo que leia um número positivo e imprima seus divisores. Exemplo:
//Os divisores do número 66 são: 1, 2, 3, 6, 11, 22, 33 e 66.


int main()
{
    int n, i;

    printf ("Numero:");
    scanf ("%d",&n);

    for (i = 1; i < n+1; i++){
        if (n%i==0)
        {
            printf ("%d\n", i);
        }
    }

    return 0;
}