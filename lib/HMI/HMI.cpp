#include "HMI.h"

Multiparrilla multiparrilla;
uint8_t no_de_funcion;

void inicializar_datos_de_plazas(){
	uint8_t limite = CANTIDAD_MAXIMA_DE_FUNCIONES * 2;
	for(uint8_t i = 0; i < limite; ++i) {
		if(i < CANTIDAD_DE_PLAZAS) {
			multiparrilla.plazas_activadas[i] = false;
		}
		if(i  < CANTIDAD_MAXIMA_DE_FUNCIONES) {
			multiparrilla.setpoints_agitacion[i] = DESACTIVADO;
			multiparrilla.minutos_para_mantener_setpoints[i] = DESACTIVADO;
			multiparrilla.tipo_de_funcion_de_temperatura[i] = '-';
		}
		multiparrilla.setpoints_temperatura[i] = DESACTIVADO;
   		
	}
	no_de_funcion = DESACTIVADO;
}


void inicializar_HMI()
{
	inicializar_comunicacion_con_multiparrilla();
  	inicializar_pantalla();
  	mostrar_logo_UAM();
}



uint8_t menu_principal(){
  
	uint8_t opcion = 1;
  	char caracter = NO_KEY;

  	colocar_elementos_de_fondo_del_menu_principal();

  	while(true) {
  		resaltar_opcion_en_posicion_actual_del_menu_principal(opcion);
    	mostrar_opciones_del_menu_principal();
    
    	caracter = NO_KEY;
    	while(caracter == NO_KEY) {
      		caracter = teclado.getKey();
      		if(caracter != 'C' && caracter != 'D' && caracter != 'A')
        		caracter = NO_KEY;
    	}
    
    	if(caracter == 'C')
      		opcion--;
    	else if(caracter == 'D')
    		opcion++;
    	else if(caracter == 'A')
    		break;
    

    	if(opcion > 3)
      		opcion = 1;  
    	else if(opcion < 1)
      		opcion = 3;
  }
  return opcion;  
}

