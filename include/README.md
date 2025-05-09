# ./include

📚 Bibliotecas SSD1306 para Display OLED

Este repositório contém as bibliotecas para controle do display OLED SSD1306 no projeto desenvolvido para o Raspberry Pi Pico. Essas bibliotecas são responsáveis pela comunicação e controle do display utilizando o protocolo I2C.
📂 Estrutura das Bibliotecas

As bibliotecas estão organizadas da seguinte forma:

/lib/ssd1306
│── ssd1306_font.h   # Definições de fontes para renderização de textos no OLED
│── ssd1306_i2c.h    # Cabeçalho para a comunicação I2C com o display
│── ssd1306_i2c.c    # Implementação da comunicação I2C para o display
│── ssd1306.h        # Cabeçalho principal da biblioteca SSD1306

Descrição dos Arquivos

    ssd1306_font.h: Contém as definições das fontes que são usadas para renderizar textos no display. Através dessa biblioteca, é possível definir o tamanho e estilo das fontes.

    ssd1306_i2c.h: Define a interface para a comunicação I2C com o display. Ela especifica funções para inicialização, configuração e controle do display via protocolo I2C.

    ssd1306_i2c.c: Implementação das funções de comunicação I2C descritas em ssd1306_i2c.h. Este arquivo é responsável por enviar e receber dados do display através da interface I2C.

    ssd1306.h: Cabeçalho principal da biblioteca, onde estão declaradas as funções essenciais para a operação do display OLED SSD1306, como inicialização, limpeza da tela, desenho de pixels, etc.

🛠️ Configuração do Projeto

Para usar essas bibliotecas no seu projeto, inclua os arquivos de cabeçalho (.h) nos seus arquivos de código-fonte e adicione o código necessário para inicializar e interagir com o display OLED SSD1306.
Exemplo de Inclusão no CMakeLists.txt

Para garantir que o código de sua aplicação consiga acessar as bibliotecas do OLED, você precisa incluir as referências no arquivo CMakeLists.txt do seu projeto. Aqui está um exemplo de como configurar isso:

target_include_directories(${PROJECT_NAME} PRIVATE
    ${CMAKE_CURRENT_LIST_DIR}/lib/ssd1306
)

Esse comando permite que o seu projeto acesse as bibliotecas SSD1306, que estão na pasta lib/ssd1306.
Exemplo de Uso

Aqui está um exemplo simples de como inicializar o display e desenhar um texto:

#include "ssd1306.h"

int main() {
    ssd1306_init();
    ssd1306_clear();
    ssd1306_draw_string(0, 0, "Olá, Mundo!");
    ssd1306_render();
    return 0;
}

🚀 Licença

Esse repositório e as bibliotecas estão licenciados sob a Licença MIT, podendo ser usados, modificados e distribuídos livremente, desde que a devida atribuição seja feita.
