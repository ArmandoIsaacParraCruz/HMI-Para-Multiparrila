#include "HMI.h"

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
    
    	caracter = teclado.getKey();
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

    	Serial.println(opcion);
  }
  return opcion;  
}



void muestraMenuOpcionElegida(uint8_t opcion)
{
  if(opcion == 1)
  {
	configAgitacionCalentamiento();
  }
  else if(opcion == 2)
  {
	monitorearMultiparrilla();
  }
  else if(opcion == 3)
  {
    menuEstadoDelEnlace();
  }
}

void menuEstadoDelEnlace()
{
  
}
