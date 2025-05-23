#include "lista.h"
#include <stdio.h>

Prato criar_prato(int id, const char* nome_prato) {
    Prato novo_prato;
    novo_prato.num_pedido = id;
    strncpy(novo_prato.nome, nome_prato, sizeof(novo_prato.nome) - 1);
    novo_prato.nome[sizeof(novo_prato.nome) - 1] = '\0';
    return novo_prato;
}

void inserir_no_inicio(Pedido **lista, Prato p) {

    Pedido *novo = malloc(sizeof(Pedido));

    if(novo) {
        novo->pratos = malloc(sizeof(Prato));
        if (novo->pratos) {
            strncpy(novo->pratos->nome, p.nome, sizeof(novo->pratos->nome) - 1);
            novo->pratos->nome[sizeof(novo->pratos->nome) - 1] = '\0';
            novo->pratos->num_pedido = p.num_pedido;
            novo->prox = *lista;
            *lista = novo;
        } else {
            printf("Erro ao alocar memoria!\n");
            free(novo);
        }
    }

    else   
        printf("Erro ao alocar memoria!\n");
}

void exibir_lista(Pedido *lista) {
    printf("\n\tPedido: \n\n");
    int indice = 1;
    while (lista) {
        printf("%d. %s\n", indice, lista->pratos->nome);
        lista = lista->prox;
        ++indice;
    }
    printf("\n\n");
    
}
void adicionar_pedido_finalizado(Pedido **lista, Pedido *pedido) {
    pedido->prox = *lista;
    *lista = pedido;
}

void exibir_pedidos_finalizados(Pedido *lista) {
    if (!lista) {
        printf("Nenhum pedido finalizado.\n");
        return;
    }
    printf("\n=== Pedidos Finalizados ===\n");
    while (lista) {
        printf("Pedido %d - %s\n", lista->pratos->num_pedido, lista->pratos->nome);
        lista = lista->prox;
    }
}


//Adicionar, ainda, verificar se a lista está vazia e excluir elemento da lista(tratar caso do elemento não estar na lista).

