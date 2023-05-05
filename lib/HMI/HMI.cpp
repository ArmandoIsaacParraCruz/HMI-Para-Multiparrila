#include "HMI.h"
#include "Pantalla.h"

motor motores[6]; 


void inicializaPlatosYMotores(){
	for(int i = 0; i < 6;i++){
   		motores[i].activado = false;
    /*
    platosCalefactores[i].activado = false;  
    */ 
  }  
}


void inicializaHMI()
{
	inicializaComunicacionInalambrica();
  	inicializaPlatosYMotores();
  	configuraPantalla();
  	muestraLogoUAM();
}



uint8_t menuPrincipal(){
  
	uint8_t opcion = 1;
  	char caracter = '\0';

  	//SE COLOCAN LOS RECUADROS DE FONDO PARA LAS OPCIONES
  	colocaElementosEstaticosMenuPrincipal();
  	//BUCLE MENÚ QUE TERMINA CUANDO SE HA ELEGIDO UNA OPCIÓN    
  	while(true){
  		resaltaOpcionMenuPrincipal(opcion);
    	escribeTextoOpcionesMenuPrincipal();
    
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



void muestraMenuOpcionElegida(uint8_t opcion)
{
	if(opcion == 1)
		configAgitacionCalentamiento();
  	else if(opcion == 2)
		monitorearMultiparrilla();
  	else if(opcion == 3)
    	menuEstadoDelEnlace();
}


void configAgitacionCalentamiento()
{
	
	colocaElementosEstaticosMenuConfigAgitacionCalentamiento();
	
	uint8_t opcion = 1; char caracter;
	while(true){
		resaltaOpcionMenuConfigAgitacionCalentamiento(opcion);
    	escribeTextoOpcionesMenuConfigCalentamiento();
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
				configuracionGrupal();
			else
				configuracionIndividual();
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

void configuracionGrupal()
{
	colocaElementosEstaticosConfiguracionGrupal();
	for(uint8_t plaza = 1; plaza <= 6; ++plaza){
		uint8_t opcion = 1; char caracter;//plazas[plaza].activar;
		while (true)
		{
			resaltaOpcionActivarDesactivarPlaza(opcion, plaza);
			escribeTextoOpcionesActivarDesactivarPlaza(plaza);
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
					delay(1); //activar plaza
				else
					delay(1);//desactivar plaza
				break;
			}
    		else if(caracter == 'B'){
				if(plaza == 1){
					configAgitacionCalentamiento();					
					return;
				}	
				plaza-=2;
				break;
			}
    

    		if(opcion > 2)
      			opcion = 1;  
    		else if(opcion < 1)
      			opcion = 2;
    	}
	}
	activarDesactivarSensorInfrarrojo();
}
	

void activarDesactivarSensorInfrarrojo()
{
	colocaElementosEstaticosPreguntaSiActivarSensorInfrarrojo();
	uint8_t opcion = 1; bool activarSensorInfrarrojo; char caracter;
	while(true){
		resaltaOpcionActivarDesactivarSensorInfrarrojo(opcion);
    	escribeTextoOpcionesActivarDesactivarSensorInfrarrojo();
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
			configurarFuncTemperatura();
			break;
		}
    	else if(caracter == 'B')
    		break;
    

    	if(opcion > 2)
      		opcion = 1;  
    	else if(opcion < 1)
      		opcion = 2;
    }
}

void configurarFuncTemperatura()
{
	colocaElementosEstaticosFuncTemperatura();
	char caracter; uint8_t opcion; 
	while(true){
    	escribeTextoOpcionesFuncTemperatura(opcion);
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
			//configurarRutinaGrupal();
			break;
		}
    	else if(caracter == 'B')
    		break;
    

    	if(opcion > 2)
      		opcion = 1;  
    	else if(opcion < 1)
      		opcion = 2;
    }
	return;
}



void configuracionIndividual()
{

}



void monitorearMultiparrilla()
{

}

void menuEstadoDelEnlace()
{
	colocaElementosEstaticosMenuEstadoDelEncale();
	char caracter = NO_KEY;
	bool conectado = obtenerEstadoDelEnlace();
	muestraEstadoDelEnlace(conectado);
	while(caracter == NO_KEY){
    	caracter = teclado.getKey();
		if(caracter == 'A'){
			conectado = obtenerEstadoDelEnlace();
			muestraEstadoDelEnlace(conectado);
			caracter = NO_KEY;
		}
		else if(caracter != 'B')
        	caracter = NO_KEY;
    }
}


