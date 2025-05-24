#ifndef FILA_H
#define FILA_H

typedef struct {
    Pedido *inicio;
    Pedido *fim;
} Fila;

typedef struct Prato {
    char nome[100];
    struct Prato *prox;
} Prato;

typedef struct Pedido {

    Prato *pratos;
    struct Pedido *prox;
} Pedido;

void inicializarFila(Fila *f);
void enfileirar(Fila *f, Pedido *p);
Pedido* desenfileirar(Fila *f);
int filaVazia(Fila *f);


#endif