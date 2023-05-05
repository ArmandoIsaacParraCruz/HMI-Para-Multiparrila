#ifndef HMI_h
#define HMI_h
#include <Arduino.h>
#include <queue> 
#include "Pantalla.h"
#include "Teclado.h"
#include "Comunicacion_Inalambrica.h"

struct motor{  
    bool activado;                                      //Activa o desactiva un motor al inicio de la configuración de los motores.
    std::queue<double>minutosParaMantenerSetpoints;     //Almacena los minutos de duración de un setpoint que seguirá el PID del motor a configurar.
    std::queue<double>setpoints;                        //Almacena los setpoints que seguirá el PID del motor a configurar
};

/*struct platoCalefactor{  
    bool activado;                                      //Activa o desactiva un motor al inicio de la configuración de los motores.
    std::queue<double>minutosParaMantenerSetpoints;     //Almacena los minutos de duración de un setpoint que seguirá el PID del motor a configurar.
    std::queue<double>setpoints;                        //Almacena los setpoints que seguirá el PID del motor a configurar
};*/


extern motor motores[6];  //Se crea un arreglo de 6 plazas llamado multiHeaterStirrer

void inicializaPlatosYMotores();
void inicializaHMI();
uint8_t menuPrincipal();
void configAgitacionCalentamiento();
void configuracionIndividual();

void configuracionGrupal();
void activarDesactivarSensorInfrarrojo();
void configurarFuncTemperatura();

void monitorearMultiparrilla();
void menuEstadoDelEnlace();
#endif