#include "galton.h"
#include "ball.h"
#include "display.h"
#include "pico/stdlib.h"

// Tempo em que a última bola foi gerada (em ms)
static uint64_t last_spawn_time = 0;

// Intervalo entre o surgimento de novas bolas (em milissegundos)
static const uint64_t spawn_interval_ms = 300;

// Inicializa o sistema: display e estrutura de bolas
void galton_init() {
    display_init();   // Inicializa o display OLED
    balls_init();     // Zera histogramas e marca bolas como inativas
}

// Atualiza a lógica do sistema a cada frame
void galton_update() {
    uint64_t now = to_ms_since_boot(get_absolute_time()); // Tempo atual em ms desde boot

    // Se passou tempo suficiente, gera uma nova bola
    if (now - last_spawn_time > spawn_interval_ms) {
        balls_spawn();         // Ativa uma nova bola na posição inicial
        last_spawn_time = now; // Atualiza o tempo da última bola gerada
    }

    balls_update(); // Move todas as bolas ativas, e registra no histograma se chegaram ao fim
}

// Desenha todos os elementos na tela
void galton_draw() {
    display_clear();  // Limpa o buffer do display

    balls_draw();     // Desenha bolas em movimento (ativas)
    display_draw_pins(MAX_BINS); // Desenha os pinos fixos da Galton Board
    display_draw_histogram(get_histogram(), MAX_BINS); // Desenha o histograma acumulado
    display_draw_total_count(get_total_count());       // Mostra o total de bolas processadas

    display_render(); // Envia o buffer para o display
}
