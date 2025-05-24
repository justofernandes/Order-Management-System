#ifndef LISTA_H
#define LISTA_H
#include <stdlib.h>
#include <string.h>

typedef struct prato {
    char nome[100];
    int num_pedido;
} Prato;

typedef struct Pedido {
    Prato *pratos;
    struct Pedido *prox;
} Pedido;

void inserir_no_inicio(Pedido **lista, Prato p);
void exibir_lista(Pedido *lista);
Prato criar_prato(int id, const char* nome_prato);

//fila

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