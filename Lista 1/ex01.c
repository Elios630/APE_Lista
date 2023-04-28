#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//Objetivo:Leia quatro valores inteiros A, B, C e D. A seguir, calcule e mostre a diferença do
//produto de A e B pelo produto de C e D segundo a fórmula: DIFERENCA = (A * B - C * D).
//Apresente o resultado da seguinte forma:
//DIFERENCA = (“valor de A” * “valor de B” - ““valor de C” * ““valor de D”)
//DIFERENCA = (“valor de DIFERENCA”)


int main()
{
    int A, B, C, D, res;

    scanf ("%d",&A);
    scanf ("%d",&B);
    scanf ("%d",&C);
    scanf ("%d",&D);

    printf("DIFERENCA = (%d * %d - %d * %d)\n",A,B,C,D);
    res=A * B - C * D;
    printf("DIFERENCA = %d"), res;

   return 0;
}