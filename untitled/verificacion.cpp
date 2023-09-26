int latchPin1 = 5; // Pin Latch del primer 74HC595
int clockPin1 = 6; // Pin Clock del primer 74HC595
int dataPin1 = 4;  // Pin Datos del primer 74HC595

int latchPin2 = 2; // Pin Latch del segundo 74HC595
int clockPin2 = 1; // Pin Clock del segundo 74HC595
int dataPin2 = 0;  // Pin Datos del segundo 74HC595

unsigned long previousMillis = 0; // Almacenar el tiempo anterior
const long interval = 1000;      // Intervalo de tiempo deseado (1 segundo)

byte* ledsData1; // Puntero a datos de LEDs para el primer registro
byte* ledsData2; // Puntero a datos de LEDs para el segundo registro
bool ledsEncendidos = false; // Variable para rastrear el estado de los LEDs

void actualizarRegistros(byte* data1, byte* data2) {
  // Actualizar registros de desplazamiento con nuevos datos
  digitalWrite(latchPin1, LOW);
  shiftOut(dataPin1, clockPin1, MSBFIRST, *data1);
  digitalWrite(latchPin1, HIGH);

  digitalWrite(latchPin2, LOW);
  shiftOut(dataPin2, clockPin2, MSBFIRST, *data2);
  digitalWrite(latchPin2, HIGH);
}

void setup() {
  // Configurar pines como salida
  pinMode(latchPin1, OUTPUT);
  pinMode(dataPin1, OUTPUT);
  pinMode(clockPin1, OUTPUT);

  pinMode(latchPin2, OUTPUT);
  pinMode(dataPin2, OUTPUT);
  pinMode(clockPin2, OUTPUT);

  // Inicializar el registro de desplazamiento con todos los LEDs apagados
  ledsData1 = new byte[1]{0x00};
  ledsData2 = new byte[1]{0x00};
  actualizarRegistros(ledsData1, ledsData2);

  // Liberar la memoria dinámica al final de la configuración
  delete[] ledsData1;
  delete[] ledsData2;
}

void loop() {
  verificacion(); // Llamar a la función de verificación
}

void verificacion() {
  unsigned long currentMillis = millis(); // Obtener el tiempo actual

  // Verificar si ha pasado 1 segundo desde la última vez
  if (currentMillis - previousMillis >= interval) {
    previousMillis = currentMillis; // Guardar el tiempo actual

    // Cambiar el estado de los LEDs
    ledsEncendidos = !ledsEncendidos;

    // Actualizar los registros de desplazamiento en función del estado de los LEDs
    if (ledsEncendidos) {
      *ledsData1 = 0xFF; // Encender todos los LEDs en el primer registro
      *ledsData2 = 0xFF; // Encender todos los LEDs en el segundo registro
    } else {
      *ledsData1 = 0x00; // Apagar todos los LEDs en el primer registro
      *ledsData2 = 0x00; // Apagar todos los LEDs en el segundo registro
    }

    actualizarRegistros(ledsData1, ledsData2);
  }
}
