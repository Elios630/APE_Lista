#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int le_valida_uf(char uf[], int val);
int le_valida_positivo();

int main() {
    
    typedef struct {
		char marca[40], site[40], uf[2], telefone[14];
	}Fabricante;

	typedef struct {
		char descricao[40];
        int peso;
        float valorCompra, valorVenda, valorLucro, percenLucro;
        Fabricante fabricante;
	}Produto;

    char DDD[2], DDDTotal[10], telefoneTotal[14], quatroPrimero[4], quatroUltimo[4], uf[2], bufferTel[14], bufferUF[2];
	int i=0, j=0, conFab=0, escolha, conProd, acabar=0,  validado=10;
    float maisCaro=0, maisBarato=10000;
    Fabricante fabricante[5];
    Produto produto[50];
    
    
    

	for(i=0;i<2;i++){
		printf("Informe o nome do fabricante %d: ", i+1);
		scanf("%s", &fabricante[i].marca);
		
		printf("Informe o site do fabricante %d: ", i+1);
		scanf("%s", &fabricante[i].site);

        printf("Informe o DDD: ");
		scanf("%s", &DDD);
        strcat(DDDTotal, "(");
        strcat(DDDTotal, DDD);
        strcat(DDDTotal, ") ");
        printf("Informe os primero quatro numeros do telefone: ");
		scanf("%s", &quatroPrimero);
        strcat(DDDTotal, quatroPrimero);
        printf("Informe os ultimos quatro numeros do telefone: ");
		scanf("%s", &quatroUltimo);
        strcat(telefoneTotal, DDDTotal);
        strcat(telefoneTotal, "-");
        strcat(telefoneTotal, quatroUltimo);
        for (j = 0; j < 14; j++){
            fabricante[i].telefone[j]=telefoneTotal[j];
        }

        do{
            printf("Informe a UF do Fabricante: ");
		    scanf("%s", &uf);
            
            for (j = 0; j < 2; j++){
                uf[j]=toupper(uf[j]);
            }
        validado=le_valida_uf(uf, validado);
        } while (validado==10);

        for (j = 0; j < 2; j++){
                fabricante[i].uf[j]=uf[j];
        }
        validado=10;
        
        
	}
    conFab=2;

    do{
        printf("Deseja adicionar mais fabricante?\n");
        printf("1-Sim\n");
        printf("2-Nao\n");
        scanf("%d", &escolha);
        switch (escolha){
            case 1:
                printf("Informe o nome do fabricante %d: ", conFab+1);
                scanf("%s", &fabricante[conFab].marca);
                
                printf("Informe o site do fabricante %d: ", conFab+1);
                scanf("%s", &fabricante[conFab].site);

                printf("Informe o DDD: ");
                scanf("%s", &DDD);
                strcat(DDDTotal, "(");
                strcat(DDDTotal, DDD);
                strcat(DDDTotal, ") ");
                printf("Informe os primero quatro numeros do telefone: ");
                scanf("%s", &quatroPrimero);
                strcat(DDDTotal, quatroPrimero);
                printf("Informe os ultimos quatro numeros do telefone: ");
                scanf("%s", &quatroUltimo);
                strcat(telefoneTotal, DDDTotal);
                strcat(telefoneTotal, "-");
                strcat(telefoneTotal, quatroUltimo);
                for (j = 0; j < 14; j++){
                    fabricante[conFab].telefone[j]=telefoneTotal[j];
                    }

                    do{
                        printf("Informe a UF do Fabricante: ");
                        scanf("%s", &uf);
                        
                        for (j = 0; j < 2; j++){
                            uf[j]=toupper(uf[j]);
                        }
                    validado=le_valida_uf(uf, validado);
                    } while (validado==10);

                    for (j = 0; j < 2; j++){
                            fabricante[conFab].uf[j]=uf[j];
                    }
                    validado=10;

                conFab++;
                break;

            case 2:
                acabar=5;
                break;
            
            default:
                break;
        }
    } while (conFab!=5 && acabar ==0);
    acabar=5;
    for(i=0;i<5;i++){
		printf("Informe a descricao do produto %d: ", i+1);
		scanf("%s", &produto[i].descricao);
		
        printf("Informe o numero do fabricante do produto %d: \n", i+1);

        for (j=0; j<conFab; j++){
            printf("Fabricante numero %d: %s\n", j+1, fabricante[j].marca);
        }
        do{
            scanf("%d", &escolha);
            switch (escolha){
                case 1:
                    produto[i].fabricante=fabricante[0];
                break;

                case 2:
                    produto[i].fabricante=fabricante[1];
                break;

                case 3:
                    if (conFab<3){
                        escolha=10;
                        break;
                    }
                    produto[i].fabricante=fabricante[2];
                break;

                case 4:
                    if (conFab<4){
                        escolha=10;
                        break;
                    }
                    produto[i].fabricante=fabricante[3];
                break;

                case 5:
                    if (conFab<5){
                        escolha=10;
                        break;
                    }
                    produto[i].fabricante=fabricante[4];
                break;
                
                default:
                    escolha=10;
                break;
            }
        } while (escolha==10);

        printf("Informe o peso produto %d: \n", i+1);
        produto[i].peso=le_valida_positivo();

        do{
            printf("Informe o valor de compra produto %d: \n", i+1);
            scanf("%f", &produto[i].valorCompra);
        } while (produto[i].valorCompra<0);

        do{
            printf("Informe o valor de venda produto %d: \n", i+1);
            scanf("%f", &produto[i].valorVenda);
        } while (produto[i].valorVenda<0);

        produto[i].valorLucro=produto[i].valorVenda-produto[i].valorCompra;
        produto[i].percenLucro=(produto[i].valorLucro/produto[i].valorVenda)*100;
	}
    conProd=5;

    do{
        printf("Deseja adicionar mais produtos?\n");
        printf("1-Sim\n");
        printf("2-Nao\n");
        scanf("%d", &escolha);
        switch (escolha){
            case 1:
                printf("Informe a descricao do produto %d: ", conProd+1);
                scanf("%s", &produto[conProd].descricao);
                
                printf("Informe o numero do fabricante do produto %d: \n", conProd+1);

                for (j=0; j<conFab; j++){
                    printf("Fabricante numero %d: %s\n", j+1, fabricante[j].marca);
                }
                do{
                    scanf("%d", &escolha);
                    switch (escolha){
                        case 1:
                            produto[conProd].fabricante=fabricante[0];
                        break;

                        case 2:
                            produto[conProd].fabricante=fabricante[1];
                        break;

                        case 3:
                            produto[conProd].fabricante=fabricante[2];
                        break;

                        case 4:
                            produto[conProd].fabricante=fabricante[3];
                        break;

                        case 5:
                            produto[conProd].fabricante=fabricante[4];
                        break;
                        
                        default:
                            escolha=10;
                        break;
                    }
                } while (escolha==10);

                printf("Informe o peso produto %d: \n", conProd+1);
                produto[conProd].peso=le_valida_positivo();

                do{
                    printf("Informe o valor de compra produto %d: \n", i+1);
                    scanf("%f", &produto[i].valorCompra);
                } while (produto[i].valorCompra<0);

                do{
                    printf("Informe o valor de venda produto %d: \n", i+1);
                    scanf("%f", &produto[i].valorVenda);
                } while (produto[i].valorVenda<0);

                produto[conProd].valorLucro=produto[conProd].valorVenda-produto[conProd].valorCompra;
                produto[conProd].percenLucro=(produto[conProd].valorLucro/produto[conProd].valorVenda)*100;
                conProd++;
                break;

            case 2:
                acabar=70;
                break;
            
            default:
                break;
        }
    } while (conProd!=50 && acabar ==5);

    do{
        printf("- [1] Listar todas as marcas\n");
        printf("- [2] Listar todos os produtos\n");
        printf("- [3] Listar os produtos de um determinado estado\n");
        printf("- [4] Listar os produtos de uma determinada marca\n");
        printf("- [5] Apresentar o(s) estado(s) onde esta registrado o produto mais caro\n");
        printf("- [6] Apresentar o(s) fabricante(s) onde esta registrado o produto mais barato\n");
        printf("- [7] Listar todos os produtos em ordem crescente de valor\n");
        printf("- [8] Listar todos os produtos em ordem crescente de maior \"valor do lucro\"\n");
        printf("- [9] Listar todos os produtos em ordem crescente de maior \"percentual de lucro\"\n");
        printf("- [0] Sair do programa\n");
        scanf("%d", &acabar);
        
        printf("%d\n", acabar);

        switch (acabar){
            
            case 1:
                printf("=====================================================================\n");
                printf("            RELATORIO 1 -LISTA DE TODAS AS MARCAS\n");
                printf("=====================================================================\n");
                printf("Marca\t|\tSite\t\t|\tTelefone\t|\tUF\n");
                
                for (i = 0; i < conFab; i++){
                    bufferTel[0] = '\0';
                    for (j = 0; j < 14; j++){
                    bufferTel[j]=fabricante[i].telefone[j];
                    }
                    bufferUF[0] = '\0';
                    for (j = 0; j < 2; j++){
                    bufferUF[j]=fabricante[i].uf[j];
                    }
                    printf("--------+-----------------------+-----------------------+------------\n");
                    printf("%s\t|\t%s\t|\t%s\t|\t%s\n", fabricante[i].marca, fabricante[i].site, bufferTel, bufferUF);
                }
                printf("--------+-----------------------+-----------------------+------------\n");
                printf("\n");
                do{
                    printf("- [0] Voltar para tela principal\n");
                    printf("- [9] Sair do programa\n");
                    printf("=====================================================================\n");
                    scanf("%d", &escolha);
                } while (escolha!=9 && escolha!=0);
                if (escolha==9){
                   acabar=1000;
                }
                break;
            case 2:
                printf("==================================================================================================================================================\n");
                printf("                                              RELATORIO 2 -LISTA DE TODOS OS PRODUTOS\n");
                printf("==================================================================================================================================================\n");
                printf("Descricao\t\t|\tMarca\t|\tpeso\t|\tV. de compra\t|\tV. de venda\t|\tLucro\t|\tPer. de lucro\n");

                for (i = 0; i < conProd; i++){
                    printf("------------------------+---------------+---------------+-----------------------+-----------------------+---------------+-------------------------\n");
                    printf("%s\t\t|\t%s\t|\t%d\t|\t%f\t|\t%f\t|\t%f\t|\t%f\n", produto[i].descricao, produto[i].fabricante.marca, produto[i].peso, produto[i].valorCompra, produto[i].valorVenda, produto[i].valorLucro, produto[i].percenLucro);
                }
                printf("------------------------+---------------+---------------+-----------------------+-----------------------+---------------+-------------------------\n");
                printf("\n");
                do{
                    printf("- [0] Voltar para tela principal\n");
                    printf("- [9] Sair do programa\n");
                    printf("==================================================================================================================================================\n");
                    scanf("%d", &escolha);
                } while (escolha!=9 && escolha!=0);
                if (escolha==9){
                   acabar=1000;
                }
                break;
            case 3:
                /* code */
                break;
            case 4:
                /* code */
                break;
            case 5:
                printf("===============================================================================\n");
                printf("                  RELATORIO 5 - ESTADO DOS PRODUTOS MAIS CAROS\n");
                printf("===============================================================================\n");
                
                printf("UF\t|\tV. de venda\n");
                 for (i = 0; i < conProd; i++){
                    if (produto[i].valorVenda>maisCaro){
                        maisCaro=produto[i].valorVenda;
                    }
                    
                }

                for (i = 0; i < conProd; i++){
                    if (produto[i].valorVenda==maisCaro){
                        printf("--------+----------------------------------------------------------------------\n");
                        printf("%s\t|\t%f\n", produto[i].fabricante.uf, produto[i].valorVenda);
                    }
                }
                printf("--------+----------------------------------------------------------------------\n");
                printf("\n");
                do{
                    printf("- [0] Voltar para tela principal\n");
                    printf("- [9] Sair do programa\n");
                    printf("===============================================================================\n");
                    scanf("%d", &escolha);
                } while (escolha!=9 && escolha!=0);
                if (escolha==9){
                   acabar=1000;
                }
                
                break;
            case 6:
                printf("===============================================================================\n");
                printf("              RELATORIO 6 - FABRICANTES DOS PRODUTOS MAIS BARATOS\n");
                printf("===============================================================================\n");
                
                printf("Marca\t|\tV. de venda\n");
                for (i = 0; i < conProd; i++){
                    if (produto[i].valorVenda<maisBarato){
                        maisBarato=produto[i].valorVenda;
                    }
                    
                }
                
                for (i = 0; i < conProd; i++){
                    if (produto[i].valorVenda==maisBarato){
                        printf("--------+----------------------------------------------------------------------\n");
                        printf("%s\t|\t%f\n", produto[i].fabricante.marca, produto[i].valorVenda);
                    }
                }
                printf("--------+----------------------------------------------------------------------\n");
                printf("\n");
                do{
                    printf("- [0] Voltar para tela principal\n");
                    printf("- [9] Sair do programa\n");
                    printf("===============================================================================\n");
                    scanf("%d", &escolha);
                } while (escolha!=9 && escolha!=0);
                if (escolha==9){
                   acabar=1000;
                }
                break;
            case 7:
                /* code */
                break;
            case 8:
                /* code */
                break;
            case 9:
                /* code */
                break;
            case 0:
                acabar=1000;
                break;
            default:
                break;
        }
    } while (acabar!=1000);
    


    return 0;
}

