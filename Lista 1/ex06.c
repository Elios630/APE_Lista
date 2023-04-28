#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//Objetivo:Faça um programa que exiba a soma de todos os números naturais abaixo de 1.000
//que são múltiplos de 3 ou 5.



int main()
{
    int i;

    for (i = 1; i < 1000; i++){
        if (i%3==0 || i%5==0)
        {
            printf ("%d\n", i);
        }
    }

    return 0;
}