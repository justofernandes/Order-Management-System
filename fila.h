#ifndef FILA_H
#define FILA_H

typedef struct Pedido {
    int num_pedido;
    char entrada[60];
    char principal[60];
    char sobremesa [60];
    struct Pedido *prox;
} Pedido;

typedef struct {
    Pedido *inicio;
    Pedido *fim;
} Fila;

void inicializarFila(Fila *f);
void enfileirar(Fila *f, Pedido *p);
Pedido* desenfileirar(Fila *f);
int filaVazia(Fila *f);
void listarFila(Fila f);

#endif