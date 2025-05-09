#include <stdio.h>
#include "pico/stdlib.h" // Funções padrão do Pico, como inicialização e delays
#include "galton.h"      // Interface do sistema Galton Board

int main() {
    stdio_init_all();  // Inicializa a saída padrão (útil para debug via USB)
    galton_init();     // Inicializa o display e as estruturas de controle das bolas

    while (true) {
        galton_update();  // Atualiza lógica das bolas (movimento e spawn)
        galton_draw();    // Desenha bolas, pinos, histograma e contador no display
        sleep_ms(100);    // Aguarda 100ms antes de repetir o loop (define a taxa de atualização)
    }

    return 0; // Nunca é alcançado, pois o loop é infinito
}
