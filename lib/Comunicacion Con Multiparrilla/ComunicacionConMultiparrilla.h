#ifndef ComunicacionConMultiparrilla_h
#define ComunicacionConMultiparrilla_h
#include <Arduino.h>
#include <WiFi.h>
#include "ESPNowW.h"

extern uint8_t mac_multiparrilla[];
extern uint8_t mac_HMI[];

void inicializar_comunicacion_con_multiparrilla();
void recibir_mensaje(const uint8_t *, const uint8_t *, int);
bool obtener_estado_del_enlace();
void enviar_mensaje();
void esperar(uint16_t);




#endif