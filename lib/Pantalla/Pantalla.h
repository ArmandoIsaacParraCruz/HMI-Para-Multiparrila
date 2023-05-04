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

void configuraPantalla();
void muestraLogoUAM();
void colocaElementosEstaticosMenuPrincipal();
void escribeTextoOpcionesMenuPrincipal();
void resaltaOpcionMenuPrincipal(uint8_t );
void muestraMenuOpcionElegida(uint8_t);
void colocaElementosEstaticosMenuConfigAgitacionCalentamiento();
void muestraImagenMultiparrilla();
void colocaElementosEstaticosMenuEstadoDelEncale();
void muestraEstadoDelEnlace(bool);

#endif