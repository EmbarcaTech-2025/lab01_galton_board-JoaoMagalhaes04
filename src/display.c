#include "display.h"
#include "ssd1306.h"
#include "string.h"
#include "stdio.h"

#define I2C_SDA 14
#define I2C_SCL 15

// Buffer para armazenamento dos pixels do display
static uint8_t buffer[ssd1306_buffer_length];

// Área completa do display usada para renderização
static struct render_area frame_area = {
    .start_column = 0,
    .end_column = ssd1306_width - 1,
    .start_page = 0,
    .end_page = ssd1306_n_pages - 1
};

// Inicializa o display OLED via I2C e limpa a tela
void display_init() {
    i2c_init(i2c1, ssd1306_i2c_clock * 1000);           // Inicializa o I2C
    gpio_set_function(I2C_SDA, GPIO_FUNC_I2C);          // Define pinos SDA/SCL como I2C
    gpio_set_function(I2C_SCL, GPIO_FUNC_I2C);
    gpio_pull_up(I2C_SDA);                              // Puxadores de pull-up
    gpio_pull_up(I2C_SCL);
    ssd1306_init();                                     // Inicializa o driver do display

    calculate_render_area_buffer_length(&frame_area);   // Define o tamanho do buffer
    display_clear();                                    // Limpa o buffer
    display_render();                                   // Renderiza buffer vazio no display
}

// Limpa o buffer (zera todos os pixels)
void display_clear() {
    memset(buffer, 0, sizeof(buffer));
}

// Envia o buffer para o display real
void display_render() {
    render_on_display(buffer, &frame_area);
}

// Desenha ou apaga um pixel individual no buffer
void display_draw_pixel(int x, int y, bool on) {
    if (x < 0 || x >= ssd1306_width || y < 0 || y >= ssd1306_height)
        return;

    uint8_t page = y / 8;              // Página no display (cada página = 8 pixels verticais)
    uint8_t bit = 1 << (y % 8);        // Bit que representa o pixel na página

    if (on)
        buffer[page * ssd1306_width + x] |= bit;    // Liga o pixel
    else
        buffer[page * ssd1306_width + x] &= ~bit;   // Desliga o pixel
}

// Desenha uma bola com 3 pixels de largura (x-1, x, x+1) para melhor visibilidade
void display_draw_ball(int x, int y) {
    display_draw_pixel(x, y, true);
    display_draw_pixel(x - 1, y, true);
    display_draw_pixel(x + 1, y, true);
}

// Desenha o histograma com base nos valores de cada bin
void display_draw_histogram(int *bins, int n_bins) {
    int max_height = 20;
    int bin_width = 4;  // Largura de cada barra vertical

    // Garante que o histograma cabe na tela
    if (n_bins * bin_width > ssd1306_width) return;

    int max = 1; // Evita divisão por zero
    for (int i = 0; i < n_bins; i++) {
        if (bins[i] > max) max = bins[i]; // Encontra o maior valor do histograma
    }

    // Centraliza o histograma horizontalmente
    int total_width = n_bins * bin_width;
    int start_x = (ssd1306_width - total_width) / 2;

    // Desenha cada barra
    for (int i = 0; i < n_bins; i++) {
        int h = (bins[i] * max_height) / max; // Altura proporcional à frequência

        int x_start = start_x + (i * bin_width);
        for (int x = x_start; x < x_start + bin_width; x++) {
            for (int y = ssd1306_height - 1; y > (ssd1306_height - 1 - h); y--) {
                display_draw_pixel(x, y, true);
            }
        }
    }
}

// Mostra o total de bolas no canto superior esquerdo
void display_draw_total_count(int count) {
    char msg[20];
    snprintf(msg, sizeof(msg), "Total: %d", count);
    ssd1306_draw_string(buffer, 0, 0, msg); // Desenha o texto no topo
}

// Desenha os pinos da Galton Board em formato triangular
void display_draw_pins(int num_pins) {
    int base_x = 64;  // Posição inicial em X (centro)
    int base_y = 10;  // Posição inicial em Y (mais abaixo do topo)

    int total_linhas = 5;

    for (int linha = 0; linha < total_linhas; linha++) {
        int num_pinos = linha + 1;
        int distancia_y = base_y + linha * 8;
        int distancia_x = 8;

        for (int pino = 0; pino < num_pinos; pino++) {
            // Centraliza os pinos horizontalmente em cada linha
            int x = base_x + pino * distancia_x - linha * distancia_x / 2;
            int y = distancia_y;
            display_draw_pixel(x, y, true);
        }
    }
}
