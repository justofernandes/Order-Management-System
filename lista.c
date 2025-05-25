#include "lista.h"
#include <stdio.h>
#include <string.h>

//Função responsável por criar uma struct do tipo Prato.
Prato criar_prato(int id, const char* nome_prato) {
    Prato novo_prato;
    novo_prato.num_pedido = id;
    strncpy(novo_prato.nome, nome_prato, sizeof(novo_prato.nome) - 1);
    novo_prato.nome[sizeof(novo_prato.nome) - 1] = '\0';
    return novo_prato;
}

//Insere os elementos no iníciio da lista encadeada
void inserir_no_inicio(Pedido **lista, Prato p) {

    Pedido *novo = malloc(sizeof(Pedido));

    if(novo) {
        novo->pratos = malloc(sizeof(Prato)); // -> Necessário alocar memória para a struct presente na lista!
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

//Exibe todos os elementos presentes na lista.
void exibir_lista(Pedido *lista) {
    printf("\n\tPedido: \n\n");
    int indice = 1;
    while (lista) { // -> Enquanto lista != NULL.
        printf("%d. %s\n", indice, lista->pratos->nome);
        lista = lista->prox;
        ++indice;
    }
    printf("\n");
    
}
void adicionar_pedido_finalizado(Pedido **lista, Pedido *pedido) {
    pedido->prox = *lista;
    *lista = pedido;
}

void exibir_pedidos_finalizados(Pedido *lista) {
    if (!lista) {
        printf("\nNenhum pedido finalizado.\n");
        return;
    }
    printf("\n=== Pedidos Finalizados ===\n\n");
    while (lista) {
        printf("Pedido %d - %s\n", lista->pratos->num_pedido, lista->pratos->nome);
        lista = lista->prox;
    }
}

//Remove o elemento desejado da lista.
void remover_elemento_lista(Pedido **lista, char* nome_elemento) {
    
    if(*lista == NULL) {
        printf("lista vazia!\n");
        return;
    } // -> Verifica se a lista está vazia

    Pedido *anterior = NULL; 
    Pedido *atual = *lista;

    while (atual != NULL && (strcmp(atual->pratos->nome, nome_elemento) != 0)) {
        anterior = atual;
        atual = atual->prox;
    }

    if(atual == NULL) { // -> Indica que chegou ao final da lista e não encontrou o elemento desejado
        printf("Valor inexistente na lista!\n");
        return;
    }

    if(anterior == NULL) { // O elemento a ser excluído é o primeiro elemento da lista
        *lista = atual->prox;
    }
    else { //Exlclui o elemento encontrado da lista.
        anterior->prox = atual->prox;
    }

    //Desaloca memória
    free(atual->pratos);
    free(atual);

}
