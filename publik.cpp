bool mostrarMensajeInicial = true; // Variable para controlar la visualizacion del mensaje inicial

void setup() {
  Serial.begin(9600); // Inicializar la comunicacion serial a 9600 baudios
}

void loop() {
  publik();
}

void publik() {
  if (mostrarMensajeInicial) {
    Serial.println("\nIngrese el numero que corresponde a la opcion que desea seleccionar:");
    Serial.println("1. Verificacion de la matriz");
    Serial.println("2. Disenar imagen");
    Serial.println("3. Mostrar patrones");
    Serial.println("0. Salir del programa\n"); // Agregado para salir del programa
    mostrarMensajeInicial = false; // Marcar que el mensaje inicial ya se ha mostrado
  }

  if (Serial.available() > 0) {
    char opcion = Serial.read(); // Leer el comando enviado por el puerto serial

    // Menu de opciones
    switch (opcion) {
      case '0':
        Serial.println("Programa finalizado."); // Agregado mensaje de finalizacion
        delay (2000);
        exit(0); // Salir del programa
        break;
      case '1':
        Serial.print("Opcion seleccionada: ");
        Serial.println(opcion);
        Serial.print("\n");
        verificacion(); // Llamar a la funcion verificacion
        break;
      case '2':
        Serial.print("Opcion seleccionada: ");
        Serial.println(opcion);
        Serial.print("\n");
        imagen(); // Llamar a la funcion imagen
        break;
      case '3':
        Serial.print("Opcion seleccionada: ");
        Serial.println(opcion);
        Serial.print("\n");
        patrones(); // Llamar a la funcion patrones
        break;
      default:
        Serial.println("Opcion no valida"); // Opcion no valida
    }

    mostrarMensajeInicial = true; // Volver a mostrar el mensaje inicial
  }
}

void verificacion() {
  // Implementacion de la funcion verificacion
  Serial.println("Funcion verificacion llamada");
}

void imagen() {
  // Implementacion de la funcion imagen
  Serial.println("Funcion imagen llamada");
}

void patrones() {
  // Implementacion de la funcion patrones
  Serial.println("Funcion patrones llamada");
}
