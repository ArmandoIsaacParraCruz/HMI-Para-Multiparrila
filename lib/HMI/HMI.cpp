#include "HMI.h"

Multiparrilla multiparrilla;
uint8_t no_de_funcion;

void inicializar_datos_de_plazas(){
	for(uint8_t i = 0; i < CANTIDAD_MAXIMA_DE_RUTINAS * 2; ++i) {
		if(i < CANTIDAD_DE_PLAZAS) {
			multiparrilla.plazas_activadas[i] = false;
		}
		if(i  < CANTIDAD_MAXIMA_DE_RUTINAS) {
			multiparrilla.setpoints_agitacion[i] = DESACTIVADO;
			multiparrilla.minutos_para_mantener_setpoints[i] = DESACTIVADO;
			multiparrilla.tipo_de_funcion_de_temperatura[i] = 'c';
		}
		multiparrilla.setpoints_temperatura[i] = DESACTIVADO;
	}
	multiparrilla.sensor_infrarrojo = false;
	multiparrilla.numero_de_rutinas_configuradas = 0;
	no_de_funcion = 0;
}


void inicializar_HMI()
{
	inicializar_comunicacion_con_multiparrilla();
  	inicializar_pantalla();
  	mostrar_logo_UAM();
}



void menu_principal(){
  
	uint8_t opcion = 1;
  	char caracter = NO_KEY;

  	colocar_elementos_de_fondo_del_menu_principal();

  	while(true) {
		
  		resaltar_opcion_en_posicion_actual_del_menu_principal(opcion);
    	mostrar_opciones_del_menu_principal();
    	while(caracter == NO_KEY) {
      		caracter = teclado.getKey();
      		if(caracter != 'C' && caracter != 'D' && caracter != 'A') {
				caracter = NO_KEY;
			}
    	}
		Serial.print("caracter ");Serial.println(caracter);
		

		if(caracter == 'A'){
			if(opcion == 1) {
        		configurar_agitacion_y_calentamiento();
				break;
    		} else if(opcion == 2) {
        		monitorear_agitacion_y_temperatura();
				break;
    		} else if(opcion == 3) {
        		mostrar_el_estado_del_enlace();
				break;
			}  
		} else if(caracter == 'D'){
    		opcion++;
		} else if(caracter == 'C') {
			opcion--;
		}
    

    	if(opcion > 3) {
      		opcion = 1; 
		} else if(opcion < 1) {
      		opcion = 3;
		}
		
		caracter = NO_KEY;
  }
 
}

void configurar_agitacion_y_calentamiento()
{
	char caracter = NO_KEY;
	bool conectado = obtener_estado_del_enlace();
	uint32_t tiempo_actual = millis();
	if(!conectado) {
		mostrar_que_la_multiparrilla_no_esta_conectada_en_el_menu_configurar_agitacion_y_calentamiento();
		while(caracter == NO_KEY){
    		caracter = teclado.getKey();
			if(caracter == 'C'){
				break;
			} else if(caracter == 'B') {
				menu_principal();
				return;
			} else {
				caracter = NO_KEY;
			}

			if(millis() - tiempo_actual >= 500) {
				tiempo_actual = millis();
				conectado = obtener_estado_del_enlace();
				if(conectado){
					mostrar_que_se_ha_restablecido_la_conexion_en_el_menu_configurar_agitacion_y_calentamiento();
					delay(3000);
					break;
				}
			}
		}
    }
	inicializar_datos_de_plazas();
	activar_o_desactivar_plazas();
}

