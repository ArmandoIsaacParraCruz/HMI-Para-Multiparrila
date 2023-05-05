#include "Pantalla.h"

TFT_eSPI pantalla = TFT_eSPI();

void configuraPantalla()
{
    pantalla.begin(2);
    pantalla.invertDisplay(false);
    pantalla.setRotation(1);
    pantalla.fillScreen(MY_WHITE);
    pantalla.setSwapBytes(true);
}

void muestraLogoUAM(){
 	int32_t logoX = 65,logoY = 10,txtX = 120, txtY = 200;
	pantalla.pushImage(logoX, logoY, logoAncho, logoAlto, logoUAM);
	pantalla.setFreeFont(FF47);
	pantalla.setTextColor(MY_BLACK);
	pantalla.drawString("LCAR", txtX, txtY, GFXFF);
	delay(3000);
	pantalla.fillScreen(MY_SKYBLUE);
}

void colocaElementosEstaticosMenuPrincipal()
{
	uint32_t posX = 45,posY = 10, ancho = 240, alto = 60, separacion = 10; 
	pantalla.fillScreen(MY_SKYBLUE);
	pantalla.fillRect(posX,posY,ancho,alto, MY_BLACK);
	pantalla.fillRect(posX,posY + alto + separacion,ancho,alto,MY_BLACK);
	pantalla.fillRect(posX,posY + alto + alto + separacion + separacion,ancho,alto,MY_BLACK);


	uint32_t x1_1 = 35,y1_1 = 230, x2_1 = 45, y2_1 = 230, x3_1 = 40, y3_1 = 220,
             x1_2 = 135,y1_2 = 220, x2_2 = 145, y2_2 = 220, x3_2 = 140, y3_2 = 230;
	pantalla.fillTriangle(x1_1, y1_1, x2_1, y2_1, x3_1, y3_1, MY_BLACK);
	pantalla.fillTriangle(x1_2, y1_2, x2_2, y2_2, x3_2, y3_2, MY_BLACK);
	pantalla.setFreeFont(FMB9);
	pantalla.setTextColor(MY_BLACK);
	pantalla.drawString("C:", x1_1 - 2*separacion, y3_1 - 2);
	pantalla.drawString("D:", x1_2 - 2*separacion, y1_2 - 2);
	pantalla.drawString("A: ELEGIR", x1_2 + 8*separacion, y1_2 - 2);
}

void resaltaOpcionMenuPrincipal(uint8_t opcion)
{
	uint32_t posX = 50,posY = 15, ancho = 230, alto = 50, separacion = 0, color;

	for(uint8_t i = 1; i <= 3; ++i, separacion += 70){
		if(i == opcion)
    		color = MY_YELLOW;
    	else
      		color = MY_WHITE;
    
    	pantalla.fillRect(posX,posY + separacion,ancho,alto, color);
	}
}

void escribeTextoOpcionesMenuPrincipal()
{
    pantalla.fillTriangle(241, 25, 243, 21, 246, 21, MY_BLACK);
    pantalla.drawString("CONFIG. AGITACION", 70, 25);
    pantalla.drawString("Y CALENTAMIENTO", 80, 40);

    pantalla.drawString("MONITOREAR", 110, 95);
    pantalla.drawString("MULTIPARRILLA", 95, 110);

    pantalla.drawString("ESTADO DEL ENLACE",70, 172);
}

