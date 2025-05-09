#ifndef BALL_H
#define BALL_H

// Define o número máximo de bolas que podem estar ativas simultaneamente na simulação
#define MAX_BALLS 20

// Define o número máximo de passos horizontais (escolhas esquerda/direita) que uma bola pode dar
#define MAX_STEPS 6

// Define o número máximo de valetas (bins) no histograma
#define MAX_BINS 32

#include <stdbool.h> // Inclui suporte ao tipo booleano (true/false)

// Estrutura que representa uma bola na simulação
typedef struct {
    int x, y;      // Posição da bola na tela (coordenadas em pixels)
    int step;      // Número de decisões já tomadas (esquerda ou direita)
    bool active;   // Indica se a bola está ativa (em movimento)
} Ball;

// Inicializa as variáveis e estruturas relacionadas às bolas
void balls_init();

// Cria uma nova bola ativa na posição inicial
void balls_spawn();

// Atualiza a posição de todas as bolas ativas (movimento e decisões aleatórias)
void balls_update();

// Desenha as bolas ativas na tela
void balls_draw();

// Retorna um ponteiro para o vetor do histograma (contagem de bolas por valeta)
int *get_histogram();

// Retorna o número total de bolas que já chegaram nas valetas
int get_total_count();

#endif