void configurar_agitacion_y_calentamiento()
{
	inicializar_datos_de_plazas();
	uint8_t opcion = 1; char caracter = NO_KEY;

	colocar_elementos_de_fondo_del_menu_configurar_agitacion_y_calentamiento();
	
	while(true) {
		resaltar_opcion_en_posicion_actual_del_menu_configurar_agitacion_y_calentamiento(opcion);
    	mostrar_opciones_del_menu_configurar_agitacion_y_calentamiento();

		caracter = NO_KEY;
    	while(caracter == NO_KEY) {
      		caracter = teclado.getKey();
      		if(caracter != 'C' && caracter != 'D' && caracter != 'A' && caracter != 'B')
        		caracter = NO_KEY;
    	}
    
    	if(caracter == 'C')
      		opcion--;
    	else if(caracter == 'D')
    		opcion++;
		else if(caracter == 'A'){
			if(opcion == 1)
				activar_o_desactivar_plazas();
				//configuracionIndividual();
			return;
		}
    	else if(caracter == 'B')
    		break;
    

    	if(opcion > 2)
      		opcion = 1;  
    	else if(opcion < 1)
      		opcion = 2;
    }
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
		caracter = NO_KEY;
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
			configurar_agitacion_y_calentamiento();					
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
	}

	bool configuracionValida = validar_que_por_lo_menos_haya_una_plaza_activada();
	if(configuracionValida)
		elegir_sensor_de_temperatura();
	else{
		desplegar_mensaje_de_que_no_se_ha_activado_ninguna_plaza();
		caracter = NO_KEY;
    	while(caracter == NO_KEY) {
    		caracter = teclado.getKey();
  			if(caracter != 'C')
    			caracter = NO_KEY;
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

	colocar_elementos_de_fondo_del_menu_elegir_sensor_de_temperatura();

	while(true) {
		resaltar_opcion_en_posicion_actual_del_menu_elegir_sensor_de_temperatura(opcion);
    	mostrar_opciones_del_menu_elegir_sensor_de_temperatura(multiparrilla.sensor_infrarrojo);

		caracter = NO_KEY;
    	while(caracter == NO_KEY) {
      		caracter = teclado.getKey();
      		if(caracter != 'C' && caracter != 'D' && caracter != 'A' && caracter != 'B')
        		caracter = NO_KEY;
    	}
    
    	if(caracter == 'C') {
			elegir_funcion_de_calentamiento();
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
    }
}

void elegir_funcion_de_calentamiento()
{
	no_de_funcion++;
	if(no_de_funcion < CANTIDAD_MAXIMA_DE_FUNCIONES) {
		char caracter = NO_KEY; 
		uint8_t opcion = 1; 
		colocar_elementos_de_fondo_del_menu_elegir_funcion_de_calentamiento();
		while(true) {
    		mostrar_opciones_del_menu_elegir_funcion_de_calentamiento(opcion);
			caracter = NO_KEY;
    		while(caracter == NO_KEY) {
      			caracter = teclado.getKey();
      			if(caracter != 'C' && caracter != 'D' && caracter != 'A' && caracter != 'B')
        			caracter = NO_KEY;
    		}
    
    		if(caracter == 'C') {
   		   		opcion--;
			} else if(caracter == 'D') {
    			opcion++;
			} else if(caracter == 'A'){
				if(opcion == 1) {
					establecer_setpoint_para_un_calentamiento_constante();
				} else if(opcion == 2){
					establecer_setpoints_para_una_rampa_de_temperatura();
				}
				break;
			} else if(caracter == 'B'){
				elegir_sensor_de_temperatura();
				break;
			}
    		
    		if(opcion > 2) {
				opcion = 1;
			} else if(opcion < 1) {
				opcion = 2;
			}
    	}
	}
}

void establecer_setpoint_para_un_calentamiento_constante()
{
	char caracter = NO_KEY;
	String temperatura_en_texto = "0";
	colocar_elementos_de_fondo_del_menu_establecer_setpoint_para_un_calentamiento_constante();
	while(true) {
		coloca_valor_de_temperatura_en_el_menu_establecer_setpoint_para_un_calentamiento_constante(temperatura_en_texto.toInt());
		caracter = NO_KEY;
    	while(caracter == NO_KEY) {
      		caracter = teclado.getKey();
      		if(caracter == '*' || caracter == '#' || caracter == 'D')
        		caracter = NO_KEY;
    	}

		if(isdigit(caracter)) {
			temperatura_en_texto += caracter;
			if(temperatura_en_texto.toInt() > 999) {
				temperatura_en_texto = caracter;
			}
		}


    	if(caracter == 'A') {
			if(temperatura_en_texto.toInt() <= 300) {
				if(temperatura_en_texto.toInt() == 0) {
					multiparrilla.tipo_de_funcion_de_temperatura[no_de_funcion] = 'd';
				} else {
					multiparrilla.tipo_de_funcion_de_temperatura[no_de_funcion] = 'c';
				}
				multiparrilla.setpoints_temperatura[no_de_funcion * 2] = temperatura_en_texto.toInt();
				multiparrilla.setpoints_temperatura[no_de_funcion * 2 + 1] = temperatura_en_texto.toInt();
				establecer_setpoint_de_agitacion(false);
				break;
			}
		} else if(caracter == 'B') { 
			multiparrilla.tipo_de_funcion_de_temperatura[no_de_funcion] = '-';
			multiparrilla.setpoints_temperatura[no_de_funcion * 2] = DESACTIVADO;
			multiparrilla.setpoints_temperatura[no_de_funcion * 2 + 1] = DESACTIVADO;
			elegir_funcion_de_calentamiento();
			break;
		} else if(caracter == 'C') {
			temperatura_en_texto = "0";
		}
    }
}

void establecer_setpoints_para_una_rampa_de_temperatura()
{
	char caracter = NO_KEY;
	String temperatura_inicial_en_texto = "0", temperatura_final_en_texto = "0";
	colocar_elementos_de_fondo_del_menu_establecer_setpoint_para_un_calentamiento_en_rampa_inicial();
	while(true) {
		coloca_valor_de_temperatura_en_el_menu_establecer_setpoint_para_un_calentamiento_en_rampa_inicial(temperatura_inicial_en_texto.toInt());
		caracter = NO_KEY;
    	while(caracter == NO_KEY) {
      		caracter = teclado.getKey();
      		if(caracter == '*' || caracter == '#' || caracter == 'D')
        		caracter = NO_KEY;
    	}

		if(isdigit(caracter)) {
			temperatura_inicial_en_texto += caracter;
			if(temperatura_inicial_en_texto.toInt() > 999) {
				temperatura_inicial_en_texto = caracter;
			}
		}


    	if(caracter == 'A') {
			if(temperatura_inicial_en_texto.toInt() <= 300 && temperatura_inicial_en_texto.toInt() > 0) {
				multiparrilla.setpoints_temperatura[no_de_funcion * 2] = temperatura_inicial_en_texto.toInt();
				multiparrilla.tipo_de_funcion_de_temperatura[no_de_funcion] = 'r';
				break;
			}
		} else if(caracter == 'B') { 
			multiparrilla.setpoints_temperatura[no_de_funcion * 2] = DESACTIVADO;
			multiparrilla.tipo_de_funcion_de_temperatura[no_de_funcion] = '-';
			elegir_funcion_de_calentamiento();
			break;
		} else if(caracter == 'C') {
			temperatura_inicial_en_texto = "0";
		}
    }

	colocar_elementos_de_fondo_del_menu_establecer_setpoint_para_un_calentamiento_en_rampa_final();
	while(true) {
		colocar_valor_de_temperatura_en_el_menu_establecer_setpoint_para_un_calentamiento_en_rampa_final(temperatura_final_en_texto.toInt());
		caracter = NO_KEY;
    	while(caracter == NO_KEY) {
      		caracter = teclado.getKey();
      		if(caracter == '*' || caracter == '#' || caracter == 'D')
        		caracter = NO_KEY;
    	}

		if(isdigit(caracter)) {
			temperatura_final_en_texto += caracter;
			if(temperatura_final_en_texto.toInt() > 999) {
				temperatura_final_en_texto = caracter;
			}
		}

    	if(caracter == 'A' && temperatura_final_en_texto.toInt() <= 300 && temperatura_final_en_texto.toInt() > temperatura_inicial_en_texto.toInt()) {
			multiparrilla.setpoints_temperatura[no_de_funcion * 2 + 1] = temperatura_final_en_texto.toInt();
			establecer_setpoint_de_agitacion(true);
			break;
		} else if(caracter == 'B') {
			multiparrilla.setpoints_temperatura[no_de_funcion * 2 + 1] = DESACTIVADO;
			establecer_setpoints_para_una_rampa_de_temperatura();
			break;
		} else if(caracter == 'C') {
			temperatura_final_en_texto = "0";
		}
    }
}

void establecer_setpoint_de_agitacion(const bool funcion_de_temperatura)
{
	char caracter = NO_KEY;
	String rpm_en_texto = "0";
	colocar_elementos_de_fondo_del_menu_establecer_setpoint_de_agitacion(funcion_de_temperatura);
	while(true) {
		colocar_valor_de_rpm_en_el_menu_establecer_setpoint_de_agitacion(rpm_en_texto.toInt(),funcion_de_temperatura);
		caracter = NO_KEY;
    	while(caracter == NO_KEY) {
      		caracter = teclado.getKey();
      		if(caracter == '*' || caracter == '#' || caracter == 'D')
        		caracter = NO_KEY;
    	}

		if(isdigit(caracter)) {
			rpm_en_texto += caracter;
			if(rpm_en_texto.toInt() > 9999) {
				rpm_en_texto = caracter;
			}
		}

    	if(caracter == 'A') {
			if(rpm_en_texto.toInt() <= 1200) {
				multiparrilla.setpoints_agitacion[no_de_funcion] = rpm_en_texto.toInt();
				establecer_minutos_para_mantener_setpoints(funcion_de_temperatura);
				break;
			}
		} else if(caracter == 'B') { 
			multiparrilla.setpoints_agitacion[no_de_funcion] = DESACTIVADO;
			multiparrilla.setpoints_temperatura[no_de_funcion * 2 + 1] = DESACTIVADO;
			if(funcion_de_temperatura) {
				establecer_setpoints_para_una_rampa_de_temperatura();
			} else {
				establecer_setpoint_para_un_calentamiento_constante();
			}
			break;
		} else if(caracter == 'C') {
			rpm_en_texto = "0";
		}
    }

}

void establecer_minutos_para_mantener_setpoints(const bool funcion_de_temperatura)
{
	char caracter = NO_KEY;
	String minutos_en_texto = "0";
	colocar_elementos_de_fondo_del_menu_establecer_minutos_para_mantener_setpoints(funcion_de_temperatura);
	while(true) {
		colocar_valor_de_minutos_en_el_menu_estalecer_minutos_para_mantener_setpoints(minutos_en_texto.toInt(), funcion_de_temperatura);
		caracter = NO_KEY;
    	while(caracter == NO_KEY) {
      		caracter = teclado.getKey();
      		if(caracter == '*' || caracter == '#' || caracter == 'D')
        		caracter = NO_KEY;
    	}

		if(isdigit(caracter)) {
			minutos_en_texto += caracter;
			if(minutos_en_texto.toInt() > 99999) {
				minutos_en_texto = caracter;
			}
		}

    	if(caracter == 'A') {
			if(minutos_en_texto.toInt() > 0 && minutos_en_texto.toInt() <= 65000) {
				multiparrilla.minutos_para_mantener_setpoints[no_de_funcion] = minutos_en_texto.toInt();
				menu_agregar_o_cancelar_rutina(funcion_de_temperatura);
				break;
			}
		} else if(caracter == 'B') { 
			multiparrilla.minutos_para_mantener_setpoints[no_de_funcion] = DESACTIVADO;
			establecer_setpoint_de_agitacion(funcion_de_temperatura);
			break;
		} else if(caracter == 'C') {
			minutos_en_texto = "0";
		}
    }
}

void menu_agregar_o_cancelar_rutina(const bool funcion_de_temperatura)
{
	char caracter = NO_KEY;
	colocar_elementos_de_fondo_menu_agregar_o_cancelar_rutina();
	while(true) {
		caracter = NO_KEY;
    	while(caracter == NO_KEY){
      		caracter = teclado.getKey();
      		if(caracter != 'A' && caracter != 'B' && caracter != 'C' && caracter != 'D')
        		caracter = NO_KEY;
    	}

    	if(caracter == 'A') {
			menu_resumen_de_las_rutinas_configuradas();
			break;
		} else if(caracter == 'B') { 
			establecer_minutos_para_mantener_setpoints(funcion_de_temperatura);
			break;
		} else if(caracter == 'C') {
			multiparrilla.setpoints_temperatura[no_de_funcion * 2] = DESACTIVADO;
			multiparrilla.setpoints_temperatura[no_de_funcion * 2 + 1] = DESACTIVADO;
			multiparrilla.tipo_de_funcion_de_temperatura[no_de_funcion] = '-';
			multiparrilla.setpoints_agitacion[no_de_funcion] = DESACTIVADO;;
			multiparrilla.minutos_para_mantener_setpoints[no_de_funcion] = DESACTIVADO;;
			elegir_funcion_de_calentamiento();
			break;
		} else if(caracter == 'D') {
			elegir_funcion_de_calentamiento();
			break;
		}
    }
}

void menu_resumen_de_las_rutinas_configuradas()
{
	enviar_rutinas_configuradas();

}

void enviar_rutinas_configuradas()
{
	enviar_rutinas(multiparrilla);
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