void activar_o_desactivar_plazas()
{
	uint8_t i = 0; 
	char caracter = NO_KEY;
	bool plazas_activadas[CANTIDAD_DE_PLAZAS];

	for(uint8_t i = 0; i < CANTIDAD_DE_PLAZAS; ++i) {
		plazas_activadas[i] = multiparrilla.plazas_activadas[i];
	}

	colocar_elementos_de_fondo_del_menu_activar_o_desactivar_plazas(plazas_activadas, CANTIDAD_DE_PLAZAS);

	while( i >= 0 && i < CANTIDAD_DE_PLAZAS) {
		resaltar_opcion_en_posicion_actual_del_menu_activar_o_desactivar_plazas(plazas_activadas, i, CANTIDAD_DE_PLAZAS);
		
    	
		while(caracter == NO_KEY) {
      		caracter = teclado.getKey();
      		if(caracter != 'C' && caracter != 'D' && caracter != 'A' && caracter != 'B')
        		caracter = NO_KEY;
    	}

		if(caracter == 'A') {
			if(multiparrilla.plazas_activadas[i]) {
				multiparrilla.plazas_activadas[i] = false;
				plazas_activadas[i] = false;
			}else {
				multiparrilla.plazas_activadas[i] = true;
				plazas_activadas[i] = true;
			}
		}

		else if(caracter == 'B'){
			menu_principal();					
			return;
		}

    	else if(caracter == 'C') {
			break;
		}

		else if(caracter == 'D') {
			i++;
			if(i >= CANTIDAD_DE_PLAZAS) {
				i = 0;
			}
		}

		caracter = NO_KEY;
	}

	bool configuracionValida = validar_que_por_lo_menos_haya_una_plaza_activada();
	if(configuracionValida)
		elegir_sensor_de_temperatura();
	else{
		desplegar_mensaje_de_que_no_se_ha_activado_ninguna_plaza();
		caracter = NO_KEY;
    	while(caracter == NO_KEY) {
    		caracter = teclado.getKey();
  			if(caracter != 'B'){
				caracter = NO_KEY;
			}
    	}
		activar_o_desactivar_plazas();
	}	
}

bool validar_que_por_lo_menos_haya_una_plaza_activada()
{
	for(uint8_t i = 0; i < CANTIDAD_DE_PLAZAS; ++i) {
		if(multiparrilla.plazas_activadas[i])
			return true;		
	}
	return false;
}

void elegir_sensor_de_temperatura()
{
	uint8_t opcion = 1; 
	char caracter = NO_KEY;

	colocar_elementos_de_fondo_del_menu_elegir_sensor_de_temperatura(multiparrilla.plazas_activadas, CANTIDAD_DE_PLAZAS);

	while(true) {
		resaltar_opcion_en_posicion_actual_del_menu_elegir_sensor_de_temperatura(opcion);
    	mostrar_opciones_del_menu_elegir_sensor_de_temperatura(multiparrilla.sensor_infrarrojo);

		
    	while(caracter == NO_KEY) {
      		caracter = teclado.getKey();
      		if(caracter != 'C' && caracter != 'D' && caracter != 'A' && caracter != 'B')
        		caracter = NO_KEY;
    	}
    
    	if(caracter == 'C') {
			configurar_rutina_de_calentamiento_y_agitacion();
			break;
		} else if(caracter == 'D') {
			opcion++;
		} else if(caracter == 'A'){
			if(opcion == 1) {
				multiparrilla.sensor_infrarrojo = true;
			} else {
				multiparrilla.sensor_infrarrojo = false;
			}
		} else if(caracter == 'B') {
			activar_o_desactivar_plazas();
    		break;
		}

    	if(opcion > 2) {
			opcion = 1; 
		}	

		caracter = NO_KEY; 
    }
}

/*
struct Multiparrilla {
    bool sensor_infrarrojo; 
    bool plazas_activadas[CANTIDAD_DE_PLAZAS];
    uint16_t setpoints_temperatura[CANTIDAD_MAXIMA_DE_FUNCIONES*2];
    char tipo_de_funcion_de_temperatura[CANTIDAD_MAXIMA_DE_FUNCIONES];
    uint16_t setpoints_agitacion[CANTIDAD_MAXIMA_DE_FUNCIONES]; 
    uint32_t minutos_para_mantener_setpoints[CANTIDAD_MAXIMA_DE_FUNCIONES];
};*/

