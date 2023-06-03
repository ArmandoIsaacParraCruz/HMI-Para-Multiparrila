#ifndef HMI_h
#define HMI_h
#include <Arduino.h>
#include <ctype.h>
#include <cstdint>
#include "Pantalla.h"
#include "Teclado.h"
#include "ComunicacionConMultiparrilla.h"

#define DESACTIVADO 0

extern Multiparrilla multiparrilla;

extern uint8_t no_de_funcion;

void inicializar_datos_de_plazas();

void inicializar_HMI();

void menu_principal();

void configurar_agitacion_y_calentamiento();

void activar_o_desactivar_plazas();

bool validar_que_por_lo_menos_haya_una_plaza_activada();

void elegir_sensor_de_temperatura();

void configurar_rutina_de_calentamiento_y_agitacion();

char elegir_funcion_de_calentamiento(const uint8_t numero_de_rutina);

char establecer_primer_setpoint_de_temperatura(const uint8_t numero_de_rutina);

char establecer_segundo_setpoint_de_temperatura(const uint8_t numero_de_rutina);

char establecer_setpoint_de_agitacion(const uint8_t numero_de_rutina); 

char establecer_minutos_para_mantener_setpoints(const uint8_t numero_de_rutina);

bool verificar_si_la_rutina_ha_sido_correctamente_configurada(const uint8_t numero_de_rutina);

uint8_t agregar_o_confirmar_rutinas_configuradas();

void eliminar_rutina(const uint8_t numero_de_rutina);

void confirmar_y_enviar_rutinas_configuradas();

void menu_resumen_de_las_rutinas_configuradas();

void monitorear_agitacion_y_temperatura();

void mostrar_el_estado_del_enlace();
#endif