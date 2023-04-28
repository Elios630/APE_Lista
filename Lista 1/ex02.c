#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//Objetivo:Leia os quatro valores correspondentes aos eixos x e y de dois pontos quaisquer no
//plano, p1(x1, y1) e p2(x2, y2) e calcule a distância entre eles, mostrando 4 casas decimais
//após a vírgula, segundo a fórmula:



int main()
{
    float x1,x2,y1,y2,res;
    float distancia;

    printf ("x1:");
    scanf ("%f",&x1);
    printf ("y1:");
    scanf ("%f",&y1);
    printf ("x2:");
    scanf ("%f",&x2);
    printf ("y2:");
    scanf ("%f",&y2);

    res = sqrt( pow(x2-x1, 2) + pow(y2-y1, 2) );

    printf("%.4f", res);
    
    return 0;
}