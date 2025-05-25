#include <locale.h>
#include "lista.h"
#include "interface.h"
#include <stdio.h>

#ifdef _WIN32
#include <windows.h>
#endif

void configurar_localidade_terminal() {
    // Configura a localidade para suportar acentuação
    if (!setlocale(LC_ALL, "")) {
        printf("Aviso: Não foi possível configurar a localidade padrão.\n");
    } else {
        printf("Localidade configurada com sucesso.\n");
    }

#ifdef _WIN32
    // No Windows: mudar a página de código do terminal para UTF-8
    if (!SetConsoleOutputCP(CP_UTF8)) {
        printf("Erro ao configurar o terminal para UTF-8.\n");
    } else {
        printf("Terminal configurado para UTF-8 no Windows.\n");
    }

#else
    printf("Sistema Linux/macOS: terminal geralmente já está em UTF-8.\n");
#endif
}

int main() {

    void configurar_localidade_terminal();

    exibir_interface();

    return 0;
}