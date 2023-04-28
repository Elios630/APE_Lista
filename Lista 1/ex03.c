#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//Objetivo:Faça um programa que calcule e mostre a área da superfície e o volume de uma esfera
//sendo fornecido o valor de seu raio (R). A fórmula para calcular o volume é: (4/3) * pi * R³. A
//fórmula para calcular a área é: 4 * pi * R². Considere (atribua) para pi o valor 3.14159. Use o
//conceito de constante Dica: Ao utilizar a fórmula, procure usar (4/3.0) ou (4.0/3), pois algumas
//linguagens (dentre elas o C++), assumem que o resultado da divisão entre dois inteiros é
//outro inteiro




int main()
{
    float R,area,vol;
    const float pi = 3.14159f;

    printf ("Raio:");
    scanf ("%f",&R);

    area=(4.0*pi*R*R*R)/3.0;
    vol=4*pi*R*R;
    
    printf("Area %f\n", area);
    printf("Volume %f", vol);
    
    return 0;
}