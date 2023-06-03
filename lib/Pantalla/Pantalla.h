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

void mostrar_que_la_multiparrilla_no_esta_conectada_en_el_menu_configurar_agitacion_y_calentamiento();

void mostrar_que_se_ha_restablecido_la_conexion_en_el_menu_configurar_agitacion_y_calentamiento();

void mostrar_imagen_multiparrilla();

void resaltar_opcion_en_posicion_actual_del_menu_configurar_agitacion_y_calentamiento(uint8_t);

void mostrar_opciones_del_menu_configurar_agitacion_y_calentamiento();

void colocar_elementos_de_fondo_del_menu_activar_o_desactivar_plazas(bool *plazas_activadas, const uint8_t cantidad_de_plazas);

void desplegar_mensaje_de_que_no_se_ha_activado_ninguna_plaza();

void resaltar_opcion_en_posicion_actual_del_menu_activar_o_desactivar_plazas(bool *plazas_activadas, uint8_t indice_plaza_actual, const uint8_t cantidad_de_plazas);

void mostrar_opciones_del_menu_activar_o_desactivar_plazas(uint8_t);

void colocar_en_gris_el_marco_del_numero_de_la_plaza_actual(uint8_t);

void colocar_elementos_de_fondo_del_menu_elegir_sensor_de_temperatura(bool *plazas_activadas, const uint8_t cantidad_de_plazas);

void resaltar_opcion_en_posicion_actual_del_menu_elegir_sensor_de_temperatura(uint8_t);

void mostrar_opciones_del_menu_elegir_sensor_de_temperatura(bool sensorInfrarrojo);

void colocar_elementos_de_fondo_del_menu_configurar_rutina_de_calentamiento_y_agitacion(bool *plazas_activadas, const uint8_t cantidad_de_plazas);

void mostrar_numero_de_rutina_y_posicion_del_cursor(const uint8_t numero_de_rutina, uint8_t posicion_del_cursor, const char funcion_de_temperatura);

void colocar_elementos_de_la_opcion_elegir_funcion_de_calentamiento(const uint16_t setpoint_temperatura_1, const uint16_t setpoint_temperatura_2, const char tipo_de_funcion, const uint16_t setpoint_agitacion, const uint32_t minutos_para_mantener_setpoints);

void coloca_valor_de_temperatura_en_la_opcion_establecer_primer_setpoint_de_temperatura(const String temperatura, const char funcion_de_temperatura);

void coloca_valor_de_temperatura_en_la_opcion_establecer_segundo_setpoint_de_temperatura(const String segunda_temperatura, const uint16_t primera_temperatura);

void coloca_valor_de_agitacion_en_la_opcion_establecer_setpoint_de_agitacion(const String agitacion, const char funcion_de_temperatura);

void coloca_valor_de_tiempo_en_la_opcion_establecer_minutos_para_mantener_setpoints(const String tiempo, const char funcion_de_temperatura);

void colocar_elementos_de_fondo_del_menu_agregar_o_confirmar_rutinas_configuradas();

void resalta_opcion_en_posicion_actual_del_menu_agregar_o_confirmar_rutinas_configuradas(const uint8_t opcion);

void colocar_elementos_de_fondo_en_el_menu_confirmar_y_enviar_rutinas_configuradas();

void muestra_plazas_activadas_y_sensor_configurado(bool *plazas_activadas, const uint8_t cantidad_de_plazas, const bool sensor_infrarrojo, const uint8_t numero_de_rutinas_configuradas);

void muestra_configuracion_de_la_rutina(const uint8_t numero_de_rutina, const uint8_t numero_de_rutinas_configuradas,const char funcion_de_temp, const uint16_t primer_setpoint_temp,
                                         const uint16_t segundo_setpoint_temp, const uint16_t agitacion, const uint32_t tiempo);

void colocar_elementos_de_fondo_del_menu_mostrar_el_estado_del_enlace();

void mostrar_en_pantalla_el_estado_del_enlace(const bool conectado);

#endif