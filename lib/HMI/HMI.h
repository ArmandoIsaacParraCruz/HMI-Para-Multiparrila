#ifndef HMI_h
#define HMI_h
#include <Arduino.h>
#include <string>
#include <queue> 
#include <ctype.h>
#include "Pantalla.h"
#include "Teclado.h"
#include "ComunicacionConMultiparrilla.h"

#define CANT_PLAZAS 6

extern bool sensorInfrarrojo; 

struct Motor{  
    bool activado;                                      //Activa o desactiva un motor al inicio de la configuración de los motores.
    std::queue<double>setpoints;                        //Almacena los setpoints que seguirá el PID del motor a configurar
};

struct PlatoCalefactor{  
    bool activado;                                     //Activa o desactiva un motor al inicio de la configuración de los motores.
    std::queue<double>setpoints;                        //Almacena los setpoints que seguirá el PID del motor a configurar
};

struct Plaza{
    bool activado;
    Motor motor;
    PlatoCalefactor platoCalefactor;
    std::queue<double> minutosParaMantenerSetpoint; 
};

extern Plaza plazas[6];

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
void monitorear_agitacion_y_temperatura();
void mostrar_el_estado_del_enlace();
#endif