void colocaElementosEstaticosMenuConfigAgitacionCalentamiento()
{
	muestraImagenMultiparrilla();
	uint32_t posX = 20;
	for(uint8_t i = 0; i < 6; ++i, posX+=50){
		pantalla.fillRect(posX, 6, 30, 30, MY_SILVER);
		pantalla.drawString((String)(i+1),posX + 4, 10);
	}

	pantalla.fillRect(40, 90, 250, 50, MY_BLACK);
	pantalla.fillRect(40, 150, 250, 50, MY_BLACK);

	uint32_t x1_1 = 30,y1_1 = 230, x2_1 = 40, y2_1 = 230, x3_1 = 35, y3_1 = 220,
         	 x1_2 = 75,y1_2 = 220, x2_2 = 85, y2_2 = 220, x3_2 = 80, y3_2 = 230,
			 separacion = 10;
	pantalla.fillTriangle(x1_1, y1_1, x2_1, y2_1, x3_1, y3_1, MY_BLACK);
	pantalla.fillTriangle(x1_2, y1_2, x2_2, y2_2, x3_2, y3_2, MY_BLACK);
	pantalla.setFreeFont(FMB9);
	pantalla.setTextColor(MY_BLACK);
	pantalla.drawString("C:", x1_1 - 2*separacion, y3_1 - 2);
	pantalla.drawString("D:", x1_2 - 2*separacion, y1_2 - 2);
	pantalla.drawString("A:ELEGIR", x1_2 + 3*separacion, y1_2 - 2);
	pantalla.drawString("B:REGRESAR", x1_2 + 13*separacion, y1_2 - 2);
}

void muestraImagenMultiparrilla()
{
	int32_t imagenX = 10,imagenY = 0;
	pantalla.fillScreen(MY_SKYBLUE);
	pantalla.pushImage(imagenX, imagenY, multiparrillaImagenAncho, multiparrillaImagenAlto, multiparrillaImagen);
	pantalla.setFreeFont(FF47);
	pantalla.setTextColor(MY_BLACK);
}

void resaltaOpcionMenuConfigAgitacionCalentamiento(uint8_t opcion)
{
	uint32_t posX = 45,posY = 95, ancho = 240, alto = 40, separacion = 0, color;
	pantalla.fillRect(40, 90, 250, 50, MY_BLACK);
	for(uint8_t i = 1; i <= 2; ++i, separacion += 60){
		if(i == opcion)
    		color = MY_YELLOW;
    	else
      		color = MY_WHITE;
    
    	pantalla.fillRect(posX,posY + separacion,ancho,alto, color);
	}

}
void escribeTextoOpcionesMenuConfigCalentamiento()
{
	pantalla.drawString("CONFIG. GRUPAL", 85, 108);
    pantalla.drawString("CONFIG. INDIVIDUAL", 65, 168);
}

void colocaElementosEstaticosPreguntaActivarSensorInfrarrojo()
{
    pantalla.fillRect(40, 90, 250, 50, MY_WHITE);
	pantalla.drawString("SENSOR INFRARROJO", 80, 108);
}

void resaltaOpcionActivarSensorInfrarrojo(uint8_t opcion)
{
	uint32_t posX = 45,posY = 155, ancho = 120, alto = 40, separacion = 0, color;

	for(uint8_t i = 1; i <= 2; ++i, separacion += 120){
		if(i == opcion)
    		color = MY_YELLOW;
    	else
      		color = MY_WHITE;
    
    	pantalla.fillRect(posX + separacion,posY,ancho,alto, color);
	}
}

void escribeTextoOpcionesActivarSensorInfrarrojo()
{
	pantalla.drawString("ACTIVAR", 65, 168);
    pantalla.drawString("DESACTIVAR", 170, 168);
}

void colocaElementosEstaticosMenuEstadoDelEncale()
{
	pantalla.fillScreen(MY_SKYBLUE);
	pantalla.drawString("REGRESAR: B", 190, 220);
	pantalla.drawString("ACTUALIZAR: A", 10, 220);
	pantalla.fillRect(45, 30, 240, 130, MY_BLACK);
	pantalla.fillRect(50, 35, 230, 120, MY_WHITE);
}

void muestraEstadoDelEnlace(const bool conectado)
{
	String respuesta; 
	uint32_t x,  y = 85, tam, color, font = 4;
	if(conectado){
		color = MY_GREEN;
		respuesta = "CONECTADO";
		x = 80;
	}
	else{
		color = MY_RED;
		respuesta = "DESCONECTADO";
		x = 65;
	}
	pantalla.fillRect(50, 35, 230, 120, color);
	pantalla.drawString(respuesta, x, y, font);
}