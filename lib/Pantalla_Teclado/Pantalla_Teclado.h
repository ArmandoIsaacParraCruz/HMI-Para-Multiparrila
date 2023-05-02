#ifndef Pantalla_Teclado_h
#define Pantalla_Teclado_h
#include <Arduino.h>
#include <TFT_eSPI.h>   //Librería para el controlador ST7789 de la pantalla tft 2.4"
#include <SPI.h>        //Librería de comunicación SPI
#include <queue> 
#include <Keypad.h>
#include "Free_Fonts.h" //Librería para obtener fuentes de letras para la interfaz
#include "Logo_UAM.h"   //Se incluye la matriz que contiene la imagen del logo de la UAM
#include "My_Colors.h"  //Se incluye los colores personalizados para la pantalla tft
/////////////CONEXIONES Y CREACIÓN DEL OBJETO KEYPAD PARA EL TECLADO 4X4////////////////////////
#define FILAS  4 
#define COLUMNAS 4 
extern char caracteres[FILAS][COLUMNAS];
extern byte pinesFilas[FILAS];
extern byte pinesColumnas[COLUMNAS];
extern Keypad teclado;
extern TFT_eSPI pantalla;


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

void inicializaPlatosYMotores(void);
void configuraPantalla(void);
void muestraLogoUAM(void);
void inicializaHMI(void);
void colocaElementosEstaticosMenuPrincipal();
void resaltaOpcionMenuPrincipal(uint8_t );
void escribeTextoOpciones();
uint8_t menuPrincipal();




#endif