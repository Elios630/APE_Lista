#include <stdio.h>
#include <string.h>

int le_valida_idade();

int main() {

	typedef struct {
		char nome[40],funcional[40],titulacao[15];
	}Professor;

    typedef struct {
		char nome[40];
		int matricula, idade;
	}Estudante;

    typedef struct  {
        char nome[40];
        int codigo, carga_horaria,matricula;
        Professor professor_responsavel;
        Estudante estudante[10];
    }Disciplina;

	int i=0, j=0, escolha, NumAlunos=0, para, tam1=0, tam2=0, aux;
	Professor professor[3];
    Disciplina disciplina[2];
    Estudante estudante[15];
	
	for(i=0;i<3;i++){
		printf("Informe o nome do Professor %d: ", i+1);
		scanf("%s", &professor[i].nome);
		
		printf("Informe o funcional do Professor %d: ", i+1);
		scanf("%s", &professor[i].funcional);

        printf("Informe a titulacao do Professor %d: ", i+1);
		scanf("%s", &professor[i].titulacao);
	}

    for(i=0;i<2;i++){
		printf("Informe o nome da disciplina %d: ", i+1);
		scanf("%s", &disciplina[i].nome);
		
		printf("Informe o codigo da disciplina %d: ", i+1);
		scanf("%d", &disciplina[i].codigo);

        printf("Informe a carga horaria da disciplina %d: ", i+1);
		scanf("%d", &disciplina[i].carga_horaria);

        printf("Informe a matricula da disciplina %d: ", i+1);
		scanf("%d", &disciplina[i].matricula);

        printf("Informe o numero do professor da disciplina %d: \n", i+1);
        for (j=0; j<3; j++){
            printf("Professor numero %d: %s\n", j+1, professor[j].nome);
        }
        do{
            scanf("%d", &escolha);
            switch (escolha){
                case 1:
                    disciplina[i].professor_responsavel=professor[0];
                break;

                case 2:
                    disciplina[i].professor_responsavel=professor[1];
                break;

                case 3:
                    disciplina[i].professor_responsavel=professor[2];
                break;
                
                default:
                    escolha=10;
                break;
            }
        } while (escolha==10);
	}

    for (i = 0; i < 10; i++){
        printf("Deseja adicionar alunos na disciplina %d: \n", 1);
        do{
            printf("1 - Sim\n");
            printf("2 - Não\n");
            scanf("%d", &escolha);
        } while (escolha!=1 && escolha!=2);
        if (escolha==1){
            
            printf("Informe o nome do estudante %d: ", i+1);
            scanf("%s", &disciplina[0].estudante[NumAlunos].nome);
            
            printf("Informe o matricula do estudante %d: ", i+1);
            scanf("%d", &disciplina[0].estudante[NumAlunos].matricula);
            
            disciplina[0].estudante[NumAlunos].idade=le_valida_idade();
            
        }else if (escolha==2){
            break;
        }
        NumAlunos++;
        tam1++;
    }

    for (i = NumAlunos; i < 15; i++){
        printf("Deseja adicionar alunos na disciplina %d: \n", 2);
        do{
            printf("1 - Sim\n");
            printf("2 - Não\n");
            scanf("%d", &escolha);
        } while (escolha!=1 && escolha!=2);
        if (escolha==1){
            
            printf("Informe o nome do estudante %d: ", i+1);
            scanf("%s", &disciplina[1].estudante[i].nome);
            
            printf("Informe o matricula do estudante %d: ", i+1);
            scanf("%d", &disciplina[1].estudante[i].matricula);
            
            disciplina[1].estudante[i].idade=le_valida_idade();
            
        }else if (escolha==2){
            break;
        }
        NumAlunos++;
        tam2++;
    }

    for (i = 0; i < tam1 - 1; i++) {
        for (j = 0; j < tam1 - i - 1; j++) {
            if (disciplina[0].estudante[j].idade > disciplina[0].estudante[j + 1].idade) {
                aux = disciplina[0].estudante[j].idade;
                disciplina[0].estudante[j].idade = disciplina[0].estudante[j + 1].idade;
                disciplina[0].estudante[j + 1].idade = aux;
            }
        }
    }

    for (i = 0; i < tam1 - 1; i++) {
        printf("codigo_disciplina: %d\tnome_professor: %s\tnome_estudante: %s\tidade_estudante %d\n", disciplina[0].codigo, disciplina[0].professor_responsavel.nome, 
        disciplina[0].estudante[i].nome, disciplina[0].estudante[i].idade);
    }

    for (i = 0; i < tam1 - 1; i++) {
        for (j = 0; j < tam1 - i - 1; j++) {
            if (disciplina[1].estudante[j].idade < disciplina[1].estudante[j + 1].idade) {
                aux = disciplina[1].estudante[j].idade;
                disciplina[1].estudante[j].idade = disciplina[1].estudante[j + 1].idade;
                disciplina[1].estudante[j + 1].idade = aux;
            }
        }
    }

    for (i = 0; i < tam1 - 1; i++) {
        printf("codigo_disciplina: %d\tnome_professor: %s\tnome_estudante: %s\tidade_estudante %d\n", disciplina[1].codigo, disciplina[1].professor_responsavel.nome, 
        disciplina[1].estudante[i].nome, disciplina[1].estudante[i].idade);
    }
}

int le_valida_idade(){
	
	int idade=0;
	
	do{
		printf("Informe a idadedo estudante: ");
		scanf("%d", &idade);
	}while(idade<16 || idade>26);
	
	return idade;
}