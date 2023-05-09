#include "HMI.h"

Plaza plazas[CANT_PLAZAS];
bool sensorInfrarrojo; 


void inicializar_plazas(){
	for(int i = 0; i < CANT_PLAZAS;i++){
   		plazas[i].activado = false;
		plazas[i].motor.activado = false;
		plazas[i].platoCalefactor.activado = false;
	}  
	sensorInfrarrojo = false;
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
  	char caracter = NO_KEY;

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
	
	uint8_t opcion = 1; char caracter = NO_KEY;
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
	bool plazas_activadas[CANT_PLAZAS];
	for(uint8_t i = 0; i < CANT_PLAZAS; ++i) {
		plazas_activadas[i] = plazas[i].activado;
	}
	colocar_elementos_de_fondo_del_menu_activar_o_desactivar_plazas(plazas_activadas, CANT_PLAZAS);
	uint8_t i = 0; 
	char caracter = NO_KEY;
	while( i >= 0 && i < CANT_PLAZAS) {
		resaltar_opcion_en_posicion_actual_del_menu_activar_o_desactivar_plazas(plazas_activadas, i, CANT_PLAZAS);
		caracter = NO_KEY;
    	while(caracter == NO_KEY){
      		caracter = teclado.getKey();
      		if(caracter != 'C' && caracter != 'D' && caracter != 'A' && caracter != 'B')
        		caracter = NO_KEY;
    	}

		if(caracter == 'A') {
			if(plazas[i].activado) {
				plazas[i].activado = false;
				plazas_activadas[i] = false;
			}else {
				plazas[i].activado = true;
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
			if(i >= CANT_PLAZAS) {
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

	uint8_t opcion = 1; 
	bool activarSensorInfrarrojo; 
	char caracter = NO_KEY;

	while(true){
		resaltar_opcion_en_posicion_actual_del_menu_elegir_sensor_de_temperatura(opcion);
    	mostrar_opciones_del_menu_elegir_sensor_de_temperatura(sensorInfrarrojo);

		caracter = NO_KEY;
    	while(caracter == NO_KEY){
      		caracter = teclado.getKey();
      		if(caracter != 'C' && caracter != 'D' && caracter != 'A' && caracter != 'B')
        		caracter = NO_KEY;
    	}
    
    	if(caracter == 'C') {
			elegir_funcion_de_calentamiento();
		} else if(caracter == 'D') {
			opcion++;
		} else if(caracter == 'A'){
			if(opcion == 1) {
				sensorInfrarrojo = true;
			} else {
				sensorInfrarrojo = false;
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
	colocar_elementos_de_fondo_del_menu_elegir_funcion_de_calentamiento();
	char caracter = NO_KEY; 
	uint8_t opcion = 1; 
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
	char caracter = NO_KEY;
	String temperatura_en_texto = "0";
	uint32_t temperatura_en_numero = 0; 
	while(true){
		coloca_valor_de_temperatura_en_el_menu_establecer_setpoint_para_un_calentamiento_constante(temperatura_en_texto.toInt());
		caracter = NO_KEY;
    	while(caracter == NO_KEY){
      		caracter = teclado.getKey();
      		if(caracter == '*' || caracter == '#' || caracter == 'D')
        		caracter = NO_KEY;
    	}

		if(isdigit(caracter))
		{
			temperatura_en_texto += caracter;
			if(temperatura_en_texto.toInt() > 999) {
				temperatura_en_texto = caracter;
			}
		}


    	if(caracter == 'C') {
			temperatura_en_texto = "0";
		}
      	
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


