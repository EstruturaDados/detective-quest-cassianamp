// Desafio Detective Quest
// Tema 4 - Árvores e Tabela Hash
// ível Novato: Mapa da Mansão com Árvore Binária

// Inclusão das bibliotecas necessárias
#include <stdio.h>   // Biblioteca padrão de entrada/saída
#include <stdlib.h>  // Biblioteca para as funções malloc e free
#include <string.h>  // Biblioteca para manipulação de strings

// Criação da struct Sala com nome e dois ponteiros - esquerda e direita - que representa cada sala da mansão (nó da árvore)
typedef struct Sala {
    char nome[50];
    struct Sala *esquerda;
    struct Sala *direita;
} Sala;

// Definição da função para criar sala que cria, de forma dinâmica, uma sala com o nome fornecido
Sala* criarSala(const char *nome) {
    Sala *nova = (Sala*) malloc(sizeof(Sala));

    if (nova == NULL) {
        printf("Erro ao alocar memória!\n");
        exit(1);
    }

    strcpy(nova->nome, nome);
    nova->esquerda = NULL;
    nova->direita = NULL;

    return nova;
}

// Definição da função para eplorar as salas que permite a navegação do jogador pela árvore
void explorarSalas(Sala *atual) {
    char opcao;

    while (atual != NULL) {
        printf("\nVocê está em: %s\n", atual->nome);

        if (atual->esquerda == NULL && atual->direita == NULL) {
            printf("Você chegou a um cômodo sem saídas. Exploração encerrada.\n");
            return;
        }

        printf("Escolha um caminho:\n");
        if (atual->esquerda != NULL)
            printf(" (e) Ir para a esquerda -> %s\n", atual->esquerda->nome);

        if (atual->direita != NULL)
            printf(" (d) Ir para a direita  -> %s\n", atual->direita->nome);

        printf(" (s) Sair\n");
        printf("Opção: ");

        scanf(" %c", &opcao);

        if (opcao == 'e' || opcao == 'E') {
            if (atual->esquerda != NULL)
                atual = atual->esquerda;
            else
                printf("Não há caminho à esquerda!\n");
        }
        else if (opcao == 'd' || opcao == 'D') {
            if (atual->direita != NULL)
                atual = atual->direita;
            else
                printf("Não há caminho à direita!\n");
        }
        else if (opcao == 's' || opcao == 'S') {
            printf("Exploração encerrada.\n");
            return;
        }
        else {
            printf("Opção inválida!\n");
        }
    }
}


// Função principal que monta o mapa inicial e dá início à exploração
int main() {

    // Criação das salas (nós da árvore)
    Sala *hall = criarSala("Hall de Entrada");
    Sala *salaEstar = criarSala("Sala de Estar");
    Sala *cozinha = criarSala("Cozinha");
    Sala *biblioteca = criarSala("Biblioteca");
    Sala *salaoJogos = criarSala("Salão de Jogos");
    Sala *jardim = criarSala("Jardim");
    Sala *suitePrincipal = criarSala("Suíte Principal");
    Sala *quarto1 = criarSala("Quarto 1");
    Sala *quarto2 = criarSala("Quarto 2");
    Sala *banheiroSocial = criarSala("Banheiro Social");
    Sala *garagem = criarSala("Garagem");
    Sala *banheiroSuite = criarSala("Banheiro Suíte");
    Sala *closet = criarSala("Closet");

    // Estrutura da mansão (árvore binária fixa)
    //
    //                                          Hall de Entrada
    //                                    /                        \
    //                           Sala de Estar                      Cozinha
    //                       /                   \                   /      \
    //              Biblioteca                 Salão de Jogos    Garagem   Jardim
    //            /          \                /             \
    //   Quarto 1       Suíte Principal   Banheiro Social   Quarto 2    
    //                    /          \
    //            Banheiro Suíte     Closet


    // Estrutura da árvore
    hall->esquerda = salaEstar;
    hall->direita = cozinha;

    salaEstar->esquerda = biblioteca;
    salaEstar->direita = salaoJogos;

    cozinha->esquerda = garagem;
    cozinha->direita = jardim;

    biblioteca->esquerda = quarto1;
    biblioteca->direita = suitePrincipal;

    salaoJogos->esquerda = banheiroSocial;
    salaoJogos->direita = quarto2;

    suitePrincipal->esquerda = banheiroSuite;
    suitePrincipal->direita = closet;

    // Início da exploração
    explorarSalas(hall);

    return 0;
}