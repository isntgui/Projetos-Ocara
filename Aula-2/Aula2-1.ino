// código para ascender todas as cores com RGB (forma minimizada sem muita repetição de código)

#define led_red 10
#define led_green 7
#define led_blue 4

int comb[][3] = {{0, 0, 0}, {1, 0, 0}, {0, 1, 0}, {0, 0, 1}, {1, 1, 0}, {1, 0, 1}, {0, 1, 1}, {1, 1, 1}}; // matriz para guardar todas as combinações possíveis entre os pinos
int row = sizeof(comb) / sizeof(comb[0]); // sizeof lê o tamanho de alguma coisa (variavel e tipos) em bytes, estou utilizando para descobrir o número de linhas da matriz

void setup() {
  pinMode(led_red, OUTPUT);
  pinMode(led_green, OUTPUT);
  pinMode(led_blue, OUTPUT);

  Serial.begin(9600); // Iniciar comunicação serial, configurando a taxa de transferência de dados (baud rate) em bits por segundo (usado para print, println e etc...)
}

void loop() {
  for (int i = 0; i < row; i++) { // estou percorrendo todas as combinações que estão armazenadas na matriz
    digitalWrite(led_red,   comb[i][0]);
    digitalWrite(led_green, comb[i][1]);
    digitalWrite(led_blue,  comb[i][2]);
    delay(1000);
  }
}
