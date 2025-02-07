#include <stdio.h>
#include "pico/stdlib.h"
#include <inc/matriz_led.h>
#include <inc/count_number.h>
#include "hardware/i2c.h"
#include "inc/ssd1306.h"
#include "inc/font.h"

#define I2C_PORT i2c1
#define I2C_SDA 14
#define I2C_SCL 15
#define endereco 0x3C


int main() {
    stdio_init_all(); // Inicializa entradas e saídas.
    npInit(LED_PIN); // Inicializa matriz de LEDs NeoPixel.
    
    // I2C Initialisation. Using it at 400Khz.
    i2c_init(I2C_PORT, 400 * 1000);

    gpio_set_function(I2C_SDA, GPIO_FUNC_I2C); // Set the GPIO pin function to I2C
    gpio_set_function(I2C_SCL, GPIO_FUNC_I2C); // Set the GPIO pin function to I2C
    gpio_pull_up(I2C_SDA); // Pull up the data line
    gpio_pull_up(I2C_SCL); // Pull up the clock line
    ssd1306_t ssd; // Inicializa a estrutura do display
    ssd1306_init(&ssd, WIDTH, HEIGHT, false, endereco, I2C_PORT); // Inicializa o display
    ssd1306_config(&ssd); // Configura o display
    ssd1306_send_data(&ssd); // Envia os dados para o display

    // Limpa o display. O display inicia com todos os pixels apagados.
    ssd1306_fill(&ssd, false);
    ssd1306_send_data(&ssd);

    bool cor = true;

    char caractere[2] = {0}; // Garante que seja uma string válida

    while (true) {
        sleep_ms(50);
        printf("\nDigite uma Caractere: ");
        scanf("%c", &caractere[0]);
        caractere[1] = '\0'; // Garante terminação de string

        if (caractere[0] != '\0') {
            printf("%c\n", caractere[0]);
            controle_numero(caractere[0]);

            cor = !cor;
            // Atualiza o conteúdo do display com animações
            ssd1306_fill(&ssd, !cor); // Limpa o display
            ssd1306_rect(&ssd, 3, 3, 122, 58, cor, !cor); // Desenha um retângulo
            ssd1306_draw_string(&ssd, "CEPEDI   TIC37", 8, 10); // Desenha uma string
            ssd1306_draw_string(&ssd, "EMBARCATECH", 20, 30); // Desenha uma string
            ssd1306_draw_string(&ssd, caractere, 60, 48); // Desenha uma string      
            ssd1306_send_data(&ssd); // Atualiza o display
        }
    }
    return 0;
}
