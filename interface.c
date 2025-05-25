#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdlib.h>
#include "interface.h"  
#include "cardapio.h"
#include "lista.h"

//Toda a lógica de funcionamento da interface. getchar() utilizado para manter as exibições na tela.
void exibir_interface() {

    int opc_main_menu, opc_submenu1, opc_submenu2, num_pedido;
    
    Pedido* lista_pedidos = NULL;
    Pedido* pedidos_finalizados = NULL;

    Fila fila_cozinha;
    inicializarFila(&fila_cozinha);

    do { 

        printf("\n---------- INTERFACE MENU ----------\n\n");
        printf("\tEscolha uma opcao: \n\n1. Realizar Atendimento\n2. Acessar Cozinha\n3. Fechar Programa\n\n");

        scanf("%d", &opc_main_menu);
        limparBuffer();
        limparTerminal();

        switch (opc_main_menu) {
            case 1:
                printf("\nQual o numero do pedido?\n");
                scanf("%d", &num_pedido);
                limparBuffer();
                limparTerminal();
                do {

                    printf("\n\t Realizar o atendimento\n");
                    printf("\nEscolha uma opcao: \n\n1. Adicionar prato\n2. Remover prato\n3. Mostrar pedido\n4. Finalizar pedido\n5. Voltar ao menu principal\n\n");

                    scanf("%d", &opc_submenu1);
                    limparBuffer();
                    limparTerminal();

                    switch (opc_submenu1) {
                        case 1:{
                            char nome_pedido[60];
                            printf("\n\tAdicionar prato\n");
                            printf("\nnumero do pedido: %d", num_pedido);
                            limparTerminal();
                            exibir_cardapio();
                            printf("\nInserir pedido: \n");
                            fgets(nome_pedido, sizeof(nome_pedido), stdin);
                            nome_pedido[strcspn(nome_pedido, "\n")] = '\0'; //Identifica se há quebra de liha. Caso houver, substitui pelo final da string.
                            limparTerminal();
                            
                            if(verificador_nome(nome_pedido)) {
                                Prato prato_entrada = criar_prato(num_pedido, nome_pedido);
                                inserir_no_inicio(&lista_pedidos, prato_entrada);
                            }
                            else {
                                printf("Prato nao consta no cardapio!\n");
                                break;
                            }
                            limparTerminal();
                            break;}

                        case 2:
                            exibir_lista(lista_pedidos);
                            printf("\n=================\n");
                            char nome_pedido_excluir[60];
                            printf("\nIndique qual prato deseja excluir: \n");
                            fgets(nome_pedido_excluir, sizeof(nome_pedido_excluir), stdin);
                            nome_pedido_excluir[strcspn(nome_pedido_excluir, "\n")] = '\0'; //Identifica se há quebra de liha. Caso houver, substitui pelo final da string.
                            remover_elemento_lista(&lista_pedidos, nome_pedido_excluir);
                            limparTerminal();
                            break;

                        case 3: //Mostra a lista de pratos adicionados no atendimento atual.
                            exibir_lista(lista_pedidos);
                            getchar();
                            limparTerminal();
                            break;
                        case 4:
                            if(lista_pedidos == NULL){
                                printf("\nLista vazia!\n\nNao eh possivel enviar a lista vazia!\n");
                                break;
                            }

                            printf("\nFinalizando pedido e enviando para a cozinha...\n");
                            enviar_lista(lista_pedidos, &fila_cozinha);
                            while (lista_pedidos) // -> Desaloca memória/exclui os elementos da lista (limpa ela)
                            {
                               Pedido *temp = lista_pedidos;
                               lista_pedidos = lista_pedidos ->prox;
                               free(temp->pratos);
                               free(temp);
                            }
                            printf("Pedido enviado com sucesso!\n");
                            limparTerminal();
                            break;

                        case 5:
                            printf("\nVoltando ao menu principal...\n");
                            while (lista_pedidos) // -> Desaloca memória/exclui os elementos da lista (limpa ela)
                            {
                               Pedido *temp = lista_pedidos;
                               lista_pedidos = lista_pedidos ->prox;
                               free(temp->pratos);
                               free(temp);
                            }
                            limparTerminal();
                            break;
                    
                        default:
                            printf("\nOpcao invalida!\n");
                    }

                } while(opc_submenu1 != 5);
                break;

            case 2:

                do {
                    printf("\n\tAcessar Cozinha\n");
                    printf("\nEscolha uma opcao: \n\n1. Exibir cozinha\n2. Processar pedido\n3. Pedidos finalizados\n4. Voltar ao menu principal\n\n");

                    scanf("%d", &opc_submenu2);
                    limparBuffer();
                    limparTerminal();

                    switch (opc_submenu2) {
                        case 1:
                            printf("\n\tCozinha:\n\n");
                            listarFila(fila_cozinha);
                            getchar();
                            limparTerminal();
                            break;

                        case 2: //remove o pedido mais antigo pelo desenfilerar
                            printf("\nProcessando pedido...\n");
                            Pedido *processado = desenfileirar(&fila_cozinha);
                            if (processado != NULL) {
                                printf("Pedido %d com prato %s foi processado.\n",
                                    processado->pratos->num_pedido, processado->pratos->nome);
                                adicionar_pedido_finalizado(&pedidos_finalizados, processado);
                            } else {
                                printf("Fila vazia.\n");
                            }
                            limparTerminal();
                            break;

                        case 3:
                            exibir_pedidos_finalizados(pedidos_finalizados);
                            getchar();
                            limparTerminal();
                            break;

                        case 4:
                            printf("\nVoltando ao menu principal...\n");
                            limparTerminal();
                            break;
                    
                        default:
                            break;
                    }

                } while(opc_submenu2 != 4);
                break;

            case 3:
                printf("Fechando o programa...\n");
                limparTerminal();
                break;
        
            default:
                printf("\nOpcao invalida!\n");

        }

    } while (opc_main_menu != 3);

}

//Função pra limpar o buffer de entrada do teclado.
void limparBuffer(void){
    char c;
    while ((c = getchar()) != '\n' && c != EOF);
}

//Verifica o sistema operacional, e aciona a limpeza correspondente.
void limparTerminal() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

