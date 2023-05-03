#include "Comunicacion_Inalambrica.h"

uint8_t mac_multiparrilla[] = {0x40, 0x91, 0x51, 0xAB , 0x1B, 0xC0};
uint8_t mac_HMI[] = {0x0C, 0xB8, 0x15, 0xC1, 0x9A, 0xD4};

uint8_t num = 33;
bool recibido;
bool mensajeProcesado;

void inicializaComunicacionInalambrica()
{
    WiFi.mode(WIFI_MODE_STA);
    ESPNow.set_mac(mac_HMI);
    WiFi.disconnect();
    ESPNow.init();
    ESPNow.reg_recv_cb(recibirMensaje);
  //  ESPNow.reg_send_cb(mensajeRecibidoPorElReceptor);
    ESPNow.add_peer(mac_multiparrilla);
}

void recibirMensaje(const uint8_t *direccionMac, const uint8_t *mensaje, int longitudMensaje) {
   //////////////////////////////////////////////////////////
}



void enviarMensaje()
{
    recibido = false;
    uint8_t a[] = {'C','a', 'r','a','c','t','e','r',':',' ', (char)num};
    ESPNow.send_message(mac_multiparrilla, a, sizeof(a));
    mensajeProcesado = false;
    for(int i = 0; i < sizeof(a); ++i)
        Serial.printf("%c",a[i]);
    Serial.print("  ");Serial.println(num);
    num++;
    if(num > 126)
        num = 33;

}
/*
void mensajeRecibidoPorElReceptor(const uint8_t *mac_addr, esp_now_send_status_t status) {
  Serial.print("\r\nEstatus del último Paquete enviado\t");
  Serial.println(status == ESP_NOW_SEND_SUCCESS ? "Delivery Success" : "Delivery Fail");
  recibido = true;
}*/

bool obtenerEstadoDelEnlace()
{
    recibido = false;
    enviarMensaje();
    espera(30);
    esp_now_register_send_cb([](const uint8_t* mac, esp_now_send_status_t status) {
        status == ESP_NOW_SEND_SUCCESS ? recibido = true : recibido = false;
        Serial.println(status == ESP_NOW_SEND_SUCCESS ? "Delivery Success" : "Delivery Fail");
    });
    Serial.print("Recibido "); Serial.println(recibido);
    return recibido;
}


void espera(uint16_t tiempoDeEsperaEnMilisegundos)
{
    unsigned long tiempoDeInicio = millis();
    while(millis() - tiempoDeInicio <= tiempoDeEsperaEnMilisegundos){
        continue;
    }
}