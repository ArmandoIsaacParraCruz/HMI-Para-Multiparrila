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
	uint32_t posX = 45,posY = 10, ancho = 240, alto = 60, separacion = 10,
			 x1_1 = 35,y1_1 = 230, x2_1 = 45, y2_1 = 230, x3_1 = 40, y3_1 = 220,
             x1_2 = 135,y1_2 = 220, x2_2 = 145, y2_2 = 220, x3_2 = 140, y3_2 = 230;

	pantalla.fillScreen(MY_SKYBLUE);
	pantalla.fillRect(posX,posY,ancho,alto, MY_BLACK);
	pantalla.fillRect(posX,posY + alto + separacion,ancho,alto,MY_BLACK);
	pantalla.fillRect(posX,posY + alto + alto + separacion + separacion,ancho,alto,MY_BLACK);

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

	for(uint8_t i = 1; i <= 3; ++i, separacion += 70) {
		if(i == opcion) {
			color = MY_YELLOW;
		} else {
			color = MY_WHITE;
		} 
      		
    
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

    pantalla.drawString("ESTADO DEL ENLACE",70, 165);
	 pantalla.drawString("Y SALIDA DE DATOS",70, 180);
}



void mostrar_que_la_multiparrilla_no_esta_conectada_en_el_menu_configurar_agitacion_y_calentamiento()
{
	pantalla.fillScreen(MY_SKYBLUE);
	pantalla.fillRect(10, 100, 300, 100, MY_YELLOW);
	pantalla.setFreeFont(FMB9);
	pantalla.fillRect(10, 10, 300, 200, MY_YELLOW);
	pantalla.drawString(".ADVERTENCIA!", 60, 30,FONT4);
	pantalla.drawLine(62,30,62,43, MY_BLACK);
	pantalla.drawLine(63,30,63,43, MY_BLACK);
	pantalla.drawString("LA COMUNICACION INALAMBRICA", 10,90);
	pantalla.drawLine(160,90,162,88, MY_BLACK);
	pantalla.drawLine(161,90,163,88, MY_BLACK);
	pantalla.drawLine(236,90,238,88, MY_BLACK);
	pantalla.drawLine(237,90,239,88, MY_BLACK);
	pantalla.drawString("CON LA MULTIPARRILLA NO SE", 20,120);
	pantalla.drawString("ENCUENTRA DISPONIBLE EN", 40,150);
	pantalla.drawString("ESTE MOMENTO", 90,180);
	pantalla.drawString("C:CONTINUAR", 10, 220);
	pantalla.drawString("B:REGRESAR", 190, 220);
}

void mostrar_que_se_ha_restablecido_la_conexion_en_el_menu_configurar_agitacion_y_calentamiento()
{
	pantalla.fillScreen(MY_SKYBLUE);
	pantalla.fillRect(10, 100, 300, 100, MY_YELLOW);
	pantalla.setFreeFont(FMB9);
	pantalla.fillRect(10, 10, 300, 200, MY_GREEN);
	pantalla.drawString("LA COMUNICACION INALAMBRICA", 10,60);
	pantalla.drawLine(160,60,162,58, MY_BLACK);
	pantalla.drawLine(161,60,163,58, MY_BLACK);
	pantalla.drawLine(236,60,238,58, MY_BLACK);
	pantalla.drawLine(237,60,239,58, MY_BLACK);
	pantalla.drawString("CON LA MULTIPARRILLA SE HA", 20,110);
	pantalla.drawString("RESTABLECIDO", 90,160);
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
	for(uint8_t i = 1; i <= 2; ++i, separacion += 60) {
		if(i == opcion) {
			color = MY_YELLOW;
		} else {
			color = MY_WHITE;
		}
    	pantalla.fillRect(posX,posY + separacion,ancho,alto, color);
	}

}


