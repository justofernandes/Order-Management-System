#include <stdio.h>
#include <stdlib.h>
#include "interface.h"  
#include "cardapio.h"

void exibir_interface() {

    int opc_main_menu, opc_submenu1, opc_submenu2, opc_menu_cardapio;

    do { 

        printf("\n---------- INTERFACE MENU ----------\n\n");
        printf("Escolha uma opcao: \n\n1. Realizar Atendimento\n2. Acessar Cozinha\n3. Fechar Programa\n\n");

        scanf("%d", &opc_main_menu);

        switch (opc_main_menu) {
            case 1:
                do {

                    printf("\nEscolhido: Realizar o atendimento\n");
                    printf("\nEscolha uma opcao: \n\n1. Adicionar prato\n2. Remover prato\n3. Mostrar pedido\n4. --------\n5. Voltar ao menu principal\n\n");

                    scanf("%d", &opc_submenu1);

                    switch (opc_submenu1) {
                        case 1:
                            printf("\nAdicionar prato\n");
                            do{
                                printf("\n1. Adicionar entrada\n2. Adicionar prato principal\n3. Adicionar sobremesa\n4. Voltar\n");

                                scanf("%d", &opc_menu_cardapio);
                                
                                switch (opc_menu_cardapio) 
                                {
                                case 1:
                                    int e; //entrada para validação
                                    exibir_entradas();
                                    printf("\nSelecione uma entrada: \n");
                                    scanf("%d", &e);
                                    printf("Entrada adicionada com sucesso!\n");
                                    
                                    //exibir entradas
                                    break;

                                case 2:
                                    int f; //entrada para validação
                                    exibir_pratos_principais();
                                    printf("\nSelecione um prato principal: \n");
                                    scanf("%d", &f);
                                    printf("Prato principal adicionado com sucesso!\n");
                                    //exibir pratos principais
                                    break;

                                case 3:
                                    int g; //entrada para validação
                                    exibir_sobremesas();
                                    printf("\nSelecione uma sobremesa: \n");
                                    scanf("%d", &g);
                                    printf("Sobremesa adicionada com sucesso!a\n");
                                    //exibir sobremesas
                                    break;
                                
                                default:
                                    printf("opc invalida!");
                                }
                                

                            }while(opc_menu_cardapio != 4);
                            break;

                        case 2:
                            printf("\nEscolhido opc: 2\n");
                            break;

                        case 3:
                            printf("\nEscolhido opc: 3\n");
                            break;

                        case 4:
                            printf("\nEscolhido opc: 4\n");
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

                    switch (opc_submenu2) {
                        case 1:
                            printf("\nEscolhido opc: 1\n");
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