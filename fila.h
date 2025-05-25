#ifndef FILA_H
#define FILA_H

typedef struct {
    Pedido *inicio;
    Pedido *fim;
} Fila;

void inicializarFila(Fila *f);
void enfileirar(Fila *f, Pedido *p);
Pedido* desenfileirar(Fila *f);
int filaVazia(Fila *f);


#endif