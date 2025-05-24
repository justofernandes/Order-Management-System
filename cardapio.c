//#include <locale.h>
#include "cardapio.h"
#include <stdio.h>
#include <ctype.h>
#include <strings.h>

const char* pratos_cardapio[] = {
    // Entradas
    "Sopa de Cebola", "Salada Caesar", "Bruschetta", "Carpaccio de Carne", "Camarao ao Alho",
    // Pratos Principais
    "Lasanha a Bolonhesa", "File Mignon com Fritas", "Frango Grelhado com Legumes", "Bacalhau a Gomes de Sa", "Risoto de Cogumelos",
    // Sobremesas
    "Tiramisu", "Cheesecake de Frutas Vermelhas", "Mousse de Chocolate", "Pudim de Leite", "Sorvete de Baunilha com Calda de Morango"
};
int verificador_nome(const char* nome) {
    int total = sizeof(pratos_cardapio) / sizeof(pratos_cardapio[0]);
    for (int i = 0; i < total; i++) {
        if (strcasecmp(nome, pratos_cardapio[i]) == 0) {
            return 1; 
        }
    }
    return 0; 
}
void exibir_cardapio() {
    //setlocale(LC_ALL, "");
    printf("\n ======= Entradas ======= \n");
    printf("\n 1. Sopa de Cebola\n");
    printf(" 2. Salada Caesar\n");
    printf(" 3. Bruschetta\n");
    printf(" 4. Carpaccio de Carne\n");
    printf(" 5. Camarao ao Alho\n");

    printf("\n======= Pratos Principais =======\n");
    printf(" 1. Lasanha a Bolonhesa\n");
    printf(" 2. File Mignon com Fritas\n");
    printf(" 3. Frango Grelhado com Legumes\n");
    printf(" 4. Bacalhau a Gomes de Sa\n");
    printf(" 5. Risoto de Cogumelos\n");

    printf("\n======= Sobremesas =======\n");
    printf(" 1. Tiramisu\n");
    printf(" 2. Cheesecake de Frutas Vermelhas\n");
    printf(" 3. Mousse de Chocolate\n");
    printf(" 4. Pudim de Leite\n");
    printf(" 5. Sorvete de Baunilha com Calda de Morango\n");
}
