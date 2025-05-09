#ifndef DISPLAY_H
#define DISPLAY_H

#include <stdint.h>
#include <stdbool.h>

// Inicializa o display OLED
void display_init();

// Limpa o conteúdo do buffer de vídeo do display
void display_clear();

// Desenha ou apaga um pixel em (x, y) dependendo do valor de `on` (true = desenha, false = apaga)
void display_draw_pixel(int x, int y, bool on);

// Desenha o histograma com base no vetor de contagem `bins` e no número de valetas `n_bins`
void display_draw_histogram(int *bins, int n_bins);

// Desenha uma bola na posição (x, y)
void display_draw_ball(int x, int y);

// Exibe na tela o número total de bolas que chegaram às valetas
void display_draw_total_count(int count);

// Atualiza o display com o conteúdo desenhado no buffer
void display_render();

// Desenha os pinos da Galton Board; `num_pins` não é usado diretamente na implementação atual,
// mas o padrão desenha 5 linhas com pinos centralizados em forma de triângulo
void display_draw_pins(int num_pins);

#endif
