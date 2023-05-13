#ifndef HMI_h
#define HMI_h
#include <Arduino.h>
#include <string>
#include <vector> 
#include <ctype.h>
#include <cstdint>
#include "Pantalla.h"
#include "Teclado.h"
#include "ComunicacionConMultiparrilla.h"

#define DESACTIVADO -1

extern Multiparrilla multiparrilla;

extern uint8_t no_de_funcion;

void inicializar_datos_de_plazas();

void inicializar_HMI();

uint8_t menu_principal();

void configurar_agitacion_y_calentamiento();

void activar_o_desactivar_plazas();

bool validar_que_por_lo_menos_haya_una_plaza_activada();

void elegir_sensor_de_temperatura();

void elegir_funcion_de_calentamiento();

void establecer_setpoint_para_un_calentamiento_constante();

void establecer_setpoints_para_una_rampa_de_temperatura();

void establecer_setpoint_de_agitacion(const bool funcion_de_temperatura); //constante:false - rampa:true

void establecer_minutos_para_mantener_setpoints(const bool funcion_de_tempratura);

void menu_agregar_o_cancelar_rutina(const bool funcion_de_temperatura);

void menu_resumen_de_las_rutinas_configuradas();

void enviar_rutinas_configuradas();

void monitorear_agitacion_y_temperatura();

void mostrar_el_estado_del_enlace();
#endif