#include <stdio.h>
#include "pico/stdlib.h"
#include <inc/matriz_led.h>
#include <inc/count_number.h>
#include <inc/display_ssd1306.h>


int main() {
    stdio_init_all(); // Inicializa entradas e saídas.
    npInit(LED_PIN); // Inicializa matriz de LEDs NeoPixel.
    
    displayInit(); //Inicializa as configurações do display
    
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
