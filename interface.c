#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdlib.h>
#include "interface.h"  
#include "cardapio.h"
#include "lista.h"


//void atendimento_pedidos();
void limparBuffer(void);
void enviar_lista(Pedido *lista, Fila *fila);
void exibir_interface() {

    int opc_main_menu, opc_submenu1, opc_submenu2, num_pedido;
    
    Pedido* lista_pedidos = NULL;

    Fila fila_cozinha;
    inicializarFila(&fila_cozinha);

    do { 

        printf("\n---------- INTERFACE MENU ----------\n\n");
        printf("Escolha uma opcao: \n\n1. Realizar Atendimento\n2. Acessar Cozinha\n3. Fechar Programa\n\n");

        scanf("%d", &opc_main_menu);
        limparBuffer();

        switch (opc_main_menu) {
            case 1:
                printf("\nQual o numero do pedido?\n");
                scanf("%d", &num_pedido);
                limparBuffer();
                do {

                    printf("\nEscolhido: Realizar o atendimento\n");
                    printf("\nEscolha uma opcao: \n\n1. Adicionar prato\n2. Remover prato\n3. Mostrar pedido\n4. Finalizar pedido\n5. Voltar ao menu principal\n\n");

                    scanf("%d", &opc_submenu1);
                    limparBuffer();

                    switch (opc_submenu1) {
                        case 1:
                            printf("\nAdicionar prato\n");
                            printf("nummero do pedido: %d", num_pedido);
                            exibir_cardapio();
                            char nome_pedido[60];
                            printf("\nInserir nome do pedido: \n");
                            //limparBuffer();
                            fgets(nome_pedido, sizeof(nome_pedido), stdin);
                            nome_pedido[strcspn(nome_pedido, "\n")] = '\0'; //Identifica se há quebra de liha. Caso houver, substitui pelo final da string.
                            Prato prato_entrada = criar_prato(&num_pedido, nome_pedido);
                            inserir_no_inicio(&lista_pedidos, prato_entrada);
                            break;

                        case 2:
                            printf("\nEscolhido opc: 2\n");
                            break;

                        case 3:
                            exibir_lista(lista_pedidos);

                            break;

                        case 4:
                            printf("\nFinalizando pedido e enviando para a cozinha...\n");
                            enviar_lista(lista_pedidos, &fila_cozinha);
                            while (lista_pedidos)
                            {
                               Pedido *temp = lista_pedidos;
                               lista_pedidos = lista_pedidos ->prox;
                               free(temp->pratos);
                               free(temp);
                            }
                            printf("Pedido enviado com sucesso!\n");
                            Pedido *temp;
                            while (lista_pedidos != NULL) {
                                temp = lista_pedidos;
                                lista_pedidos = lista_pedidos->prox;
                                free(temp->pratos);
                                free(temp);
                            }
                            break;

                        case 5:
                            printf("\nEscolhido opc: Voltar ao menu principal\n");
                            break;
                    
                        default:
                            printf("\nOpc invalida!\n");
                    }

                } while(opc_submenu1 != 5);
                break;

            case 2:

                do {
                    printf("\nEscolhido: Acessar Cozinha\n");
                    printf("\nEscolha uma opcao: \n\n1. Exibir cozinha\n2. Processar pedido\n3. --------\n4. Voltar ao menu principal\n\n");

                    scanf("%d", &opc_submenu2);
                    limparBuffer();

                    switch (opc_submenu2) {
                        case 1:
                            printf("\nEscolhido opc: 1\n");
                            listarFila(fila_cozinha);
                            break;

                        case 2:
                            printf("\nEscolhido opc: 2\n");
                            break;

                        case 3:
                            printf("\nEscolhido opc: 3\n");
                            break;

                        case 4:
                            printf("\nEscolhido opc: Voltar ao menu principal\n");
                            break;
                    
                        default:
                            break;
                    }

                } while(opc_submenu2 != 4);
                break;

            case 3:
                printf("Escolhido: Sair do menu\n");
                break;
        
            default:
                printf("\nOpcao invalida!\n");
        }

    } while (opc_main_menu != 3);

}

void limparBuffer(void){
    char c;
    while ((c = getchar()) != '\n' && c != EOF);
}

void enviar_lista(Pedido *lista, Fila *fila){
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