void colocar_elementos_de_fondo_del_menu_activar_o_desactivar_plazas(bool *plazas_activadas, const uint8_t cantidad_de_plazas)
{
	uint32_t x1_1 = 223,y1_1 = 222, x2_1 = 223, y2_1 = 232, x3_1 = 233, y3_1 = 227,
         	 x1_2 = 220,y1_2 = 222, x2_2 = 220, y2_2 = 232, x3_2 = 210, y3_2 = 227,
			 posX = 17, color;

	pantalla.fillScreen(MY_SKYBLUE);
	mostrar_imagen_multiparrilla();
	pantalla.setFreeFont(FF47);
	for(uint8_t i = 0; i < cantidad_de_plazas; ++i, posX+=50) {
		if(plazas_activadas[i]) {
			color = MY_GREEN;
		} else {
			color = MY_SILVER;
		}
		pantalla.fillRect(posX, 3, 36, 36, color);
		pantalla.drawString((String)(i+1),posX + 7, 6);
	}

	
	pantalla.fillRect(40, 150, 250, 50, MY_BLACK);
	pantalla.fillTriangle(x1_1, y1_1, x2_1, y2_1, x3_1, y3_1, MY_BLACK);
	pantalla.fillTriangle(x1_2, y1_2, x2_2, y2_2, x3_2, y3_2, MY_BLACK);

	pantalla.setFreeFont(FMB9);
	pantalla.setTextColor(MY_BLACK);
	pantalla.drawString("A:ELEGIR", 10, 205);
	pantalla.drawString("B:REGRESAR", 10, 220);
	pantalla.drawString("C:CONTINUAR", 190, 205);
	pantalla.drawString("D:", 190, 220);
}

void desplegar_mensaje_de_que_no_se_ha_activado_ninguna_plaza()
{
	pantalla.setFreeFont(TT1);
	pantalla.fillRect(10, 90, 300, 120, MY_YELLOW);
	pantalla.drawString("NO SE HA ACTIVADO", 45, 95,FONT4);
	pantalla.drawString("NINGUNA PLAZA", 60,120, FONT4);
	pantalla.setFreeFont(FMB9);
	pantalla.drawString("OPRIMA (B) PARA REGRESAR", 30,150);
}

void resaltar_opcion_en_posicion_actual_del_menu_activar_o_desactivar_plazas(bool *plazas_activadas, uint8_t indice_plaza_actual, const uint8_t cantidad_de_plazas)
{
	uint32_t x = 20, color_recuadro_numero, color_recuadro_texto;
	uint8_t indice_plaza_anterior, espacio_texto_activar_o_desactivar;
	String texto_opcion_activar_o_desactivar, texto_estado_de_la_plaza;
	if(indice_plaza_actual == 0) {
		indice_plaza_anterior = cantidad_de_plazas - 1;
	} else {
		indice_plaza_anterior = indice_plaza_actual - 1;
	}

    if(plazas_activadas[indice_plaza_anterior]) {
		color_recuadro_numero = MY_GREEN;
	} else {
		color_recuadro_numero = MY_SILVER;
	}
	pantalla.setFreeFont(FF47);
	pantalla.fillRect(x + 50 * indice_plaza_anterior-3, 3, 36, 36, color_recuadro_numero);
	pantalla.drawString((String)(indice_plaza_anterior + 1),x + 50 * indice_plaza_anterior + 4, 6);

	pantalla.fillRect(x + 50 * indice_plaza_actual -3, 3, 36, 36, MY_RED);
    if(plazas_activadas[indice_plaza_actual]) {
		color_recuadro_numero = MY_GREEN;
		color_recuadro_texto = MY_SILVER;
		texto_opcion_activar_o_desactivar = "DESACTIVAR";
		texto_estado_de_la_plaza = "ACTIVADA";
		espacio_texto_activar_o_desactivar = 0;
	} else {
		color_recuadro_numero = MY_SILVER;
		color_recuadro_texto = MY_GREEN;
		texto_opcion_activar_o_desactivar = "ACTIVAR";
		texto_estado_de_la_plaza = "DESACTIVADA";
		espacio_texto_activar_o_desactivar = 20;
	}
	
	pantalla.fillRect(x + 50*indice_plaza_actual, 6, 30, 30, color_recuadro_numero);
	pantalla.fillRect(45, 155, 240, 40, color_recuadro_texto);
	pantalla.drawString((String)(indice_plaza_actual + 1),x + 50 * indice_plaza_actual + 4, 6);
	pantalla.fillRect(40, 90, 250, 50, color_recuadro_numero);
	pantalla.setFreeFont(FMB9);
	pantalla.drawString("PLAZA", 110, 95);
	pantalla.drawString((String)(indice_plaza_actual + 1), 190, 95);
	pantalla.drawString(texto_estado_de_la_plaza, 110, 115);
	pantalla.drawString("PRESIONE 'A' PARA", 70, 158);
	pantalla.drawString(texto_opcion_activar_o_desactivar, 110 + espacio_texto_activar_o_desactivar, 178);
}

