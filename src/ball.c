#include "ball.h"
#include "stdlib.h"
#include "ssd1306.h"
#include "display.h"  

// Array de bolas simuladas
static Ball balls[MAX_BALLS];
// Array de contadores de cada bin (valeta) do histograma
static int histogram[MAX_BINS] = {0};
// Contador total de bolas que já chegaram no final
static int total_count = 0;

// Inicializa as bolas e o histograma
void balls_init() {
    for (int i = 0; i < MAX_BALLS; i++) {
        balls[i].active = false; // Nenhuma bola ativa no início
    }
    for (int i = 0; i < MAX_BINS; i++) {
        histogram[i] = 0; // Zera o histograma
    }
    total_count = 0;
}

// Cria (ativa) uma nova bola na posição inicial (centro do topo do display)
void balls_spawn() {
    for (int i = 0; i < MAX_BALLS; i++) {
        if (!balls[i].active) {
            balls[i].x = ssd1306_width / 2; // Começa no centro do display
            balls[i].y = 10;                // Altura inicial
            balls[i].step = 0;
            balls[i].active = true;
            break; // Apenas uma bola por chamada
        }
    }
}

// Atualiza a posição das bolas ativas
void balls_update() {
    for (int i = 0; i < MAX_BALLS; i++) {
        if (!balls[i].active) continue;

        if (balls[i].step < MAX_STEPS) {
            // A bola escolhe aleatoriamente ir para a esquerda ou direita (2 pixels por passo)
            int shift = (rand() % 2 == 0) ? -1 : 1;
            balls[i].x += shift * 2; // Deslocamento horizontal
            balls[i].y += 5;         // Deslocamento vertical
            balls[i].step++;
        } else {
            // Quando a bola chega ao fim, incrementa o bin correspondente
            int bin = balls[i].x * MAX_BINS / ssd1306_width;
            if (bin < 0) bin = 0;
            if (bin >= MAX_BINS) bin = MAX_BINS - 1;

            histogram[bin]++;
            total_count++;
            balls[i].active = false; // Desativa a bola
        }
    }
}

// Desenha as bolas ativas no display
void balls_draw() {
    for (int i = 0; i < MAX_BALLS; i++) {
        if (balls[i].active) {
            display_draw_ball(balls[i].x, balls[i].y);
        }
    }
}

// Retorna ponteiro para o histograma (para desenhar)
int *get_histogram() {
    return histogram;
}

// Retorna o total de bolas que chegaram ao final
int get_total_count() {
    return total_count;
}
