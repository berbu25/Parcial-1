int latchPin1 = 5;
int clockPin1 = 6;
int dataPin1 = 4;

int latchPin2 = 2;
int clockPin2 = 1;
int dataPin2 = 0;

byte matrizLEDs[8][8];

// Define las coordenadas de los LEDs que forman la letra "X"
int patronX[8][8] = {
  {1, 0, 0, 0, 0, 0, 0, 1},
  {0, 1, 0, 0, 0, 0, 1, 0},
  {0, 0, 1, 0, 0, 1, 0, 0},
  {0, 0, 0, 1, 1, 0, 0, 0},
  {0, 0, 0, 1, 1, 0, 0, 0},
  {0, 0, 1, 0, 0, 1, 0, 0},
  {0, 1, 0, 0, 0, 0, 1, 0},
  {1, 0, 0, 0, 0, 0, 0, 1}
};

void setup() {
  pinMode(latchPin1, OUTPUT);
  pinMode(dataPin1, OUTPUT);
  pinMode(clockPin1, OUTPUT);

  pinMode(latchPin2, OUTPUT);
  pinMode(dataPin2, OUTPUT);
  pinMode(clockPin2, OUTPUT);


}

void loop() {
  // Enciende y apaga solo los LEDs que forman el patrón "X"
  for (int fila = 0; fila < 8; fila++) {
    for (int col = 0; col < 8; col++) {
      if (patronX[fila][col] == 1) {
        //matrizLEDs[fila][col] = HIGH;
        // Actualiza los registros de desplazamiento
      actualizarRegistroDeDesplazamientoON(latchPin1, dataPin1, clockPin1, latchPin2, dataPin2, clockPin2);
      }
      if (patronX[fila][col] == 0) {
        //matrizLEDs[fila][col] = HIGH;
        // Actualiza los registros de desplazamiento
      actualizarRegistroDeDesplazamientoOFF(latchPin1, dataPin1, clockPin1, latchPin2, dataPin2, clockPin2);
      }


      delay(1000); // Espera un breve periodo de tiempo para que los LEDs sean visibles
    }
  }
}



void actualizarRegistroDeDesplazamientoON(int latchPin1, int dataPin1, int clockPin1, int latchPin2, int dataPin2, int clockPin2) {
  digitalWrite(latchPin1, LOW);
  shiftOut(dataPin1, clockPin1, LSBFIRST, 255); // Envía datos al primer registro
  digitalWrite(latchPin1, HIGH);


}

void actualizarRegistroDeDesplazamientoOFF(int latchPin1, int dataPin1, int clockPin1, int latchPin2, int dataPin2, int clockPin2) {
  digitalWrite(latchPin1, LOW);
  shiftOut(dataPin1, clockPin1, LSBFIRST, 0); // Envía datos nulos al primer registro
  digitalWrite(latchPin1, LOW);


}
