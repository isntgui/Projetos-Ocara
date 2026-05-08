const byte digitos[10][7] = {{1, 1, 1, 0, 1, 1, 1},
							               {1, 0, 0, 0, 1, 0, 0},
              							 {1, 1, 0, 1, 0, 1, 1},
              							 {1, 1, 0, 1, 1, 1, 0},
              							 {1, 0, 1, 1, 1, 0, 0}, 
              							 {0, 1, 1, 1, 1, 1, 0},
              							 {0, 1, 1, 1, 1, 1, 1},
               							 {1, 1, 0, 0, 1, 0, 0},
              							 {1, 1, 1, 1, 1, 1, 1},
              							 {1, 1, 1, 1, 1, 1, 0}};
    					            // {b, a, f, g, c, d, e}

void setup(){
  for(int pino = 13; pino >= 7; pino--){
    pinMode(pino, OUTPUT);
  }
}

void loop(){
  for (int digit = 0; digit < 10; digit++) { // [0, 9]
    for (int pino = 13; pino >= 7; pino--) {
      digitalWrite(pino, digitos[digit][13 - pino]);
    }
    delay(1000);
  }
}
