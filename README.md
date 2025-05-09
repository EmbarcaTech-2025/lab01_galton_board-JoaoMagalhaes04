
# Projetos de Sistemas Embarcados - EmbarcaTech 2025

Autor: João Fernandes

Curso: Residência Tecnológica em Sistemas Embarcados

Instituição: EmbarcaTech - HBr

Campinas, maio de 2025

---

# 🚀 Galton Board - Sistema Embarcado no Raspberry Pi Pico W

📚 **Objetivo**

Este repositório contém o código-fonte do projeto **Galton Board** desenvolvido para o Raspberry Pi Pico W. O projeto simula o comportamento de uma Galton Board utilizando um display SSD1306 para exibir as bolas caindo e o histograma das quedas.

📂 **Estrutura do Repositório**

galton_board
│── /build # Diretório de compilação (gerado pelo CMake)
│── /src # Código-fonte principal
│ ├── ball.c # Lógica das bolas
│ ├── display.c # Funções para o display
│ └── galton.c # Lógica da Galton Board
│── /include # Cabeçalhos (.h)
│ ├── ball.h # Declarações para as bolas
│ ├── display.h # Declarações para o display
│ └── galton.h # Declarações para a Galton Board
│── /lib # Bibliotecas externas - display Oled
│ └── ssd1306 # Biblioteca SSD1306
│ ├── ssd1306.c # Comunicação com o display
│ ├── ssd1306.h # Definições da biblioteca
│ ├── ssd1306_i2c.c# Funções I2C para comunicação
│ ├── ssd1306_i2c.h# Cabeçalho I2C
│ └── ssd1306_font.h # Fontes para o display
|── main.c #arquivo principal
│── CMakeLists.txt # Configuração do CMake
│── pico_sdk_import.cmake # Importação do SDK da Raspberry Pi
└── README.md # Documentação do projeto


🛠️ **Requisitos e Configuração**

Para compilar e rodar o projeto no Raspberry Pi Pico W, siga os passos abaixo:

1. Instale o SDK do Raspberry Pi Pico seguindo as instruções [aqui](https://www.raspberrypi.org/documentation/rp2040/getting-started/).
2. Clone este repositório:

    ```bash
    git clone https://github.com/seu_usuario/galton_board.git
    cd galton_board
    ```

3. Crie o diretório de build e compile:

    ```bash
    mkdir build
    cd build
    cmake ..
    make
    ```

4. Carregue o firmware no Raspberry Pi Pico W.

👤 **Autor**

João Fernandes - Hbr Campinas

Se tiver dúvidas ou sugestões, fique à vontade para contribuir ou abrir uma issue. 🚀

## 📜 Licença
MIT License - MIT GPL-3.0.