void configurar_rutina_de_calentamiento_y_agitacion()
{
	uint8_t numero_de_rutina = 0, posicion_del_cursor = 0;
	char caracter = NO_KEY;

	colocar_elementos_de_fondo_del_menu_configurar_rutina_de_calentamiento_y_agitacion(multiparrilla.plazas_activadas, CANTIDAD_DE_PLAZAS);
	
	while(numero_de_rutina < CANTIDAD_MAXIMA_DE_RUTINAS) {
		//Serial.println(multiparrilla.tipo_de_funcion_de_temperatura[numero_de_rutina]);
		
		mostrar_numero_de_rutina_y_posicion_del_cursor(numero_de_rutina, posicion_del_cursor, multiparrilla.tipo_de_funcion_de_temperatura[numero_de_rutina]);

		if(posicion_del_cursor == 0) {
			caracter  = elegir_funcion_de_calentamiento(numero_de_rutina);
		} else if(posicion_del_cursor == 1) {
			caracter = establecer_primer_setpoint_de_temperatura(numero_de_rutina);
		} else if(posicion_del_cursor == 2) {
			if(multiparrilla.tipo_de_funcion_de_temperatura[numero_de_rutina] == 'c') {
				posicion_del_cursor = 3;
				continue;
			} else {
				caracter = establecer_segundo_setpoint_de_temperatura(numero_de_rutina);
			}
		} else if(posicion_del_cursor == 3) {
			caracter = establecer_setpoint_de_agitacion(numero_de_rutina);
		} else if(posicion_del_cursor == 4) {
			caracter = establecer_minutos_para_mantener_setpoints(numero_de_rutina);
		}


		if(caracter == 'B'){
			if(numero_de_rutina == 0) {
				elegir_sensor_de_temperatura();
				return;
			} else {
				numero_de_rutina -=1;
				posicion_del_cursor = 0;
				continue;
			}
			return;
		} else if(caracter == 'C') {
			if(verificar_si_la_rutina_ha_sido_correctamente_configurada(numero_de_rutina)) {
				posicion_del_cursor = 0; 
				if(numero_de_rutina == multiparrilla.numero_de_rutinas_configuradas) {
					uint8_t opc = agregar_o_confirmar_rutinas_configuradas();
					if(opc == 0) {
						if(numero_de_rutina < CANTIDAD_MAXIMA_DE_RUTINAS - 1) {				
							numero_de_rutina++;
							multiparrilla.numero_de_rutinas_configuradas++;
						}
						continue;
					} else if(opc == 1) {
						bool enviar_rutinas = confirmar_y_enviar_rutinas_configuradas();
						if(enviar_rutinas) {
							return;
						} else {
							continue;
						}
					} else if(opc == 2) {
						eliminar_rutina(numero_de_rutina);
						multiparrilla.numero_de_rutinas_configuradas--;
						numero_de_rutina--;
						continue;
					} else {
						continue;
					}
				} else {
					numero_de_rutina++;
				}
				
			} else {
				continue;
			}
		} else if(caracter == 'D') {
			posicion_del_cursor++;
			if(posicion_del_cursor > 4) {
				posicion_del_cursor = 0;
			}
		}
		caracter = NO_KEY;
	}
}

char elegir_funcion_de_calentamiento(const uint8_t numero_de_rutina)
{
	char caracter = NO_KEY;
	colocar_elementos_de_la_opcion_elegir_funcion_de_calentamiento(multiparrilla.setpoints_temperatura[numero_de_rutina*2], multiparrilla.setpoints_temperatura[numero_de_rutina * 2 + 1], multiparrilla.tipo_de_funcion_de_temperatura[numero_de_rutina],
										 multiparrilla.setpoints_agitacion[numero_de_rutina], multiparrilla.minutos_para_mantener_setpoints[numero_de_rutina]);
	while(true) {
		caracter = teclado.getKey();
		if(caracter == 'D' || caracter == 'C' || caracter == 'B') {
			break;
		} else if (caracter == 'A') {
			if(multiparrilla.tipo_de_funcion_de_temperatura[numero_de_rutina] != 'r') {
				multiparrilla.tipo_de_funcion_de_temperatura[numero_de_rutina] = 'r';
			} else {
				multiparrilla.tipo_de_funcion_de_temperatura[numero_de_rutina] = 'c';
			}
			colocar_elementos_de_la_opcion_elegir_funcion_de_calentamiento(multiparrilla.setpoints_temperatura[numero_de_rutina*2], multiparrilla.setpoints_temperatura[numero_de_rutina * 2 + 1], multiparrilla.tipo_de_funcion_de_temperatura[numero_de_rutina],
										 multiparrilla.setpoints_agitacion[numero_de_rutina], multiparrilla.minutos_para_mantener_setpoints[numero_de_rutina]);
		}
	}
	return caracter;
}

char establecer_primer_setpoint_de_temperatura(const uint8_t numero_de_rutina)
{
	char caracter = NO_KEY;
	String valor_de_temperatura_en_texto = "0";
	while(true) {
		caracter = teclado.getKey();
		if(caracter == 'D' || caracter == 'C' || caracter == 'B') {
			break;
		} else if(isdigit(caracter) || caracter == 'A') {
			if(caracter == 'A') {
				valor_de_temperatura_en_texto = "0";
			} else {
				valor_de_temperatura_en_texto += caracter;
				if(valor_de_temperatura_en_texto.toInt() > 999) {
					valor_de_temperatura_en_texto = caracter;
				}
			}
			multiparrilla.setpoints_temperatura[numero_de_rutina * 2] = valor_de_temperatura_en_texto.toInt();
			coloca_valor_de_temperatura_en_la_opcion_establecer_primer_setpoint_de_temperatura(valor_de_temperatura_en_texto, multiparrilla.tipo_de_funcion_de_temperatura[numero_de_rutina]);
		}
	}
	return caracter;
}

