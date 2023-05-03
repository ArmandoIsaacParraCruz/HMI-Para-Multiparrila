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

  //SE DESPLIEGAN LOS CONTROLES PARA MOVERSE DENTRO DEL MENÚ
  uint32_t x1_1 = 15,y1_1 = 230, x2_1 = 25, y2_1 = 230, x3_1 = 20, y3_1 = 220,
           x1_2 = 115,y1_2 = 220, x2_2 = 125, y2_2 = 220, x3_2 = 120, y3_2 = 230;
  pantalla.fillTriangle(x1_1, y1_1, x2_1, y2_1, x3_1, y3_1, MY_BLACK);
  pantalla.fillTriangle(x1_2, y1_2, x2_2, y2_2, x3_2, y3_2, MY_BLACK);
  pantalla.setFreeFont(FMB9);
  pantalla.setTextColor(MY_BLACK);
  pantalla.drawString(":C", x1_1 + separacion, y3_1);
  pantalla.drawString(":D", x1_2 + separacion, y1_2);
  pantalla.drawString("ELEGIR:A", x1_2 + 10*separacion, y1_2);

}

void resaltaOpcionMenuPrincipal(uint8_t opcion)
{
  uint32_t posX = 50,posY = 15, ancho = 230, alto = 50, separacion = 0, color;

  for(uint8_t i = 1; i <= 3; ++i, separacion += 70){
    if(i == opcion){
      color = MY_YELLOW;
    }else{
      color = MY_WHITE;
    }
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