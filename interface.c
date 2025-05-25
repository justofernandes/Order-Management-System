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
    Pedido* pedidos_finalizados = NULL;

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
                           if(verificador_nome(nome_pedido)){
                            Prato prato_entrada = criar_prato(num_pedido, nome_pedido);
                            inserir_no_inicio(&lista_pedidos, prato_entrada);
                           }
                            else{
                                printf("Prato nao consta no cardapio!\n");
                                break;
                            }
                            break;

                        case 2:
                            //Remover prato.
                            break;

                        case 3:
                             exibir_lista(lista_pedidos);
                            break;
                        case 4:
                            if(lista_pedidos == NULL){
                                printf("\nLista vazia!\nNao eh possivel enviar a lista vazia!\n");
                                break;
                            }

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
                            
                            break;

                        case 5:
                            printf("\nEscolhido opc: Voltar ao menu principal\n");
                            while (lista_pedidos)
                            {
                               Pedido *temp = lista_pedidos;
                               lista_pedidos = lista_pedidos ->prox;
                               free(temp->pratos);
                               free(temp);
                            }
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
                            printf("\nCozinha:\n");
                            listarFila(fila_cozinha);
                            break;

                        case 2:
                            printf("\nProcessando pedido...\n");
                            Pedido *processado = desenfileirar(&fila_cozinha);
                            if (processado != NULL) {
                                printf("Pedido %d com prato %s foi processado.\n",
                                    processado->pratos->num_pedido, processado->pratos->nome);
                                adicionar_pedido_finalizado(&pedidos_finalizados, processado);
                            } else {
                                printf("Fila vazia.\n");
                            }
                            break;

                        case 3:
                            exibir_pedidos_finalizados(pedidos_finalizados);
                            break;

                        case 4:
                            printf("\nVoltando ao menu principal...\n");
                            break;
                    
                        default:
                            break;
                    }

                } while(opc_submenu2 != 4);
                break;

            case 3:
                printf("Fechando o programa...\n");
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

