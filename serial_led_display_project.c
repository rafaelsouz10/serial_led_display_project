#include <stdio.h>
#include "pico/stdlib.h"
#include <inc/matriz_led.h>
#include <inc/count_number.h>
#include <inc/display_ssd1306.h>
#include <inc/config_btn.h>

int main() {
    stdio_init_all(); // Inicializa entradas e saídas.
    npInit(LED_PIN); // Inicializa matriz de LEDs NeoPixel.
    displayInit(); //Inicializa as configurações do display
    setup_gpio_buttons(); // Configuração inicial ds botões
    setup_gpio_leds();  //Configuração incial dos leds
  
    gpio_set_irq_interrupt_btn();// Configuração da interrupção com callback para botão
    
    bool cor = true;

    char caractere[2] = {'-', '\0'}; //vetor[2] para armazenar o caracter digitado com um caractere nulo, visto que o displa aceita somente string
    char estado_led_blue[20];   // Variável para armazenar o estado do LED azul
    char estado_led_green[20];   // Variável para armazenar o estado do LED verde

    while (true) {
        sleep_ms(50);

        // Atualiza as variáveis com o estado dos LEDs azul e verde
        sprintf(estado_led_blue, "Led Azul %s", led_blue_state ? "ON" : "OFF");
        sprintf(estado_led_green, "Led Verde %s", led_green_state ? "ON" : "OFF");

        ssd1306_fill(&ssd, !cor); // Limpa o display
        // Atualiza o conteúdo do display com animações
        ssd1306_rect(&ssd, 3, 3, 122, 58, cor, !cor); // Desenha um retângulo
        ssd1306_draw_string(&ssd, "EMBARCATECH", 20, 10); // Desenha uma string
        ssd1306_draw_string(&ssd, estado_led_green, 10, 25); // Exibe o estado do LED azul no display
        ssd1306_draw_string(&ssd, estado_led_blue, 10, 35); // Exibe o estado do LED azul no display
        ssd1306_draw_string(&ssd, caractere, 60, 48); // Desenha uma string  
        ssd1306_send_data(&ssd); // Atualiza o display
        
        if (stdio_usb_connected()) { 
            int c = getchar_timeout_us(100000); // Aguarda até 100ms para receber um caractere
            if (c != PICO_ERROR_TIMEOUT && c != '\n') { // Ignora o timeout e novas linhas '\n'
                caractere[0] = (char)c; // Atualiza o caractere
                controle_numero(caractere[0]);
            }
        }
    }
    return 0;
}
