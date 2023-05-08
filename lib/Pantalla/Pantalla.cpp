#include "Pantalla.h"

TFT_eSPI pantalla = TFT_eSPI();

void inicializar_pantalla()
{
    pantalla.begin(2);
    pantalla.invertDisplay(false);
    pantalla.setRotation(1);
    pantalla.fillScreen(MY_WHITE);
    pantalla.setSwapBytes(true);
}

void mostrar_logo_UAM(){
 	int32_t logoX = 65,logoY = 10,txtX = 120, txtY = 200;
	pantalla.pushImage(logoX, logoY, logoAncho, logoAlto, logoUAM);
	pantalla.setFreeFont(FF47);
	pantalla.setTextColor(MY_BLACK);
	pantalla.drawString("LCAR", txtX, txtY, GFXFF);
	delay(3000);
	pantalla.fillScreen(MY_SKYBLUE);
}

void colocar_elementos_de_fondo_del_menu_principal()
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

void resaltar_opcion_en_posicion_actual_del_menu_principal(uint8_t opcion)
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

void mostrar_opciones_del_menu_principal()
{
	pantalla.setFreeFont(FMB9);
    pantalla.fillTriangle(241, 25, 243, 21, 246, 21, MY_BLACK);
    pantalla.drawString("CONFIG. AGITACION", 70, 25);
    pantalla.drawString("Y CALENTAMIENTO", 80, 40);

    pantalla.drawString("MONITOREAR", 110, 95);
    pantalla.drawString("MULTIPARRILLA", 95, 110);

    pantalla.drawString("ESTADO DEL ENLACE",70, 172);
}

