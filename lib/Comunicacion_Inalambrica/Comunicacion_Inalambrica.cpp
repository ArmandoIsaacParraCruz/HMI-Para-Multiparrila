#include "Comunicacion_Inalambrica.h"

uint8_t esclavo_mac[] = {0x40, 0x91, 0x51, 0xAB , 0x1B, 0xC0};

uint8_t num;

void iniComunicacionInalambrica()
{
    WiFi.mode(WIFI_MODE_STA);
    WiFi.disconnect();
    ESPNow.init();
    ESPNow.add_peer(esclavo_mac);
}

void enviarMensaje()
{
    uint8_t a[] = {'C','a', 'r','a','c','t','e','r',':',' ', (char)num};
    ESPNow.send_message(esclavo_mac, a, sizeof(a));
    for(int i = 0; i < sizeof(a); ++i)
        Serial.printf("%c",a[i]);
    Serial.print("  ");Serial.println(num);
    num++;
    if(num > 126)
        num = 33;
}

bool obtenerEstadoDelEnlace()
{
 //   if(esp_now_is_peer_exist(esclavo_mac))
        return true;
 //   else
 //       return false;
}
