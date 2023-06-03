#ifndef ComunicacionConMultiparrilla_h
#define ComunicacionConMultiparrilla_h
#include <Arduino.h>
#include <WiFi.h>
#include "ESPNowW.h"
#include <vector> 

#define CANTIDAD_DE_PLAZAS 6
#define CANTIDAD_MAXIMA_DE_RUTINAS 20

extern uint8_t mac_multiparrilla[];
extern uint8_t mac_HMI[];

struct Multiparrilla {
    bool sensor_infrarrojo; 
    bool plazas_activadas[CANTIDAD_DE_PLAZAS];
    uint16_t setpoints_temperatura[CANTIDAD_MAXIMA_DE_RUTINAS*2];
    char tipo_de_funcion_de_temperatura[CANTIDAD_MAXIMA_DE_RUTINAS];
    uint16_t setpoints_agitacion[CANTIDAD_MAXIMA_DE_RUTINAS]; 
    uint32_t minutos_para_mantener_setpoints[CANTIDAD_MAXIMA_DE_RUTINAS];
    uint8_t numero_de_rutinas_configuradas;
};

void inicializar_comunicacion_con_multiparrilla();
void recibir_mensaje(const uint8_t *, const uint8_t *, int);
bool obtener_estado_del_enlace();
void enviar_mensaje_de_prueba();
bool enviar_rutinas(Multiparrilla mensaje_rutina);
void esperar(uint16_t);




#endif