int le_valida_uf(char uf[], int val){
	
    val=10;
        
        if (uf[0]=='A'){
            if (uf[1]=='C'){
                val=0;
            }else if (uf[1]=='L'){
                val=0;
            }else if (uf[1]=='P'){
                val=0;
            }else if (uf[1]=='M'){
                val=0;
            }
        }else if (uf[0]=='B') {
            if (uf[1]=='A')
                val=0;
        }else if (uf[0]=='C') {
            if (uf[1]=='E')
                val=0;
        }else if (uf[0]=='D') {
            if (uf[1]=='F')
                val=0;;
        }else if (uf[0]=='E') {
            if (uf[1]=='S')
                val=0;
        }else if (uf[0]=='G') {
            if (uf[1]=='O')
                val=0;  
        }else if (uf[0]=='M'){
            if (uf[1]=='A'){
                val=0;
            }else if (uf[1]=='T'){
                val=0;
            }else if (uf[1]=='S'){
                val=0;
            }else if (uf[1]=='G'){
                val=0;
            }
        }else if (uf[0]=='P'){
            if (uf[1]=='A'){
                val=0;
            }else if (uf[1]=='B'){
                val=0;
            }else if (uf[1]=='R'){
                val=0;
            }else if (uf[1]=='E'){
                val=0;
            }else if (uf[1]=='I'){
                val=0;
            }
        }else if (uf[0]=='R'){
            if (uf[1]=='J'){
                val=0;
            }else if (uf[1]=='N'){
                val=0;
            }else if (uf[1]=='S'){
                val=0;
            }else if (uf[1]=='O'){
                val=0;
            }else if (uf[1]=='R'){
                val=0;
            }
        }else if (uf[0]=='S'){
            if (uf[1]=='C'){
                val=0;
            }else if (uf[1]=='P'){
                val=0;
            }else if (uf[1]=='E'){
                val=0;
            }
        }else if (uf[0]=='T'){
            if (uf[0]=='O')
                val=0;
        }
        
        
    return val;

	
}

int le_valida_positivo(){
    int num;

    do{
        printf("Informe: ");
        scanf("%d", &num);
    } while (num<0);
    

    return num;
}
