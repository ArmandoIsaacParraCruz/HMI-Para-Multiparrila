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

char obtener_tecla_presionada(char * teclas_validas, uint8_t numero_de_teclas_validas) 
{
	char tecla_presionada = NO_KEY;
 	while(tecla_presionada == NO_KEY) {
    	tecla_presionada = teclado.getKey();
    	for (uint8_t i = 0; i < numero_de_teclas_validas; ++i) {
			if(tecla_presionada == teclas_validas[i]) {
				return tecla_presionada;
			}
        }
		tecla_presionada = NO_KEY;
	}
	return tecla_presionada;
}
