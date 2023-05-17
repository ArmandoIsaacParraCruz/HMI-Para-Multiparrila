#ifndef Pantalla_h
#define Patanlla_h
#include <Arduino.h>
#include <string>
#include <iostream>
#include <TFT_eSPI.h>   //Librería para el controlador ST7789 de la pantalla tft 2.4"
#include <SPI.h>        //Librería de comunicación SPI
#include "Free_Fonts.h" //Librería para obtener fuentes de letras para la interfaz
#include "Logo_UAM.h"   //Se incluye la matriz que contiene la imagen del logo de la UAM
#include "My_Colors.h"  //Se incluye los colores personalizados para la pantalla tft
#include "multiparrillaImagen300x82.h"

extern TFT_eSPI pantalla;

void inicializar_pantalla();

void mostrar_logo_UAM();

void colocar_elementos_de_fondo_del_menu_principal();

void mostrar_opciones_del_menu_principal();

void resaltar_opcion_en_posicion_actual_del_menu_principal(uint8_t );

void mostrar_opcion_elegida_en_el_menu_principal(uint8_t);

void colocar_elementos_de_fondo_del_menu_configurar_agitacion_y_calentamiento();

void mostrar_imagen_multiparrilla();

void resaltar_opcion_en_posicion_actual_del_menu_configurar_agitacion_y_calentamiento(uint8_t);

void mostrar_opciones_del_menu_configurar_agitacion_y_calentamiento();

void colocar_elementos_de_fondo_del_menu_activar_o_desactivar_plazas(bool *plazas_activadas, const uint8_t cantidad_de_plazas);

void desplegar_mensaje_de_que_no_se_ha_activado_ninguna_plaza();

void resaltar_opcion_en_posicion_actual_del_menu_activar_o_desactivar_plazas(bool *plazas_activadas, uint8_t indice_plaza_actual, const uint8_t cantidad_de_plazas);

void mostrar_opciones_del_menu_activar_o_desactivar_plazas(uint8_t);

void colocar_en_gris_el_marco_del_numero_de_la_plaza_actual(uint8_t);

void colocar_elementos_de_fondo_del_menu_elegir_sensor_de_temperatura();

void resaltar_opcion_en_posicion_actual_del_menu_elegir_sensor_de_temperatura(uint8_t);

void mostrar_opciones_del_menu_elegir_sensor_de_temperatura(bool sensorInfrarrojo);

void colocar_elementos_de_fondo_del_menu_elegir_funcion_de_calentamiento();

void mostrar_opciones_del_menu_elegir_funcion_de_calentamiento(uint8_t);

void colocar_elementos_de_fondo_del_menu_establecer_setpoint_para_un_calentamiento_constante();

void coloca_valor_de_temperatura_en_el_menu_establecer_setpoint_para_un_calentamiento_constante(uint16_t temperatura);

void colocar_elementos_de_fondo_del_menu_establecer_setpoint_para_un_calentamiento_en_rampa_inicial();

void coloca_valor_de_temperatura_en_el_menu_establecer_setpoint_para_un_calentamiento_en_rampa_inicial(uint16_t temperatura);

void colocar_elementos_de_fondo_del_menu_establecer_setpoint_para_un_calentamiento_en_rampa_final();

void colocar_valor_de_temperatura_en_el_menu_establecer_setpoint_para_un_calentamiento_en_rampa_final(uint16_t temperatura);

void colocar_elementos_de_fondo_del_menu_establecer_setpoint_de_agitacion(bool agregar_espacio);

void colocar_valor_de_rpm_en_el_menu_establecer_setpoint_de_agitacion(uint16_t rpm, bool agregar_espacio);

void colocar_elementos_de_fondo_del_menu_establecer_minutos_para_mantener_setpoints(bool agregar_espacio);

void colocar_valor_de_minutos_en_el_menu_estalecer_minutos_para_mantener_setpoints(uint32_t minutos, bool agregar_espacio);

void colocar_elementos_de_fondo_menu_agregar_o_cancelar_rutina();

void colocar_elementos_de_fondo_del_menu_mostrar_el_estado_del_enlace();

void mostrar_en_pantalla_el_estado_del_enlace(const bool conectado);

#endif