char establecer_segundo_setpoint_de_temperatura(const uint8_t numero_de_rutina)
{
	char caracter = NO_KEY;
	String valor_de_temperatura_en_texto = "0";
	while(true) {
		caracter = teclado.getKey();
		if(caracter == 'D' || caracter == 'C' || caracter == 'B') {
			break;
		} else if(isdigit(caracter) || caracter == 'A') {
			if(caracter == 'A') {
				valor_de_temperatura_en_texto = "0";
			} else {
				valor_de_temperatura_en_texto += caracter;
				if(valor_de_temperatura_en_texto.toInt() > 999) {
					valor_de_temperatura_en_texto = caracter;
				}
			}
			multiparrilla.setpoints_temperatura[numero_de_rutina * 2 + 1] = valor_de_temperatura_en_texto.toInt();
			coloca_valor_de_temperatura_en_la_opcion_establecer_segundo_setpoint_de_temperatura(valor_de_temperatura_en_texto, multiparrilla.setpoints_temperatura[numero_de_rutina * 2]);
		}
	}
	return caracter;
}



char establecer_setpoint_de_agitacion(const uint8_t numero_de_rutina)
{
	char caracter = NO_KEY;
	String valor_de_agitacion_en_texto = "0";
	while(true) {
		caracter = teclado.getKey();
		if(caracter == 'D' || caracter == 'C' || caracter == 'B') {
			break;
		} else if(isdigit(caracter) || caracter == 'A') {
			if(caracter == 'A') {
				valor_de_agitacion_en_texto = "0";
			} else {
				valor_de_agitacion_en_texto += caracter;
				if(valor_de_agitacion_en_texto.toInt() > 9999) {
					valor_de_agitacion_en_texto = caracter;
				}
			}
			multiparrilla.setpoints_agitacion[numero_de_rutina] = valor_de_agitacion_en_texto.toInt();
			coloca_valor_de_agitacion_en_la_opcion_establecer_setpoint_de_agitacion(valor_de_agitacion_en_texto, multiparrilla.tipo_de_funcion_de_temperatura[numero_de_rutina]);
		}
	}
	return caracter;

}

char establecer_minutos_para_mantener_setpoints(const uint8_t numero_de_rutina)
{
    char caracter = NO_KEY;
	String valor_de_tiempo_en_texto = "0";
	while(true) {
		caracter = teclado.getKey();
		if(caracter == 'D' || caracter == 'C' || caracter == 'B') {
			break;
		} else if(isdigit(caracter) || caracter == 'A') {
			if(caracter == 'A') {
				valor_de_tiempo_en_texto = "0";
			} else {
				valor_de_tiempo_en_texto += caracter;
				if(valor_de_tiempo_en_texto.toInt() > 9999999) {
					valor_de_tiempo_en_texto = caracter;
				}
			}
			multiparrilla.minutos_para_mantener_setpoints[numero_de_rutina] = valor_de_tiempo_en_texto.toInt();
			coloca_valor_de_tiempo_en_la_opcion_establecer_minutos_para_mantener_setpoints(valor_de_tiempo_en_texto, multiparrilla.tipo_de_funcion_de_temperatura[numero_de_rutina]);
		}
	}
	return caracter;
}

bool verificar_si_la_rutina_ha_sido_correctamente_configurada(const uint8_t numero_de_rutina)
{
	if(multiparrilla.setpoints_temperatura[numero_de_rutina * 2] > 300) {
		return false;
	}
	if(multiparrilla.setpoints_agitacion[numero_de_rutina] > 1200) {
		return false;
	} 
	if(multiparrilla.minutos_para_mantener_setpoints[numero_de_rutina] <= 0) {
		return false;
	}

	if(multiparrilla.tipo_de_funcion_de_temperatura[numero_de_rutina] == 'c') {
		multiparrilla.setpoints_temperatura[numero_de_rutina * 2 + 1] = multiparrilla.setpoints_temperatura[numero_de_rutina * 2];
	} else {
		if(multiparrilla.setpoints_temperatura[numero_de_rutina * 2 + 1] <= 0 || multiparrilla.setpoints_temperatura[numero_de_rutina * 2 + 1] <= multiparrilla.setpoints_temperatura[numero_de_rutina * 2]) {
			return false;
		} 
	}
	
    return true;
}

