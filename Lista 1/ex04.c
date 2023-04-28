#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//Objetivo:Leia 2 valores com uma casa decimal (x e y), que devem representar as coordenadas
//de um ponto em um plano. A seguir, determine qual o quadrante ao qual pertence o ponto, ou
//se está sobre um dos eixos cartesianos ou na origem (x = y = 0). Se o ponto estiver na origem,
//escreva a mensagem “Origem”. Se o ponto estiver sobre um dos eixos escreva “Eixo X” ou
//“Eixo Y”, conforme for a situação



int main()
{
    float x,y;

    printf ("x:");
    scanf ("%f",&x);
    printf ("y:");
    scanf ("%f",&y);

    if (x==0 && y==0){
        printf ("Origem");
    }else if (x==0){
        printf ("Eixo X");
    }else if (y==0){
        printf ("Eixo Y");
    }else{
        if (x>0){
            if (y>0){
                printf ("Q1");
            }else{
                printf ("Q4");
            }
            
        }else if (y>0){
            printf ("Q2");
        }else{
            printf ("Q3");
        }
    }

    return 0;
}