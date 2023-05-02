#include <Arduino.h>
#include "Pantalla_Teclado.h"

uint8_t opcion = 0;

void setup() { 
  
  inicializaHMI();
  Serial.begin(9600);
 
}

void loop() 
{
  opcion = menuPrincipal();
  Serial.println(opcion);
}

