//#include <locale.h>
#include "cardapio.h"
#include <stdio.h>

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
