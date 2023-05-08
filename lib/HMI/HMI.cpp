#include "HMI.h"

Plaza plazas[CANT_PLAZAS];


void inicializar_plazas(){
	for(int i = 0; i < CANT_PLAZAS;i++){
   		plazas[i].activado = false;
		plazas[i].motor.activado = false;
		plazas[i].platoCalefactor.activado = false;
		plazas[i].sensorInfrarrojo = false;
	}  
}


void inicializar_HMI()
{
	inicializar_comunicacion_con_multiparrilla();
  	inicializar_plazas();
  	inicializar_pantalla();
  	mostrar_logo_UAM();
}



uint8_t menu_principal(){
  
	uint8_t opcion = 1;
  	char caracter = '\0';

  	//SE COLOCAN LOS RECUADROS DE FONDO PARA LAS OPCIONES
  	colocar_elementos_de_fondo_del_menu_principal();
  	//BUCLE MENÚ QUE TERMINA CUANDO SE HA ELEGIDO UNA OPCIÓN    
  	while(true){
  		resaltar_opcion_en_posicion_actual_del_menu_principal(opcion);
    	mostrar_opciones_del_menu_principal();
    
    	caracter = NO_KEY;
    	while(caracter == NO_KEY){
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
	colocar_elementos_de_fondo_del_menu_configurar_agitacion_y_calentamiento();
	
	uint8_t opcion = 1; char caracter;
	while(true){
		resaltar_opcion_en_posicion_actual_del_menu_configurar_agitacion_y_calentamiento(opcion);
    	mostrar_opciones_del_menu_configurar_agitacion_y_calentamiento();
		caracter = NO_KEY;

    	while(caracter == NO_KEY){
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
	colocar_elementos_de_fondo_del_menu_activar_o_desactivar_plazas();
	for(uint8_t plaza = 0; plaza < CANT_PLAZAS; ++plaza){
		uint8_t opcion = 1; char caracter;
		while (true)
		{
			resaltar_opcion_en_posicion_actual_del_menu_activar_o_desactivar_plazas(opcion, plaza + 1);
			mostrar_opciones_del_menu_activar_o_desactivar_plazas(plaza + 1);
			caracter = NO_KEY;
    		while(caracter == NO_KEY){
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
					plazas[plaza].activado = false;
				else
					plazas[plaza].activado = true;
				break;
			}
    		else if(caracter == 'B'){
				if(plaza == 0){
					configurar_agitacion_y_calentamiento();					
					return;
				}	
				colocar_en_gris_el_marco_del_numero_de_la_plaza_actual( plaza + 1);
				plaza-=2;
				break;
			}
    

    		if(opcion > 2)
      			opcion = 1;  
    		else if(opcion < 1)
      			opcion = 2;
    	}
	}

	bool configuracionValida = validar_que_por_lo_menos_haya_una_plaza_activada();
	if(configuracionValida)
		elegir_sensor_de_temperatura();
	else{
		desplegar_mensaje_de_que_no_se_ha_activado_ninguna_plaza();
		char caracter = NO_KEY;
    	while(caracter == NO_KEY){
    		caracter = teclado.getKey();
  			if(caracter != 'B')
    			caracter = NO_KEY;
    	}
		activar_o_desactivar_plazas();
	}	
}

bool validar_que_por_lo_menos_haya_una_plaza_activada()
{
	for(uint8_t i = 0; i < CANT_PLAZAS; ++i)
	{
		if(plazas[i].activado)
			return true;		
	}
	return false;
}

void elegir_sensor_de_temperatura()
{
	colocar_elementos_de_fondo_del_menu_elegir_sensor_de_temperatura();
	uint8_t opcion = 1; bool activarSensorInfrarrojo; char caracter;
	while(true){
		resaltar_opcion_en_posicion_actual_del_menu_elegir_sensor_de_temperatura(opcion);
    	mostrar_opciones_del_menu_elegir_sensor_de_temperatura();
		caracter = NO_KEY;
    	while(caracter == NO_KEY){
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
				delay(1); //activar sensor infrarrojo
			else
				delay(1);//desactivar sensor infrarrojo
			elegir_funcion_de_calentamiento();
			break;
		}
    	else if(caracter == 'B'){
			activar_o_desactivar_plazas();
    		break;
		}
    

    	if(opcion > 2)
      		opcion = 1;  
    	else if(opcion < 1)
      		opcion = 2;
    }
}

void elegir_funcion_de_calentamiento()
{
	colocar_elementos_de_fondo_del_menu_elegir_funcion_de_calentamiento();
	char caracter; uint8_t opcion = 1; 
	while(true){
    	mostrar_opciones_del_menu_elegir_funcion_de_calentamiento(opcion);
		caracter = NO_KEY;
    	while(caracter == NO_KEY){
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
				establecer_setpoint_para_un_calentamiento_constante();
			else if(opcion == 2){
				establecer_setpoints_para_una_rampa_de_temperatura();
			}
			break;
		}
    	else if(caracter == 'B'){
			elegir_sensor_de_temperatura();
			break;
		}
    		
    

    	if(opcion > 2)
      		opcion = 1;  
    	else if(opcion < 1)
      		opcion = 2;
    }
}

void establecer_setpoint_para_un_calentamiento_constante()
{
	colocar_elementos_de_fondo_del_menu_establecer_setpoint_para_un_calentamiento_constante();
	char caracter; uint32_t temperatura = 0; uint8_t digito;
	while(true){
		caracter = NO_KEY;
    	while(caracter == NO_KEY){
      		caracter = teclado.getKey();
      		if(caracter == '*' || caracter == '#' || caracter == 'D')
        		caracter = NO_KEY;
    	}

		if(isdigit(caracter))
		{
			//escribeDigitoTempModoGrupal();
		}


    	if(caracter == 'C')
      		temperatura = 0;
    	else if(caracter == 'D')
    		break;
		else if(caracter == 'A'){
			//if(opcion == 1)
				//elegirSetpoin();
			//else
				//elegirSetpointInicialTempRampaModoGrupal();
			break;
		}
    	else if(caracter == 'B'){
			elegir_funcion_de_calentamiento();
			break;
		}
    		
    }
}

void establecer_setpoints_para_una_rampa_de_temperatura()
{

}




void monitorear_agitacion_y_temperatura()
{

}

void mostrar_el_estado_del_enlace()
{
	colocar_elementos_de_fondo_del_menu_mostrar_el_estado_del_enlace();
	char caracter = NO_KEY;
	bool conectado = obtener_estado_del_enlace();
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