uint8_t agregar_o_confirmar_rutinas_configuradas()
{
	char caracter = NO_KEY;
	uint8_t opcion = 0;
	colocar_elementos_de_fondo_del_menu_agregar_o_confirmar_rutinas_configuradas();
	while(true) {
		resalta_opcion_en_posicion_actual_del_menu_agregar_o_confirmar_rutinas_configuradas(opcion);
		while(caracter == NO_KEY) {
			caracter = teclado.getKey();
			if(caracter != 'A' && caracter != 'B' && caracter != 'D') {
				caracter = NO_KEY;
			}
		}
		if(caracter == 'A') {
			break;
		} else if(caracter == 'B'){
			return 3;
		} else if(caracter == 'D') {
			opcion++;
			if(opcion >= 3) {
				opcion = 0;
			}
		}
		caracter = NO_KEY;
	}
    return opcion;
}

void eliminar_rutina(const uint8_t numero_de_rutina)
{
	multiparrilla.setpoints_agitacion[numero_de_rutina] = DESACTIVADO;
	multiparrilla.minutos_para_mantener_setpoints[numero_de_rutina] = DESACTIVADO;
	multiparrilla.tipo_de_funcion_de_temperatura[numero_de_rutina] = 'c';
	multiparrilla.setpoints_temperatura[numero_de_rutina * 2] = DESACTIVADO;
	multiparrilla.setpoints_temperatura[numero_de_rutina * 2 + 1] = DESACTIVADO;
}

bool confirmar_y_enviar_rutinas_configuradas()
{
	char caracter = NO_KEY;
	colocar_elementos_de_fondo_en_el_menu_confirmar_y_enviar_rutinas_configuradas();
	uint8_t configuracion = 0;
	//Serial.println("Numero de rutunas config. :" + (String)(multiparrilla.numero_de_rutinas_configuradas));
	while(configuracion <= multiparrilla.numero_de_rutinas_configuradas + 1) {
		if(configuracion == 0) {
			muestra_plazas_activadas_y_sensor_configurado(multiparrilla.plazas_activadas, CANTIDAD_DE_PLAZAS, multiparrilla.sensor_infrarrojo, multiparrilla.numero_de_rutinas_configuradas);
		} else {
			muestra_configuracion_de_la_rutina(configuracion, multiparrilla.numero_de_rutinas_configuradas + 1, multiparrilla.tipo_de_funcion_de_temperatura[configuracion -1], multiparrilla.setpoints_temperatura[(configuracion - 1) * 2],
											   multiparrilla.setpoints_temperatura[(configuracion - 1) * 2 + 1], multiparrilla.setpoints_agitacion[configuracion - 1], multiparrilla.minutos_para_mantener_setpoints[configuracion - 1]);
		}

		while(caracter == NO_KEY) {
			caracter = teclado.getKey();
			if(caracter != 'B' && caracter != 'C') {
				caracter = NO_KEY;
			} 
		}

		if(caracter == 'B') {
			if(configuracion <= 0) {
				return false;
			} else {
				configuracion--;
			}
		} else if(caracter == 'C') {
			if(configuracion >= multiparrilla.numero_de_rutinas_configuradas + 1) {
				Serial.println("Final");
			}
			configuracion++;
		}	
		caracter = NO_KEY;
	}
	return true;
}



void menu_resumen_de_las_rutinas_configuradas()
{
}

void monitorear_agitacion_y_temperatura()
{

}

void mostrar_el_estado_del_enlace()
{
	char caracter = NO_KEY;
	bool conectado = obtener_estado_del_enlace();
	colocar_elementos_de_fondo_del_menu_mostrar_el_estado_del_enlace();
	mostrar_en_pantalla_el_estado_del_enlace(conectado);
	while(caracter == NO_KEY){
    	caracter = teclado.getKey();
		if(caracter == 'A'){
			conectado = obtener_estado_del_enlace();
			mostrar_en_pantalla_el_estado_del_enlace(conectado);
			caracter = NO_KEY;
		}
		else if(caracter != 'B')
        	caracter = NO_KEY;
    }
}


