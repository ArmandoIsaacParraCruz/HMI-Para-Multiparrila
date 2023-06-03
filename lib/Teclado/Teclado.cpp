#include "Teclado.h"

Keypad teclado = Keypad( makeKeymap(caracteres), pinesFilas, pinesColumnas, FILAS, COLUMNAS); 

char caracteres[FILAS][COLUMNAS] = {
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};

byte pinesFilas[FILAS] = {4, 13, 14, 27}; 
byte pinesColumnas[COLUMNAS] = {26, 25, 33, 32};


