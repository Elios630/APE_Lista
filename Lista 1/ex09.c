#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//Objetivo:Elabore um algoritmo que permita ao usuário realizar a compra de frutas. Assim,
//apresente a lista de frutas disponíveis, abaixo, com seus respectivos valores. O algoritmo
//deve permitir ao usuário retomar o menu frutas quantas vezes quiser, e solicitar a quantidade
//de frutas. Ao final, apresente o valor total da compra. 


int main()
{
    int n, total=0, quant;

    do{
        printf ("---------------------------------\n");
        printf ("1 => ABACAXI - 5,00 a unidade\n");
        printf ("2 => MAÇA - 1,00 a unidade\n");
        printf ("3 => PERA - 4,00 a unidade\n");
        printf ("4 => Sair\n");
        printf ("---------------------------------\n");
        printf ("Opcao:");
        scanf ("%d",&n);

        switch (n){
            case 1:
                printf ("Quantidade:");
                scanf ("%d",&quant);
                total=total+quant*5;
            break;
            case 2:
                printf ("Quantidade:");
                scanf ("%d",&quant);
                total=total+quant*1;
            break;
            case 3:
                printf ("Quantidade:");
                scanf ("%d",&quant);
                total=total+quant*4;
            break;
        
            default:

            break;
        }
    } while (n!=4);
    
    
    printf ("Valor total: %d\n", total);

    return 0;
}