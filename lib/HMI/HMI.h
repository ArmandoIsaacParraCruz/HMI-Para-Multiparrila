#ifndef HMI_h
#define HMI_h
#include <Arduino.h>
#include <string>
#include <vector> 
#include <ctype.h>
#include "Pantalla.h"
#include "Teclado.h"
#include "ComunicacionConMultiparrilla.h"

#define CANT_PLAZAS 6


struct Multiparrilla {
    bool sensor_infrarrojo; 
    bool plazas_activadas[CANT_PLAZAS];
    std::vector<uint16_t>setpoints_temperatura;
    std::vector<char>funcion_de_temperatura;
    std::vector<uint16_t>setpoints_agitacion; 
    std::vector<uint16_t> minutos_para_mantener_setpoints; 
};

extern Multiparrilla multiparrilla;

void inicializar_plazas();
void inicializar_HMI();
uint8_t menu_principal();
void configurar_agitacion_y_calentamiento();
void activar_o_desactivar_plazas();
bool validar_que_por_lo_menos_haya_una_plaza_activada();
void elegir_sensor_de_temperatura();
void elegir_funcion_de_calentamiento();
void establecer_setpoint_para_un_calentamiento_constante();
void establecer_setpoints_para_una_rampa_de_temperatura();
void establecer_setpoint_de_agitacion();
void monitorear_agitacion_y_temperatura();
void mostrar_el_estado_del_enlace();
#endif