#ifndef CONFIG_BTN_H
#define CONFIG_BTN_H

#include "hardware/timer.h"

//definição de GPIO LEDS
#define LED_GREEN 11
#define LED_BLUE 12
//definição de GPIO botões
#define BTN_A 5
#define BTN_B 6

// Variáveis globais 
static volatile uint32_t last_time = 0; // Armazena o tempo do último evento (em microssegundos)
bool led_green_state = false;
bool led_blue_state = false;

void setup_gpio_leds(){
  gpio_init(LED_GREEN);
  gpio_set_dir(LED_GREEN, GPIO_OUT);
  gpio_init(LED_BLUE);
  gpio_set_dir(LED_BLUE, GPIO_OUT);
}

// Configuração inicial ds botões
void setup_gpio_buttons() {
  //Botão A
  gpio_init(BTN_A);
  gpio_set_dir(BTN_A, GPIO_IN);
  gpio_pull_up(BTN_A);

  //Botão B
  gpio_init(BTN_B);
  gpio_set_dir(BTN_B, GPIO_IN);
  gpio_pull_up(BTN_B);
}

// Função de interrupção com debouncing do botão
void gpio_irq_handler(uint gpio, uint32_t events){

  // Obtém o tempo atual em microssegundos
  uint32_t current_time = to_us_since_boot(get_absolute_time());
  
  // Verifica se passou tempo suficiente desde o último evento
  if (current_time - last_time > 200000) { // 300 ms de debouncing
    last_time = current_time; // Atualiza o tempo do último evento

    if (gpio == BTN_A) {
      printf("\nBotão A pressionado. ");
      led_green_state = !led_green_state; // Alterna o estado
      gpio_put(LED_GREEN, led_green_state);
      printf("LED Verde %s\n", led_green_state ? "LIGADO!" : "DESLIGADO!");

    } else if (gpio == BTN_B) {
      printf("\nBotão B pressionado. ");
      led_blue_state = !led_blue_state; // Alterna o estado
      gpio_put(LED_BLUE, led_blue_state);
      printf("LED Azul %s\n", led_blue_state ? "LIGADO!" : "DESLIGADO!");
    }
  }
}

void gpio_set_irq_interrupt_btn(){
    // Configuração da interrupção com callback para botão A
    gpio_set_irq_enabled_with_callback(BTN_A, GPIO_IRQ_EDGE_FALL, true, &gpio_irq_handler);
    // Configuração da interrupção com callback para botão B
    gpio_set_irq_enabled_with_callback(BTN_B, GPIO_IRQ_EDGE_FALL, true, &gpio_irq_handler);
}

#endif