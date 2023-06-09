#include "ComunicacionConMultiparrilla.h"

uint8_t mac_multiparrilla[] = {0x40, 0x91, 0x51, 0xAB , 0x1B, 0xC0};
uint8_t mac_HMI[] = {0x0C, 0xB8, 0x15, 0xC1, 0x9A, 0xD4};

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

void recibir_mensaje(const uint8_t *direccion_mac, const uint8_t *mensaje, int longitud_del_mensaje) {
   //////////////////////////////////////////////////////////
}



void enviar_mensaje_de_prueba()
{
    uint32_t mensaje = 12022001;
    ESPNow.send_message(mac_multiparrilla, reinterpret_cast<uint8_t*>(&mensaje), sizeof(mensaje));
    Serial.print("Mensaje de prueba: ");Serial.println(mensaje);
}

bool enviar_rutinas(Multiparrilla mensaje_rutina)
{
    Serial.print("Sensor infrarrojo: ");
    if(mensaje_rutina.sensor_infrarrojo) {
        Serial.println("Ingrarrojo");
    } else {
        Serial.println("Termopares");
    }
    Serial.println("Plazas_activadas:");
    for(uint8_t i = 0; i < CANTIDAD_DE_PLAZAS; ++i) {
        Serial.print(i+1);Serial.print(": ");Serial.println(mensaje_rutina.plazas_activadas[i]);
    }

    Serial.print("Rutinas configuradas: "); Serial.println(mensaje_rutina.numero_de_rutinas_configuradas);

    Serial.println(" ");
    Serial.println("Setpoints de temperatura:");
    for(uint8_t i = 0; i < CANTIDAD_MAXIMA_DE_RUTINAS; ++i) {
        if(mensaje_rutina.setpoints_temperatura[i * 2] == 0) {
            Serial.print("Desactivado");
        } else {
            Serial.print(mensaje_rutina.setpoints_temperatura[i]);
        }
        Serial.print("  ");
        if(mensaje_rutina.setpoints_temperatura[i * 2 + 1] == 0) {
            Serial.println("Desactivado");
        } else {
            Serial.println(mensaje_rutina.setpoints_temperatura[i * 2 + 1]);
        }
        
    }

    Serial.println(" ");
    Serial.println("Funciones de temperatura:");
    for(uint8_t i = 0; i < CANTIDAD_MAXIMA_DE_RUTINAS; ++i) {
        Serial.println(mensaje_rutina.tipo_de_funcion_de_temperatura[i]);
    }

    Serial.println(" ");
    Serial.println("Setpoints de agitación");
    for(uint8_t i = 0; i < CANTIDAD_MAXIMA_DE_RUTINAS; ++i) {
        Serial.println(mensaje_rutina.setpoints_agitacion[i]);
    }

    Serial.println(" ");
    Serial.println("Minutos para mantener setpoints");
    for(uint8_t i = 0; i < CANTIDAD_MAXIMA_DE_RUTINAS; ++i) {
        Serial.println(mensaje_rutina.minutos_para_mantener_setpoints[i]);
    }
    Serial.println(sizeof(mensaje_rutina));
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