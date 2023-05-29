#ifndef Teclado_h
#define Teclado_h
#include <Keypad.h>
#include <Arduino.h>
#define FILAS  4 
#define COLUMNAS 4 
extern char caracteres[FILAS][COLUMNAS];
extern byte pinesFilas[FILAS];
extern byte pinesColumnas[COLUMNAS];
extern Keypad teclado;

char obtener_tecla_presionada(char * teclas_validas, uint8_t numero_de_teclas_validas);
#endif