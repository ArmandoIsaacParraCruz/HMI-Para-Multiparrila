#ifndef ComunicacionConMultiparrilla_h
#define ComunicacionConMultiparrilla_h
#include <Arduino.h>
#include <WiFi.h>
#include "ESPNowW.h"
#include <vector> 

#define CANT_PLAZAS 6

extern uint8_t mac_multiparrilla[];
extern uint8_t mac_HMI[];

struct Multiparrilla {
    bool sensor_infrarrojo; 
    bool plazas_activadas[CANT_PLAZAS];
    std::vector<uint16_t>setpoints_temperatura;
    std::vector<char>funcion_de_temperatura;
    std::vector<uint16_t>setpoints_agitacion; 
    std::vector<uint32_t> minutos_para_mantener_setpoints; 
};

void inicializar_comunicacion_con_multiparrilla();
void recibir_mensaje(const uint8_t *, const uint8_t *, int);
bool obtener_estado_del_enlace();
void enviar_mensaje_de_prueba();
bool enviar_rutinas(Multiparrilla mensaje_rutina);
void esperar(uint16_t);




#endif