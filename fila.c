#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fila.h"

void inicializarFila(Fila *f) {
    f->inicio = NULL;
    f->fim = NULL;
}

void enfileirar(Fila *f, Pedido *p) {
    p->prox = NULL;
    if (f->fim == NULL) {
        f->inicio = f->fim = p;
    } else {
        f->fim->prox = p;
        f->fim = p;
    }
}

Pedido* desenfileirar(Fila *f) {
    if (f->inicio == NULL) return NULL;
    Pedido *removido = f->inicio;
    f->inicio = f->inicio->prox;
    if (f->inicio == NULL)
        f->fim = NULL;
    return removido;
}


int filaVazia(Fila *f) {
    return f->inicio == NULL;
}



//falta implementarmos alguma coisa para listarmos os pedidos, temos que pensar num identificador que voce vai colocar ai na lista