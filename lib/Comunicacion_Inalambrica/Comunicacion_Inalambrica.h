#ifndef Comunicacion_Inalambrica_h
#define Comunicacion_Inalambrica_h
#include <Arduino.h>
#include <WiFi.h>
#include "ESPNowW.h"

extern uint8_t mac_multiparrilla[];
extern uint8_t mac_HMI[];

void inicializaComunicacionInalambrica();
void recibirMensaje(const uint8_t *, const uint8_t *, int);
bool obtenerEstadoDelEnlace();
void mensajeRecibidoPorElReceptor(const uint8_t *, esp_now_send_status_t );
void enviarMensaje();




#endif