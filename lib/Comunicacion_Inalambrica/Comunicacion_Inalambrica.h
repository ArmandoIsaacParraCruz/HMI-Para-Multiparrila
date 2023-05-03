#ifndef Comunicacion_Inalambrica_h
#define Comunicacion_Inalambrica_h
#include <Arduino.h>
#include <WiFi.h>
#include "ESPNowW.h"


extern uint8_t esclavo_mac[];

void iniComunicacionInalambrica();

bool obtenerEstadoDelEnlace();

void enviarMensaje();




#endif