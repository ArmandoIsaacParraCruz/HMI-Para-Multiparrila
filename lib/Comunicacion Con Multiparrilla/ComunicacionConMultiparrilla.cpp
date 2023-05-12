#include "ComunicacionConMultiparrilla.h"

uint8_t mac_multiparrilla[] = {0x40, 0x91, 0x51, 0xAB , 0x1B, 0xC0};
uint8_t mac_HMI[] = {0x0C, 0xB8, 0x15, 0xC1, 0x9A, 0xD4};


uint8_t num = 33;
bool mensaje_recibido_por_la_multiparrilla;

void inicializar_comunicacion_con_multiparrilla()
{
    WiFi.mode(WIFI_MODE_STA);
    ESPNow.set_mac(mac_HMI);
    WiFi.disconnect();
    ESPNow.init();
    ESPNow.reg_recv_cb(recibir_mensaje);
    ESPNow.add_peer(mac_multiparrilla);
}

void recibir_mensaje(const uint8_t *direccionMac, const uint8_t *mensaje, int longitudMensaje) {
   //////////////////////////////////////////////////////////
}



void enviar_mensaje_de_prueba()
{
    uint8_t a[] = {'C','a', 'r','a','c','t','e','r',':',' ', (char)num};
    ESPNow.send_message(mac_multiparrilla, a, sizeof(a));
    for(int i = 0; i < sizeof(a); ++i)
        Serial.printf("%c",a[i]);
    Serial.print("  ");Serial.println(num);
    num++;
    if(num > 126)
        num = 33;

}

bool enviar_rutinas(Multiparrilla mensaje_rutina)
{
    ESPNow.send_message(mac_multiparrilla, reinterpret_cast<uint8_t*>(&mensaje_rutina), sizeof(mensaje_rutina));

    return false;
}


bool obtener_estado_del_enlace()
{
    mensaje_recibido_por_la_multiparrilla = false;
    enviar_mensaje_de_prueba();
    esperar(30);
    esp_now_register_send_cb([](const uint8_t* mac, esp_now_send_status_t status) {
        status == ESP_NOW_SEND_SUCCESS ? mensaje_recibido_por_la_multiparrilla = true : mensaje_recibido_por_la_multiparrilla = false;
        //Serial.println(status == ESP_NOW_SEND_SUCCESS ? "Entrega exitosa" : "Entrega fallida");
    });
    return mensaje_recibido_por_la_multiparrilla;
}


void esperar(uint16_t tiempo_de_espera_en_milisegundos)
{
    unsigned long tiempo_de_inicio = millis();
    unsigned long tiempo_actual = millis();
    while(tiempo_actual - tiempo_de_inicio <= tiempo_de_espera_en_milisegundos){
        tiempo_actual = millis();
    }
}