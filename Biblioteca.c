#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// constante global
#define MAX_LIVROS 50
#define TAM_STRING 100

// Estrutura (struct)

struct Livro
{
    char nome[TAM_STRING];
    char autor[TAM_STRING];
    char editora[TAM_STRING];
    int edicao;
};

// Limpeza de Buffer
void limparBufferEntrada()
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF)
        ;
}

// Função principal

int main()
{
    struct Livro biblioteca[MAX_LIVROS];
    int totalLivros = 0;
    int opcao;

    // Menu

    do
    {

        printf("==================BIBLIOTECA=====================\n\n");
        printf("1 - Cadastrar novo livro \n");
        printf("2 - Listar todos os livros \n");
        printf("0 - sair \n");
        printf("Escolha a opcao desejada:");

        // lê a opção do usuario

        scanf("%d", &opcao);
        limparBufferEntrada();

        switch (opcao)
        {
        case 1: // Cadastrar novo livro
            printf("------------Cadastro de um novo livro------------\n\n");

            if (totalLivros < MAX_LIVROS)
            {
                printf("Digite o nome do livro: ");
                fgets(biblioteca[totalLivros].nome, TAM_STRING, stdin);

                printf("Digite o autor: ");
                fgets(biblioteca[totalLivros].autor, TAM_STRING, stdin);

                printf("Digite a editora: ");
                fgets(biblioteca[totalLivros].editora, TAM_STRING, stdin);

                biblioteca[totalLivros].nome[strcspn(biblioteca[totalLivros].nome, "\n")] = '\0';
                biblioteca[totalLivros].autor[strcspn(biblioteca[totalLivros].autor, "\n")] = '\0';
                biblioteca[totalLivros].editora[strcspn(biblioteca[totalLivros].editora, "\n")] = '\0';

                printf("Digite o numero da edicao: ");
                scanf("%d", &biblioteca[totalLivros].edicao);
                limparBufferEntrada();

                totalLivros++;

                printf("\nLivro cadastrado com sucesso\n");
            }
            else
            {
                printf("Biblioteca cheia, impossivel cadastrar\n");
            }

            printf("\n Pressione Enter para continuar...");
            getchar(); // Pausa para o usuario ler a mensagem antes de voltar ao menu
            break;

        case 2: // Listagem de livros
            printf("--Livros cadastrados--\n\n");

            if (totalLivros == 0)
            {
                printf("Nenhum livro cadastrado\n");
            }
            else
            {
                for (int i = 0; i < totalLivros; i++)
                {
                    printf("------------------");
                    printf("Livro %d\n", i + 1);
                    printf("Nome: %s\n", biblioteca[i].nome);
                    printf("Autor: %s\n", biblioteca[i].autor);
                    printf("Editora: %s\n", biblioteca[i].editora);
                    printf("Edicao: %d\n", biblioteca[i].edicao);
                }
                printf("-------------------------------------\n");
            }

            printf("\nPressione Enter para continuar...");
            getchar();
            break;
        case 0: // Sair
            printf("\nSaindo do sistema...\n");
            break;

        default: // Opção invalida
            printf("\nOpcao invalida! Tente nocamente.\n");
            printf("Pressione Enter para continuar...");
            getchar();
            break;
        }
    } while (opcao != 0);

    return 0;
}