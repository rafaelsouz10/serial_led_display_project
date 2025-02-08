# Sistema de Comunicação Serial e Controle de Matriz RGB e Display OLED

---

## Descrição do Projeto

Projeto da atividade **EmbarcaTech**, sobre comunicação serial (UART e I2C) e o controle de dispositivos na placa BitDogLab. A implementação inclui:
    
✅ **Entrada Serial e display SSD1306**: Captura de caracteres via Serial Monitor para exibição no display SSD1306.  
✅ **Matriz de LEDs WS2812**: Exibição de símbolos numéricos ao receber números entre 0 e 9.    
✅ **Interação com Botões**: Alternância do LED RGB ao pressionar os botões A e B, com mensagens exibidas no display e no Serial Monitor.   
✅ **Uso de Interrupções e Debounce**: Implementação de IRQs e tratamento de bouncing nos botões.

![image](https://github.com/user-attachments/assets/bf56e9b6-b3f5-4c58-bdb0-8d2c7e683358)

## Requisitos

- **Microcontrolador**: Raspberry Pi Pico ou Raspberry Pi Pico W (opcional)
- **Placa de Desenvolvimento:** BitDogLab (opcional).
- **Conta Criada no Wokwi Simulator**: [Wokwi](https://wokwi.com/).
- **Editor de Código**: Visual Studio Code (VS Code).
- **SDK do Raspberry Pi Pico** configurado no sistema.
- Ferramentas de build: **CMake** e **Ninja**.

---

## Instruções de Uso

### 1. Clone o Repositório

Clone o repositório para o seu computador:
```bash
git clone git@github.com:rafaelsouz10/serial_led_display_project.git
cd serial_led_display_project
code .
```
---

### 2. Instale as Dependências

Certifique-se de que o SDK do Raspberry Pi Pico está configurado corretamente no VS Code. As extensões recomendadas são:

- **C/C++** (Microsoft).
- **CMake Tools**.
- **Wokwi Simulator**.
- **Raspberry Pi Pico**.

---

### 3. Configure o VS Code

Abra o projeto no Visual Studio Code e siga as etapas abaixo:

1. Certifique-se de que as extensões mencionadas anteriormente estão instaladas.
2. No terminal do VS Code, compile o código clicando em "Compile Project" na interface da extensão do Raspberry Pi Pico.
3. O processo gerará o arquivo `.uf2` necessário para a execução no hardware real.

---

### 4. Teste no Simulador Wokwi Integrado ao VS Code

Após ter configurado o VS Code conforme descrito no item 3, siga os passos abaixo para simular o projeto:

1. Abra o arquivo `diagram.json` no Visual Studio Code.
2. Clique no botão "Play" disponível na interface.
3. Divirta-se interagindo com os componentes disponíveis no simulador integrado!

---

### 5. Teste no Hardware Real

#### Utilizando a Placa de Desenvolvimento BitDogLab com Raspberry Pi Pico W:

1. Conecte a placa ao computador no modo BOTSEEL:
   - Pressione o botão **BOOTSEL** (localizado na parte de trás da placa de desenvolvimento) e, em seguida, o botão **RESET** (localizado na frente da placa).
   - Após alguns segundos, solte o botão **RESET** e, logo depois, solte o botão **BOOTSEL**.
   - A placa entrará no modo de programação.

2. Compile o projeto no VS Code utilizando a extensão do [Raspberry Pi Pico W](https://marketplace.visualstudio.com/items?itemName=raspberry-pi.raspberry-pi-pico):
   - Clique em **Compile Project**.

3. Execute o projeto clicando em **Run Project USB**, localizado abaixo do botão **Compile Project**.

---

### 6. Conexões e Esquemático

Abaixo está o mapeamento de conexões entre os componentes e a Raspberry Pi Pico W para os ambientes **Wokwi** (simulação) e **BitDogLab** (hardware físico):

|    **Componentes**        |**GPIO** |  
|---------------------------|---------|  
| Matriz de LEDs WS2812     | GPIO 7  |   
| LED RGB (LED_GREEN)       | GPIO 11 |  
| LED RGB (LED_BLUE)        | GPIO 12 |  
| Botão A                   | GPIO 5  |  
| Botão B                   | GPIO 6  |  
| Display SSD1306 (I2C) SDA | GPIO 14 |
| Display SSD1306 (I2C) SCL | GPIO 15 | 

### 7. Funcionamento do Sistema  

1. **Inicialização**:
- O sistema inicia e aguarda a entrada de caracteres via **Serial Monitor**.  
- O display SSD1306 é inicializado e pronto para exibir os caracteres recebidos. 
- A Matriz RGB é incializada e pronta para exibir os caracteres numéricos. 

### 2. Entrada de Caracteres via Serial  
- O usuário digita um caractere no **Serial Monitor**.  
- O caractere é exibido imediatamente no **display SSD1306**.  
- Se for um número entre **0 e 9**, um símbolo correspondente será exibido na **matriz de LEDs WS2812**.  

### 3. Interação com os Botões  
#### 🔘 **Botão A (GPIO 5)**  
- Alterna o estado do **LED RGB Verde** (liga/desliga).  
- Mensagem informando a mudança no **display SSD1306** é exibida:  "Led Verde ON/OFF"
- Envia um log da ação ao **Serial Monitor**.  

#### 🔘 **Botão B (GPIO 6)**  
- Alterna o estado do **LED RGB Azul** (liga/desliga).  
- Mensagem informando a mudança no **display SSD1306**é exibida:   "Led Azul ON/OFF"
- Envia um log da ação ao **Serial Monitor**.  

### 4. Interrupções e Debounce  
- Os botões utilizam **interrupções (IRQ)** para garantir respostas rápidas.  
- Foi implementado um **debounce via software** para evitar leituras falsas devido a ruídos mecânicos.  

### 5. Controle da Matriz de LEDs WS2812  
- Quando um número de **0 a 9** é recebido via **Serial Monitor**, um símbolo correspondente é exibido na **matriz de LEDs 5x5**.  
- Isso permite a representação visual dos números usando os LEDs endereçáveis.  

### 6. Comunicação Serial (UART)  
- A UART é utilizada para **receber caracteres** e **exibir logs das ações dos botões e leds**. 

### 8. Vídeo Demonstrativo

Click [AQUI](https://drive.google.com/file/d/1yuaB1rB0Mb9bUAn2dsNlylHCa4Cl1D_K/view?usp=sharing) para acessar o link do Vídeo Ensaio