void colocar_elementos_de_fondo_del_menu_configurar_agitacion_y_calentamiento()
{
	mostrar_imagen_multiparrilla();
	uint32_t posX = 20;
	for(uint8_t i = 0; i < 6; ++i, posX+=50){
		pantalla.fillRect(posX, 6, 30, 30, MY_SILVER);
		pantalla.drawString((String)(i+1),posX + 4, 6);
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

void mostrar_imagen_multiparrilla()
{
	int32_t imagenX = 10,imagenY = 0;
	pantalla.fillScreen(MY_SKYBLUE);
	pantalla.pushImage(imagenX, imagenY, multiparrillaImagenAncho, multiparrillaImagenAlto, multiparrillaImagen);
	pantalla.setFreeFont(FF47);
	pantalla.setTextColor(MY_BLACK);
}

void resaltar_opcion_en_posicion_actual_del_menu_configurar_agitacion_y_calentamiento(uint8_t opcion)
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
void mostrar_opciones_del_menu_configurar_agitacion_y_calentamiento()
{
	pantalla.setFreeFont(FMB9);
	pantalla.drawString("CONFIG. GRUPAL", 85, 108);
    pantalla.drawString("CONFIG. INDIVIDUAL", 65, 168);
}

void colocar_elementos_de_fondo_del_menu_activar_o_desactivar_plazas()
{
	uint32_t x1_1 = 30,y1_1 = 220, x2_1 = 30, y2_1 = 230, x3_1 = 40, y3_1 = 225,
         	 x1_2 = 85,y1_2 = 220, x2_2 = 85, y2_2 = 230, x3_2 = 75, y3_2 = 225;
	pantalla.fillRect(10,90, 300, 120, MY_SKYBLUE);
	pantalla.fillRect(40, 150, 250, 50, MY_BLACK);
	pantalla.fillRect(40, 90, 250, 50, MY_WHITE);
	pantalla.fillRect(30,220, 10, 15, MY_SKYBLUE);
	pantalla.fillRect(75,220, 10, 15, MY_SKYBLUE);
	pantalla.fillTriangle(x1_1, y1_1, x2_1, y2_1, x3_1, y3_1, MY_BLACK);
	pantalla.fillTriangle(x1_2, y1_2, x2_2, y2_2, x3_2, y3_2, MY_BLACK);
	uint32_t posX = 20;pantalla.setFreeFont(FF47);
	for(uint8_t i = 0; i < 6; ++i, posX+=50){
		pantalla.fillRect(posX, 6, 30, 30, MY_SILVER);
		pantalla.drawString((String)(i+1),posX + 4, 6);
	}
}

void desplegar_mensaje_de_que_no_se_ha_activado_ninguna_plaza()
{
	pantalla.setFreeFont(TT1);
	pantalla.fillRect(10, 90, 300, 120, MY_YELLOW);
	pantalla.drawString("NO SE HA ACTIVADO", 45, 95,FONT4);
	pantalla.drawString("NINGUNA PLAZA", 60,120, FONT4);
	pantalla.drawString("OPRIMA (B) PARA CONTINUAR", 62,150, FONT2);
}

void resaltar_opcion_en_posicion_actual_del_menu_activar_o_desactivar_plazas(uint8_t opcion, uint8_t plaza)
{
	uint32_t posX = 45,posY = 155, ancho = 120, alto = 40, separacion = 0, color, colorPlaza, posNumX = 20, separacionNum = 50;
	for(uint8_t i = 1; i <= 2; ++i, separacion += 120){
		if(i == opcion){
			color = MY_YELLOW;
			colorPlaza = MY_GREEN;
		}
    		
    	else{
			color = MY_WHITE;
			colorPlaza = MY_GREY;
		}

    	pantalla.fillRect(posX + separacion,posY,ancho,alto, color);
	}
	
	pantalla.setFreeFont(FF47);
	posNumX += separacionNum * (plaza - 1);
	pantalla.fillRect(posNumX, 6, 30, 30, colorPlaza);
	pantalla.drawString((String)(plaza),posNumX + 4, 6);
	pantalla.fillRect(posNumX, 33, 30, 3, MY_RED);
	pantalla.setFreeFont(FMB9);
	pantalla.drawString("DESACTIVAR", 53, 168);
    pantalla.drawString("ACTIVAR", 185, 168);
}

void colocar_en_gris_el_marco_del_numero_de_la_plaza_actual(uint8_t plaza)
{
	pantalla.setFreeFont(FF47);
	uint32_t posNumX = 20 + 50* (plaza - 1);
	pantalla.fillRect(posNumX, 6, 30, 30, MY_SILVER);
	pantalla.drawString((String)(plaza),posNumX + 4, 6);
}



void mostrar_opciones_del_menu_activar_o_desactivar_plazas(uint8_t plaza)
{
	pantalla.setFreeFont(FMB9);
	pantalla.fillRect(40, 90, 250, 50, MY_WHITE);
	pantalla.drawString("PLAZA:", 110, 108);
	pantalla.drawString((String)(plaza), 200, 108);
}

void colocar_elementos_de_fondo_del_menu_elegir_sensor_de_temperatura()
{
	pantalla.setFreeFont(FMB9);
	pantalla.fillRect(10,90, 300, 120, MY_SKYBLUE);
	pantalla.fillRect(40, 150, 250, 50, MY_BLACK);
	pantalla.fillRect(40, 90, 250, 50, MY_WHITE);
    pantalla.fillRect(40, 90, 250, 50, MY_WHITE);
	pantalla.drawString("SENSOR DE TEMPERATURA", 50, 108);
}

void resaltar_opcion_en_posicion_actual_del_menu_elegir_sensor_de_temperatura(uint8_t opcion)
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

void mostrar_opciones_del_menu_elegir_sensor_de_temperatura()
{
	pantalla.setFreeFont(FMB9);
	pantalla.drawString("INFRARROJO", 50, 168);
    pantalla.drawString("TERMOPAR", 180, 168);
}



void colocar_elementos_de_fondo_del_menu_elegir_funcion_de_calentamiento()
{
	pantalla.fillRect(10, 90, 300, 120, MY_WHITE);
	pantalla.setFreeFont(TT1);
	pantalla.drawString("FUNC. DE TEMPERATURA:", 11, 90, FONT2);
}


void mostrar_opciones_del_menu_elegir_funcion_de_calentamiento(uint8_t opcion)
{
	pantalla.setFreeFont(TT1);
	if(opcion == 1){
		pantalla.fillRect(175, 91, 125, 15, MY_GREEN);
		pantalla.drawString("CONSTANTE", 200, 90, FONT2);
	}else
	{
		pantalla.fillRect(175, 91, 125, 15, MY_YELLOW);
		pantalla.drawString("RAMPA", 210, 90, FONT2);
	}
}

void colocar_elementos_de_fondo_del_menu_establecer_setpoint_para_un_calentamiento_constante()
{
	pantalla.setFreeFont(TT1);
	pantalla.drawString("TEMPERATURA:", 10, 105, FONT2);
	pantalla.drawString("C", 300, 105, FONT2);
	pantalla.drawCircle(295,108,2,MY_BLACK);
	pantalla.fillRect(10,220, 190, 15, MY_SKYBLUE);
	pantalla.setFreeFont(FMB9);
	pantalla.drawString("C:BORRAR", 10, 218);
	pantalla.drawString("A:ACEPT.", 110, 218);
}


void colocar_elementos_de_fondo_del_menu_mostrar_el_estado_del_enlace()
{
	pantalla.fillScreen(MY_SKYBLUE);
	pantalla.drawString("REGRESAR: B", 190, 220);
	pantalla.drawString("ACTUALIZAR: A", 10, 220);
	pantalla.fillRect(45, 30, 240, 130, MY_BLACK);
	pantalla.fillRect(50, 35, 230, 120, MY_WHITE);
}

void mostrar_en_pantalla_el_estado_del_enlace(const bool conectado)
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