#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//Objetivo:Escreva um programa que leia um número inteiro, maior ou igual a zero, do usuário.
//Imprima o enésimo termo da sequência de Fibonacci. Essa sequência começa no termo de
//ordem zero, e, a partir do segundo termo, seu valor é dado pela soma dos dois termos
//anteriores. Alguns termos dessa sequência são: 0, 1, 1, 2, 3, 5, 8, 13, 21, 34

int main()
{
    int n, i, res[2];
    res[0]=0;
    res[1]=0;
    res[2]=0;

    printf ("Numero:");
    scanf ("%d",&n);

    const int pos=n;

    for (i = 1; i < pos; i++){
        if (res[0]==0){
            res[0]=1;
        }else if (res[1]==0){
            res[1]=1;
            res[2]=1;
            
        }else{
            res[0]=res[1];
            res[1]=res[2];
            res[2]=res[0]+res[1];
        }
    }
    
    printf ("Enésimo termo da sequência de Fibonacci: %d\n", res[2]);

    return 0;
}