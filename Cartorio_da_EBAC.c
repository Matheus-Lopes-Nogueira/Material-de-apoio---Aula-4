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
        printf("Não foi possível abrir o arquivo, arquivo não localizado.\n");
    }
    
    while (fgets(conteudo, 200, file) != NULL) {
        printf("\nEssas são as informações do usuário:\n");
        printf("%s", conteudo);
        printf("\n\n");
    }
    
    fclose(file);
    
    system("pause");
}

int deletar() {
    char cpf[40];
    
    printf("Qual o CPF do usuário que você deseja deletar? ");
    scanf("%s", cpf);
    
    remove(cpf);
    
    FILE *file;
    file = fopen(cpf, "r");
    
    if (file == NULL) {
        printf("Usuário não encontrado.\n");
        system("pause");
    }
    
}

int main()
{
    int opcao=0; // Definir variáveis
    int laco=1;
    
    for (laco=1;laco=1; ) 

    {
        system("cls");
        
        setlocale(LC_ALL, "Portuguese"); // Definir a linguagem

        printf("#### Cartorio da EBAC ####\n\n"); // Início do menu
        printf("Escolha a opção desejada do menu:\n\n");
        printf("\t1 - Registrar nomes\n");
        printf("\t2 - Consultar os nomes\n");
        printf("\t3 - Deletar nomes\n\n");
        printf("\t4 - Sair do sistema\n\n");
        printf("Opção: "); // Fim de menu

        scanf("%d", &opcao); // Armazenar a escolha do usuário

        system("cls");

        // Início da seleção
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
                printf("Esta opção não está disponível!\n");
                system("pause");
                break;
        }     
    }
}


