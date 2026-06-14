// Leticia Avelar Araujo - Lab_Programação


#include <stdio.h>
#include <string.h>

#define MAX_REGISTROS 50
#define MAX_LETRAS 30

int main()
{
    char banco_dados[MAX_REGISTROS][MAX_LETRAS] = {""};
    char nome[MAX_LETRAS];
    char novo_nome[MAX_LETRAS];

    int opcao;
    int i;
    int posicao;
    int encontrado;
    int existe;

    do {

        printf("\n===== MENU =====\n");
        printf("1 - Incluir nome\n");
        printf("2 - Buscar nome\n");
        printf("3 - Modificar nome\n");
        printf("4 - Apagar nome\n");
        printf("5 - Listar todos\n");
        printf("0 - Sair\n");
        printf("Escolha uma opcao: ");

        scanf("%d", &opcao);

        switch(opcao) {

            case 1:

                printf("Digite o nome: ");
                scanf(" %[^\n]", nome);

                existe = 0;

                for(i = 0; i < MAX_REGISTROS; i++) {
                    if(strcmp(banco_dados[i], nome) == 0) {
                        existe = 1;
                    }
                }

                if(existe == 1) {
                    printf("Esse nome ja existe.\n");
                }
                else {

                    posicao = -1;

                    for(i = 0; i < MAX_REGISTROS; i++) {

                        if(banco_dados[i][0] == '\0') {
                            posicao = i;
                            break;
                        }
                    }

                    if(posicao == -1) {
                        printf("Banco de dados cheio.\n");
                    }
                    else {
                        strcpy(banco_dados[posicao], nome);
                        printf("Nome cadastrado com sucesso.\n");
                    }
                }

                break;

            case 2:

                printf("Digite o nome que deseja buscar: ");
                scanf(" %[^\n]", nome);

                encontrado = -1;

                for(i = 0; i < MAX_REGISTROS; i++) {

                    if(strcmp(banco_dados[i], nome) == 0) {
                        encontrado = i;
                        break;
                    }
                }

                if(encontrado == -1) {
                    printf("Nome nao encontrado.\n");
                }
                else {
                    printf("Nome encontrado no indice %d.\n", encontrado);
                }

                break;

            case 3:

                printf("Digite o nome que deseja modificar: ");
                scanf(" %[^\n]", nome);

                encontrado = -1;

                for(i = 0; i < MAX_REGISTROS; i++) {

                    if(strcmp(banco_dados[i], nome) == 0) {
                        encontrado = i;
                        break;
                    }
                }

                if(encontrado == -1) {
                    printf("Nome nao encontrado.\n");
                }
                else {

                    printf("Digite o novo nome: ");
                    scanf(" %[^\n]", novo_nome);

                    existe = 0;

                    for(i = 0; i < MAX_REGISTROS; i++) {

                        if(strcmp(banco_dados[i], novo_nome) == 0) {
                            existe = 1;
                        }
                    }

                    if(existe == 1) {
                        printf("Esse nome ja existe.\n");
                    }
                    else {
                        strcpy(banco_dados[encontrado], novo_nome);
                        printf("Nome alterado com sucesso.\n");
                    }
                }

                break;

            case 4:

                printf("Digite o nome que deseja apagar: ");
                scanf(" %[^\n]", nome);

                encontrado = -1;

                for(i = 0; i < MAX_REGISTROS; i++) {

                    if(strcmp(banco_dados[i], nome) == 0) {
                        encontrado = i;
                        break;
                    }
                }

                if(encontrado == -1) {
                    printf("Nome nao encontrado.\n");
                }
                else {
                    banco_dados[encontrado][0] = '\0';
                    printf("Nome apagado com sucesso.\n");
                }

                break;

            case 5:

                printf("\n===== LISTA DE NOMES =====\n");

                encontrado = 0;

                for(i = 0; i < MAX_REGISTROS; i++) {

                    if(banco_dados[i][0] != '\0') {

                        printf("Indice %d: %s\n", i, banco_dados[i]);
                        encontrado = 1;
                    }
                }

                if(encontrado == 0) {
                    printf("Nenhum nome cadastrado.\n");
                }

                break;

            case 0:

                printf("Saindo do programa...\n");
                break;

            default:

                printf("Opcao invalida.\n");
        }

    } while(opcao != 0);

    return 0;
}