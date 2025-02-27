#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

void registro() {
	setlocale(LC_ALL, "Portuguese");
    char arquivo[40];
    char cpf[40];
    char nome[40];
    char sobrenome[40];
    char cargo[40];
    
    printf("Digite o seu CPF: ");
    scanf("%s", cpf);
    
    strcpy(arquivo, cpf);
    
    FILE *file;
    file = fopen(arquivo, "w");
    fprintf(file, "%s", cpf);
    fclose(file);
    
    file = fopen(arquivo, "a");
    fprintf(file, ",");
    fclose(file);
    
    printf("Digite o seu Nome: ");
    scanf("%s", nome);
    
    file = fopen(arquivo, "a");
    fprintf(file, "%s", nome);
    fclose(file);
    
    file = fopen(arquivo, "a");
    fprintf(file, ",");
    fclose(file);
    
    printf("Digite o seu sobrenome: ");
    scanf("%s", sobrenome);
    
    file = fopen(arquivo, "a");
    fprintf(file, "%s", sobrenome);
    fclose(file);
    
    file = fopen(arquivo, "a");
    fprintf(file, ",");
    fclose(file);
    
    printf("Digite o seu cargo: ");
    scanf("%s", cargo);
    
    file = fopen(arquivo, "a");
    fprintf(file, "%s", cargo);
    fclose(file);
}

int consulta() {
    setlocale(LC_ALL, "Portuguese");
    
    char cpf[40];
    char conteudo[200];
    
    printf("Digite o CPF a ser consultado: ");
    scanf("%s", cpf);
    
    FILE *file;
    file = fopen(cpf, "r");
    
    if (file == NULL) {
        printf("N�o foi poss�vel abrir o arquivo, arquivo n�o localizado.\n");
    }
    
    while (fgets(conteudo, 200, file) != NULL) {
        printf("\nEssas s�o as informa��es do usu�rio:\n");
        printf("%s", conteudo);
        printf("\n\n");
    }
    
    fclose(file);
    
    system("pause");
}

int deletar() {
    char cpf[40];
    
    printf("Qual o CPF do usu�rio que voc� deseja deletar? ");
    scanf("%s", cpf);
    
    remove(cpf);
    
    FILE *file;
    file = fopen(cpf, "r");
    
    if (file == NULL) {
        printf("Usu�rio n�o encontrado.\n");
        system("pause");
    }
    
}

int main()
{
    int opcao=0; // Definir vari�veis
    int laco=1;
    
    for (laco=1;laco=1; ) 

    {
        system("cls");
        
        setlocale(LC_ALL, "Portuguese"); // Definir a linguagem

        printf("#### Cartorio da EBAC ####\n\n"); // In�cio do menu
        printf("Escolha a op��o desejada do menu:\n\n");
        printf("\t1 - Registrar nomes\n");
        printf("\t2 - Consultar os nomes\n");
        printf("\t3 - Deletar nomes\n\n");
        printf("\t4 - Sair do sistema\n\n");
        printf("Op��o: "); // Fim de menu

        scanf("%d", &opcao); // Armazenar a escolha do usu�rio

        system("cls");

        // In�cio da sele��o
        switch (opcao)
        {
            case 1:
				registro();
                break;
                
            case 2:
                consulta();
                break;
                
            case 3:
                deletar();
                break;
                
            case 4:
                printf("Obrigado por utilizar o sistema");
                return 0;
                break;

                
            default:
                printf("Esta op��o n�o est� dispon�vel!\n");
                system("pause");
                break;
        }     
    }
}


