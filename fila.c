#include <stdio.h>
#include <string.h>
#include "lista.h"


//Define os ponteiros inicio e fim como NULL, indicando que a fila está vazia.
void inicializarFila(Fila *f) {
    f->inicio = NULL;
    f->fim = NULL;
}

//Função responsável por colocar em ordem de fila os pedidos, onde cada novo pedido vai para o ultimo lugar da fia
void enfileirar(Fila *f, Pedido *p) {
    p->prox = NULL;
    if (f->fim == NULL) {
        f->inicio = f->fim = p;
    } else {
        f->fim->prox = p;
        f->fim = p;
    }
}
//Remove e retorna o primeiro elemento da fila
Pedido* desenfileirar(Fila *f) {
    if (f->inicio == NULL) return NULL;
    Pedido *removido = f->inicio;
    f->inicio = f->inicio->prox;
    if (f->inicio == NULL)
        f->fim = NULL;
    return removido;
}

//Verifica se a fila está vazia
int filaVazia(Fila *f) {
    return f->inicio == NULL;
}


//Exibe todos os elementos presentes na fila.
void listarFila(Fila f) {
    Pedido *atual = f.inicio;
    if (atual == NULL) {
        printf("Nenhum pedido em processamento.\n");
        return;
    }

    while (atual != NULL) {
        if (atual->pratos != NULL) {
            printf("Numero do pedido: %d\n", atual->pratos->num_pedido);
            printf("Prato: %s\n", atual->pratos->nome);
        } else {
            printf("Pedido vazio.\n");
        }
        atual = atual->prox;
    }
}
//copia os dados do prato do pedido, e insere na fila com enfileirar.
void enviar_lista(Pedido *lista, Fila *fila) {
    Pedido *atual = lista;
    while (atual)
    {
       Pedido *novo= malloc(sizeof(Pedido));
       if(novo){
        novo->pratos= malloc(sizeof(Prato));
        if(novo->pratos){
            strcpy(novo->pratos->nome, atual->pratos->nome);
            novo->pratos->num_pedido = atual->pratos->num_pedido;
            novo->prox=NULL;
            enfileirar(fila, novo);
    
        }else{
            free(novo);
        }
        atual= atual->prox;
       }

    }
    
}