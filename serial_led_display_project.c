#include <stdio.h>
#include "pico/stdlib.h"
#include <inc/matriz_led.h>
#include <inc/count_number.h>

int main() {

    stdio_init_all(); // Inicializa entradas e saídas.
    npInit(LED_PIN); // Inicializa matriz de LEDs NeoPixel.

    char caractere;

    while (true) {
        sleep_ms(50);

        printf("\nDigite uma tecla: ");
        scanf("%c", &caractere);

        if (caractere != '\0') {
            printf("Tecla pressionada: %c\n", caractere);

            controle_numero(caractere);
        }
    }
    return 0;
}