void colocar_en_gris_el_marco_del_numero_de_la_plaza_actual(uint8_t plaza)
{
	uint32_t posNumX = 20 + 50* (plaza - 1);
	pantalla.setFreeFont(FF47);
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

void colocar_elementos_de_fondo_del_menu_elegir_sensor_de_temperatura(bool *plazas_activadas, const uint8_t cantidad_de_plazas)
{
	uint32_t x1_1 = 223,y1_1 = 222, x2_1 = 223, y2_1 = 232, x3_1 = 233, y3_1 = 227,
         	 x1_2 = 220,y1_2 = 222, x2_2 = 220, y2_2 = 232, x3_2 = 210, y3_2 = 227,
			 posX = 17, color;

	pantalla.fillScreen(MY_SKYBLUE);
	mostrar_imagen_multiparrilla();
	pantalla.setFreeFont(FF47);
	for(uint8_t i = 0; i < cantidad_de_plazas; ++i, posX+=50) {
		if(plazas_activadas[i]) {
			color = MY_GREEN;
		} else {
			color = MY_SILVER;
		}
		pantalla.fillRect(posX, 3, 36, 36, color);
		pantalla.drawString((String)(i+1),posX + 7, 6);
	}

	pantalla.setFreeFont(FMB9);
	pantalla.fillRect(10,90, 300, 200, MY_SKYBLUE);
	pantalla.fillRect(40, 150, 250, 50, MY_BLACK);
	pantalla.fillRect(40, 90, 250, 50, MY_WHITE);
	pantalla.drawString("SENSOR DE TEMPERATURA", 45, 95);
	pantalla.drawString("CONFIGURADO:", 45, 120);
	pantalla.fillTriangle(x1_1, y1_1, x2_1, y2_1, x3_1, y3_1, MY_BLACK);
	pantalla.fillTriangle(x1_2, y1_2, x2_2, y2_2, x3_2, y3_2, MY_BLACK);
	pantalla.setFreeFont(FMB9);
	//pantalla.setTextColor(MY_BLACK);
	pantalla.drawString("A:ELEGIR", 10, 205);
	pantalla.drawString("B:REGRESAR", 10, 220);
	pantalla.drawString("C:CONTINUAR", 190, 205);
	pantalla.drawString("D:", 190, 220);
	
}

void resaltar_opcion_en_posicion_actual_del_menu_elegir_sensor_de_temperatura(uint8_t opcion)
{
	uint32_t posX = 45,posY = 155, ancho = 120, alto = 40, separacion = 0, color;

	for(uint8_t i = 1; i <= 2; ++i, separacion += 120){
		if(i == opcion) {
			color = MY_YELLOW;
		} else {
			color = MY_WHITE;
		}
    	pantalla.fillRect(posX + separacion,posY,ancho,alto, color);
	}
}

void mostrar_opciones_del_menu_elegir_sensor_de_temperatura(bool sensorInfrarrojo)
{
	String sensor;

	if(sensorInfrarrojo) {
		sensor = "INFRARROJO";
	} else {
		sensor = "TERMOPAR";
	}

	pantalla.setFreeFont(FMB9);
	pantalla.fillRect(175, 120, 115, 20, MY_WHITE);
	pantalla.drawString(sensor, 175, 120);
	pantalla.drawString("INFRARROJO", 50, 168);
    pantalla.drawString("TERMOPAR", 180, 168);
}

void colocar_elementos_de_fondo_del_menu_configurar_rutina_de_calentamiento_y_agitacion(bool *plazas_activadas, const uint8_t cantidad_de_plazas)
{
	uint32_t x1_1 = 213,y1_1 = 222, x2_1 = 223, y2_1 = 222, x3_1 = 218, y3_1 = 232,
			 posX = 17, color;

	pantalla.fillScreen(MY_SKYBLUE);
	mostrar_imagen_multiparrilla();
	pantalla.setFreeFont(FF47);
	for(uint8_t i = 0; i < cantidad_de_plazas; ++i, posX+=50) {
		if(plazas_activadas[i]) {
			color = MY_GREEN;
		} else {
			color = MY_SILVER;
		}
		pantalla.fillRect(posX, 3, 36, 36, color);
		pantalla.drawString((String)(i+1),posX + 7, 6);
	}

	pantalla.fillRect(10, 100, 300, 100, MY_WHITE);
	pantalla.fillRect(65, 80, 170, 20, MY_WHITE);
	pantalla.setFreeFont(TT1);
	pantalla.drawString("NO. DE RUTINA: ", 70, 80, FONT2);
	pantalla.setFreeFont(FMB9);
	pantalla.drawString("B:REGRESAR", 10, 220);
	pantalla.drawString("C:CONTINUAR", 190, 205);
	pantalla.drawString("D:", 190, 220);
	pantalla.fillTriangle(x1_1, y1_1, x2_1, y2_1, x3_1, y3_1, MY_BLACK);
}

void mostrar_numero_de_rutina_y_posicion_del_cursor(const uint8_t numero_de_rutina, uint8_t posicion_del_cursor, const char funcion_de_temperatura)
{
	uint32_t x1_1 = 10, y1_1 = 100, x2_1 = 10, y2_1 = 110, x3_1 = 20, y3_1 = 105,
	     	 posicion_anterior_del_cursor, espacio_para_desplazar_el_cursor;

	pantalla.setFreeFont(FMB9);
	pantalla.fillRect(190,220,60,20, MY_SKYBLUE);
	pantalla.drawString("D:", 190, 220);
	pantalla.fillTriangle(213, 222, 223, 222, 218, 232, MY_BLACK);
	pantalla.drawString("C:CONTINUAR", 190, 205);
	pantalla.fillRect(10, 205, 180, 15, MY_SKYBLUE);
	if(posicion_del_cursor == 0) {
		pantalla.drawString("A:CAMBIAR FUNC.", 10, 205);
	} else if((posicion_del_cursor == 1 && funcion_de_temperatura == 'c' ) || posicion_del_cursor == 3) {
		pantalla.drawString("A:DESACTIVAR", 10, 205);
	} else if(posicion_del_cursor == 1 && funcion_de_temperatura == 'r') {
		pantalla.drawString("A:TEMP.AMBIENTE", 10, 205);
	} else if(posicion_del_cursor == 2 || posicion_del_cursor == 4) {
		pantalla.drawString("A:BORRAR.", 10, 205);
	}

	if(posicion_del_cursor == 0) {
		if(funcion_de_temperatura == 'c') {
			posicion_anterior_del_cursor = 3;
		} else {
			posicion_anterior_del_cursor = 4;
		}
		espacio_para_desplazar_el_cursor = 0;
	} else {
		if(funcion_de_temperatura == 'c' && posicion_del_cursor >= 3) {
			posicion_del_cursor -= 1;
		} 
		posicion_anterior_del_cursor = posicion_del_cursor - 1;
		espacio_para_desplazar_el_cursor = posicion_del_cursor * 20 + 5;
	}


	pantalla.fillRect(170, 80, 60, 20, MY_WHITE);
	pantalla.setFreeFont(TT1);
	pantalla.drawString((String)(numero_de_rutina + 1) + " DE 20", 170, 80, FONT2);
	pantalla.fillRect(10, 100 + posicion_anterior_del_cursor * 20, 20, 20, MY_WHITE);
	pantalla.fillTriangle(x1_1, y1_1 + espacio_para_desplazar_el_cursor, x2_1, y2_1 + espacio_para_desplazar_el_cursor, x3_1, y3_1 + espacio_para_desplazar_el_cursor, MY_BLACK);

}

void colocar_elementos_de_la_opcion_elegir_funcion_de_calentamiento(const uint16_t setpoint_temperatura_1, const uint16_t setpoint_temperatura_2, const char tipo_de_funcion, const uint16_t setpoint_agitacion, const uint32_t minutos_para_mantener_setpoints)
{
	uint8_t posy_setpoint_agitacion = 140, posy_tiempo = 160;
	uint32_t x1_1 = 10, y1_1 = 100, x2_1 = 10, y2_1 = 110, x3_1 = 20, y3_1 = 105;
	pantalla.setFreeFont(TT1);
	pantalla.fillRect(10, 100, 300, 100, MY_WHITE);
	pantalla.fillRect(65, 80, 105, 20, MY_WHITE);
	pantalla.drawString("NO. DE RUTINA: ", 70, 80, FONT2);
	pantalla.drawString("FUNC. DE TEMPERATURA:", 30, 100, FONT2);
	pantalla.fillTriangle(x1_1, y1_1, x2_1, y2_1, x3_1, y3_1, MY_BLACK);
	if(tipo_de_funcion == 'r') {
		pantalla.fillRect(190, 100, 120, 15, MY_MAGENTA);
		pantalla.drawString("RAMPA", 230, 100, FONT2);
		pantalla.drawString("TEMP. INICIAL:", 30, 120, FONT2);
		pantalla.drawString("TEMP. FINAL:", 30, 140, FONT2);
		pantalla.drawLine(83,160,85,157, MY_BLACK);
		pantalla.drawString("AGITACION:", 30, 160, FONT2);
		pantalla.drawString("TIEMPO:", 30, 180, FONT2);
		if(setpoint_temperatura_2 <= 0) {
			pantalla.fillRect(115, 140, 105, 15, MY_YELLOW);
			pantalla.drawString("SIN CONFIGURAR", 115, 140, FONT2);
		} else {
			if(setpoint_temperatura_2 <= setpoint_temperatura_1 || setpoint_temperatura_2 > 300) {
				pantalla.fillRect(115, 140, 70, 15, MY_YELLOW);
			}
			pantalla.drawString((String)(setpoint_temperatura_2), 115, 140, FONT2);
			pantalla.drawCircle(145, 142, 2, MY_BLACK);
			pantalla.drawString("C", 150, 140, FONT2);
		}

		posy_setpoint_agitacion += 20;
		posy_tiempo += 20; 

	} else {
		pantalla.fillRect(190, 100, 120, 15, MY_GREEN);
		pantalla.drawString("CONSTANTE", 210, 100, FONT2);
		pantalla.drawString("TEMPERATURA:", 30, 120, FONT2);
		pantalla.drawLine(83,140,85,137, MY_BLACK);
		pantalla.drawString("AGITACION:", 30, 140, FONT2);
		pantalla.drawString("TIEMPO:", 30, 160, FONT2);
	}

	if(setpoint_temperatura_1 <= 0) {
		if(tipo_de_funcion == 'r') {
			pantalla.drawString("TEMPERATURA AMBIENTE", 130, 120, FONT2);
		} else {
			pantalla.drawString("DESACTIVADO", 130, 120, FONT2);
		}		
	} else {
		if(setpoint_temperatura_1 > 300) {
			pantalla.fillRect(130, 120, 180, 15, MY_YELLOW);
		}
		pantalla.drawString((String)(setpoint_temperatura_1), 130, 120, FONT2);
		pantalla.drawCircle(160, 122, 2, MY_BLACK);
		pantalla.drawString("C", 165, 120, FONT2);
		pantalla.drawString("TEMP.MAX=300  C", 185, 120, FONT2);
		pantalla.drawCircle(289, 122, 2, MY_BLACK);
	}

	if(setpoint_agitacion <= 0) {
			pantalla.drawString("DESACTIVADO", 100, posy_setpoint_agitacion, FONT2);
	} else {
		if(setpoint_agitacion > 1200) {
			pantalla.fillRect(100, posy_setpoint_agitacion, 210, 15, MY_YELLOW);
		}
		pantalla.drawString((String)(setpoint_agitacion), 100, posy_setpoint_agitacion, FONT2);
		pantalla.drawString("RPM", 140, posy_setpoint_agitacion, FONT2);
		pantalla.drawString("VEL.MAX=1200 RPM", 180, posy_setpoint_agitacion, FONT2);
	}

	if(minutos_para_mantener_setpoints <= 0) {
		pantalla.fillRect(80, posy_tiempo, 100, 15, MY_YELLOW);
		pantalla.drawString("SIN CONFIGURAR", 80, posy_tiempo, FONT2);
	} else {
		pantalla.drawString((String)(minutos_para_mantener_setpoints) + " " + "MINUTOS", 80, posy_tiempo, FONT2);
	}
}


void coloca_valor_de_temperatura_en_la_opcion_establecer_primer_setpoint_de_temperatura(const String temperatura, const char funcion_de_temperatura)
{
	pantalla.setFreeFont(TT1);
	pantalla.fillRect(130, 120, 180, 15, MY_WHITE);
	if(temperatura.toInt() <= 0) {
		if(funcion_de_temperatura == 'r') {
			pantalla.drawString("TEMPERATURA AMBIENTE", 130, 120, FONT2);
		} else {
			pantalla.drawString("DESACTIVADO", 130, 120, FONT2);
		}
		
	} else {
		if(temperatura.toInt() > 300) {
			pantalla.fillRect(130, 120, 180, 15, MY_YELLOW);
		}
		pantalla.drawString((String)(temperatura.toInt()), 130, 120, FONT2);
		pantalla.drawCircle(160, 122, 2, MY_BLACK);
		pantalla.drawString("C", 165, 120, FONT2);
		pantalla.drawString("TEMP.MAX=300  C", 190, 120, FONT2);
		pantalla.drawCircle(289, 122, 2, MY_BLACK);
	}
	
}

void coloca_valor_de_temperatura_en_la_opcion_establecer_segundo_setpoint_de_temperatura(const String segunda_temperatura, const uint16_t primera_temperatura)
{
	pantalla.setFreeFont(TT1);
	pantalla.fillRect(115, 140, 180, 15, MY_WHITE);
	if(segunda_temperatura.toInt() <= 0) {
		pantalla.fillRect(115, 140, 105, 15, MY_YELLOW);
		pantalla.drawString("SIN CONFIGURAR", 115, 140, FONT2);
	} else {
		if(segunda_temperatura.toInt() > 300 || segunda_temperatura.toInt() <= primera_temperatura) {
			pantalla.fillRect(115, 140, 105, 15, MY_YELLOW);
		}
		pantalla.drawString((String)(segunda_temperatura.toInt()), 115, 140, FONT2);
		pantalla.drawCircle(145, 142, 2, MY_BLACK);
		pantalla.drawString("C", 150, 140, FONT2);
	}
}



void coloca_valor_de_agitacion_en_la_opcion_establecer_setpoint_de_agitacion(const String agitacion, const char funcion_de_temperatura)
{
	pantalla.setFreeFont(TT1);
	
	uint8_t posy_agitacion = 140;
	
	if(funcion_de_temperatura == 'r') {
		posy_agitacion += 20;
	}

	pantalla.fillRect(100, posy_agitacion, 210, 15, MY_WHITE);

	if(agitacion.toInt() <= 0) {
		pantalla.drawString("DESACTIVADO", 100, posy_agitacion, FONT2);
	} else {
		if(agitacion.toInt() > 1200) {
			pantalla.fillRect(100, posy_agitacion, 210, 15, MY_YELLOW);
		}
		pantalla.drawString((String)(agitacion.toInt()), 100, posy_agitacion, FONT2);
		pantalla.drawString("RPM", 140, posy_agitacion, FONT2);
		pantalla.drawString("VEL.MAX=1200 RPM", 180, posy_agitacion, FONT2);
	}
}

void coloca_valor_de_tiempo_en_la_opcion_establecer_minutos_para_mantener_setpoints(const String tiempo, const char funcion_de_temperatura)
{
	pantalla.setFreeFont(TT1);
	
	uint8_t posy_tiempo = 160;
	
	if(funcion_de_temperatura == 'r') {
		posy_tiempo += 20;
	}

	pantalla.fillRect(80, posy_tiempo, 210, 15, MY_WHITE);

	if(tiempo.toInt() <= 0) {
		pantalla.fillRect(80, posy_tiempo, 100, 15, MY_YELLOW);
		pantalla.drawString("SIN CONFIGURAR", 80, posy_tiempo, FONT2);
	} else {
		pantalla.drawString((String)(tiempo.toInt()) + " " + "MINUTOS", 80, posy_tiempo, FONT2);
	}
}

void colocar_elementos_de_fondo_del_menu_agregar_o_confirmar_rutinas_configuradas()
{
	uint32_t x1_1 = 213,y1_1 = 222, x2_1 = 223, y2_1 = 222, x3_1 = 218, y3_1 = 232;
	pantalla.fillRect(10, 100, 300, 80, MY_WHITE);
	pantalla.fillRect(0, 205, 320, 40, MY_SKYBLUE);
	pantalla.setFreeFont(FMB9);
	pantalla.drawString("A:ELEGIR", 10, 205);
	pantalla.drawString("B:REGRESAR", 10, 220);
	pantalla.drawString("D:", 190, 220);
	pantalla.fillTriangle(x1_1, y1_1, x2_1, y2_1, x3_1, y3_1, MY_BLACK);
}

void resalta_opcion_en_posicion_actual_del_menu_agregar_o_confirmar_rutinas_configuradas(const uint8_t opcion)
{
	if(opcion == 0) {
		pantalla.fillRect(10, 100, 300, 20, MY_YELLOW);
		pantalla.fillRect(10, 130, 300, 40, MY_WHITE);
		pantalla.fillRect(10, 180, 300, 20, MY_WHITE);
	} else if(opcion == 1) {
		pantalla.fillRect(10, 100, 300, 20, MY_WHITE);
		pantalla.fillRect(10, 130, 300, 40, MY_YELLOW);
		pantalla.fillRect(10, 180, 270, 20, MY_WHITE);
	} else if(opcion == 2) {
		pantalla.fillRect(10, 100, 300, 20, MY_WHITE);
		pantalla.fillRect(10, 130, 300, 40, MY_WHITE);
		pantalla.fillRect(10, 180, 300, 20, MY_YELLOW);
	}
	pantalla.setFreeFont(FMB9);
	pantalla.drawString("AGREGAR RUTINA", 80, 100);
	pantalla.drawString("CONFIRMAR Y ENVIAR RUTINAS", 10, 130);
	pantalla.drawString("CONFIGURADAS", 90, 150);
	pantalla.drawString("ELIMINAR RUTINA", 80, 180);
}
void colocar_elementos_de_fondo_en_el_menu_confirmar_y_enviar_rutinas_configuradas()
{
	pantalla.fillScreen(MY_SKYBLUE);
	mostrar_imagen_multiparrilla();
	pantalla.setFreeFont(FMB9);
	pantalla.setTextColor(MY_BLACK);
	//pantalla.drawString("A:ELEGIR", 10, 205);
	pantalla.drawString("B:REGRESAR", 10, 205);
	pantalla.drawString("C:CONTINUAR", 190, 205);
	//pantalla.drawString("D:", 190, 220);
}

void muestra_plazas_activadas_y_sensor_configurado(bool *plazas_activadas, const uint8_t cantidad_de_plazas, const bool sensor_infrarrojo, const uint8_t numero_de_rutinas_configuradas)
{
	uint32_t posX = 17, color;
	pantalla.setFreeFont(FF47);
	String plazas_activadas_texto = "", sensor;
	for(uint8_t i = 0; i < cantidad_de_plazas; ++i, posX+=50) {
		if(plazas_activadas[i]) {
			color = MY_GREEN;
			plazas_activadas_texto += (String)(i + 1) + ", ";
		} else {
			color = MY_SILVER;
		}
		pantalla.fillRect(posX, 3, 36, 36, color);
		pantalla.drawString((String)(i + 1),posX + 7, 6);
	}
	plazas_activadas_texto = plazas_activadas_texto.substring(0, plazas_activadas_texto.length() - 2);
	pantalla.setFreeFont(TT1);
	pantalla.fillRect(65, 80, 170, 20, MY_SKYBLUE);
	pantalla.fillRect(10, 100, 300, 100, MY_WHITE);
	pantalla.drawString("PLAZAS ACTIVADAS: " + plazas_activadas_texto, 10, 100, FONT2);
	if(sensor_infrarrojo) {
		sensor = "INFRARROJO";
	} else {
		sensor = "TERMOPAR";
	}
	pantalla.drawString("SENSOR CONFIGURADO: " + sensor, 10, 120, FONT2);
	pantalla.drawString("NO. DE RUTINAS CONFIGURADAS: " + (String)(numero_de_rutinas_configuradas + 1), 10, 140, FONT2);
}

void muestra_configuracion_de_la_rutina(const uint8_t numero_de_rutina, const uint8_t numero_de_rutinas_configuradas, const char funcion_de_temp, const uint16_t primer_setpoint_temp, const uint16_t segundo_setpoint_temp, const uint16_t agitacion, const uint32_t tiempo)
{
	String funcion;
	uint8_t espacio = 0;
	pantalla.fillRect(65, 80, 170, 20, MY_WHITE);
	pantalla.fillRect(10, 100, 300, 100, MY_WHITE);
	pantalla.setFreeFont(TT1);
	pantalla.drawString("NO. DE RUTINA: " + (String)(numero_de_rutina) + " DE " + (String)(numero_de_rutinas_configuradas), 70, 80, FONT2);
	if(funcion_de_temp == 'r'){
		funcion = "RAMPA";
		if(primer_setpoint_temp == 0) {
			pantalla.drawString("TEMP. INICIAL: TEMPERATURA AMBIENTE", 10, 120, FONT2);
		} else {
			pantalla.drawString("TEMP. INICIAL: " + (String)(primer_setpoint_temp), 10, 120, FONT2);
			pantalla.drawCircle(140, 122, 2, MY_BLACK);
			pantalla.drawString("C", 145, 120, FONT2);
		}
		pantalla.drawString("TEMP. FINAL: " + (String)(segundo_setpoint_temp), 10, 140, FONT2);
		pantalla.drawCircle(125, 142, 2, MY_BLACK);
		pantalla.drawString("C", 130, 140, FONT2);
		espacio += 20;
	} else {
		funcion= "CONSTANTE";
		if(primer_setpoint_temp == 0) {
			pantalla.drawString("TEMPERATURA: DESACTIVADO", 10, 120, FONT2);
		} else {
			pantalla.drawString("TEMPERATURA: " + (String)(primer_setpoint_temp), 10, 120, FONT2);
			pantalla.drawCircle(140, 122, 2, MY_BLACK);
			pantalla.drawString("C", 145, 120, FONT2);
		}
	}

	if(agitacion == 0) {
		pantalla.drawString("AGITACION: DESACTIVADA", 10, 140 + espacio, FONT2);
	} else {
		pantalla.drawString("AGITACION: " + (String)(agitacion) + " RMP", 10, 140 + espacio, FONT2);
	}
	pantalla.drawLine(63,140 + espacio,65,137 + espacio, MY_BLACK);
	pantalla.drawString("TIEMPO: " + (String)(tiempo) + " MINUTOS",10, 160 + espacio, FONT2);
	pantalla.drawString("FUNC. DE TEMPERATURA: " + funcion, 10, 100, FONT2);
	
	pantalla.fillRect(190, 205, 130, 50, MY_SKYBLUE);
	pantalla.setFreeFont(FMB9);
	if(numero_de_rutina >= numero_de_rutinas_configuradas) {
		pantalla.drawString("C:CONFIRMAR", 190, 205);
		pantalla.drawString("Y ENVIAR", 210, 225);
	} else {
		pantalla.drawString("C:CONTINUAR", 190, 205);
	}
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
	if(conectado) {
		color = MY_GREEN;
		respuesta = "CONECTADO";
		x = 80;
	} else {
		color = MY_RED;
		respuesta = "DESCONECTADO";
		x = 65;
	}
	pantalla.fillRect(50, 35, 230, 120, color);
	pantalla.drawString(respuesta, x, y, font);
}